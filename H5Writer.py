import sys
import time
import datetime
import h5py
import log
from epics import PV
import xml.etree.ElementTree as ET

from SEDWriter import SEDWriter
from SEDSS.CLIMessage import CLIMessage
from SEDSS.SEDSupport import readFile

class H5Writer (SEDWriter):
	def __init__(self, fName, fPath, configFile, wMode="w"):
		super().__init__(fName, fPath)

		"""
		This class is being used to create h5 files and setup the dxFile format.
		dxFile format is bing applied by reading 2 XML files:
		- Layout file
		- Attribute file

		The path of the two files are already provided by reading the writer/beamline
		configurations file i.e. (BEATS.json)
		"""

		""" read writer/beamline JSON configurations file to exact paths and other parameters """
		log.info("Reading Writer configuration file: {}".format(configFile))
		try:
			self.configFile = readFile(configFile).readJSON()

			self.fFormat = self.configFile["fileFormat"]
			self.XMLH5LayoutFile = self.configFile["formatSettings"]["layout"]
			log.info("Reading XML dxFile layout file: {}".format(self.XMLH5LayoutFile))

			self.XMLH5AttFile = self.configFile["formatSettings"]["attribute"]
			log.info("Reading XML dxFile attribute file: {}".format(self.XMLH5AttFile))

			# if statement is being used here for the future (for other beamlines),
			self.creator = self.configFile["fileCreator"]
			# self.beamline = self.configFile["beamline"]
			# self.detector = self.configFile["detector"]
			# self.fType = self.configFile["fileType"]

			# hdf5 file may not contain fixed attributes
			self.writerFileReady = self.configFile["EPICSandIOCs"]["writerFileReady"]
			if "hdf5FixedAtt" in self.configFile:
				self.hdf5FixedAtts = self.configFile["hdf5FixedAtt"]
			self.PVTimeout = self.configFile["EPICSandIOCs"]["EPICSPVTimeout"]
		except:
			CLIMessage("Problem reading the beamline configurations file", "E")
			log.error("Problem reading writer configurations file: {}".format(configFile))
			raise AttributeError

		self.fName = fName + ".h5" # H5 file name
		self.wMode = wMode

		"""
		DX file format:
		The writer accepts dx, DX, Dx and dX
		"""

		if self.fFormat.lower() == "dx" and self.wMode.lower() == "w":
			CLIMessage("hdf5 with dx file format will be created", "I")
		elif self.fFormat.lower() == "nx":
			CLIMessage("nx file format is not yet implemented, please use dx file format instead", "W") # nx will be added later when it is needed
			sys.exit()
		else:
			log.error("HDF5 file creation | Unsupported/Wrong file format has been chosen")
			sys.exit()

	def createH5File (self):
		"""
		A method to create hdf5 files in standard way
		"""

		try:
			log.info("Creating hdf5 (H5) file")
			self.h5File = h5py.File(self.fPath + "/" + self.fName, self.wMode.lower())

			# adding h5 attributes to the created file
			self.h5File.attrs["filename"] = self.fName
			log.info("H5 file name: {}".format(self.fName))

			self.h5File.attrs["file_time"] = str(datetime.datetime.now())
			log.info("H5 file creation time: {}".format(self.h5File.attrs["file_time"]))

			self.h5File.attrs["file_creator"] = self.creator
			self.h5File.attrs["h5py_version"] = h5py.__version__

			self.h5File.attrs["file_path"] = self.fPath
			log.info("H5 file path: {}".format(self.fPath))
			log.info("{} file has been successfully created".format(self.fName))

		except:
			CLIMessage("hdf5 file creation error | there was a problem creating {} file".format(self.fName), "E")
			log.error("Error creating hdf5 file")
			raise TypeError

	def setupH5DXLayout (self):
		"""
		a method to build Scientific Data Exchange (DXfile) format:
			- Reads the XML layout and attributes files.
			- Creates groups and subgroups
			- Creates datasets
			- Add datasets attributes
		"""

		log.info("Setting up dxFile layout")

		# set some initial variables.
		h5GroupList = [] 	# a list to temporarily store hdf5 groups and sub-groups
		count = 0 			# just a counter to index the list above.
		EPICSPVsAtt = {}

		"""
		onFileCloseDatasets is a dictionary to store hdf5 datasets paths (as a key) and
		their PVs (as a value) to be UPDATED when H5 file is about to close
		"""
		self.onFileCloseDatasets = {}
		dt = h5py.string_dtype(encoding='ascii', length=2000) # default dataset type

		# reads h5 tree elements and retrieve events (start or end of node, tree element)
		for event, elem in ET.iterparse(self.XMLH5LayoutFile, events=('start', 'end')):
			if event == 'start':
				# in XML, anything starts with "<" is a tag i.e. <AAA name="sesame">
				# AAA is the tag, name is attribute.
				if elem.tag == "group":
					h5GroupList.insert(count, elem.attrib.get("name"))
					h5Tree = "" # a temporarily variable to build and restore paths of hdf5 file.
					for i in range (len(h5GroupList)):
						h5Tree = h5Tree + "/" + h5GroupList[i]
					try:
						h5Group = self.h5File.create_group(h5Tree)
					except:
						CLIMessage("hdf5 group creation error | there was a problem creating {} the group / sub-group".format(h5GroupList[i]), "E")
						log.error("Error creating hdf5 group {}".format(h5Tree))
						raise TypeError

				elif elem.tag == "dataset": # if tag is a dataset: analyze it then create it ...
					_data = "NO Data" # default if no data found
					_dtype = dt # default if no dtype found
					_shape = 1 # default shape size

					try:
						if "source" in elem.attrib:

							if elem.attrib.get("source") == "constant":
								_data = elem.attrib.get("value") if elem.attrib.get("value") else "NONE"
								"""
								all the time "type=string" and "shape = 1"
								when source is constant
								"""
								_dtype = dt if elem.attrib.get("type") else dt
								_shape = 1 # default shape for most of the attributes.

								"""
								when the source is "ndattribute", then dataset value, attributes
								and datatype are being imported from attribute xml file.
								"""
							if elem.attrib.get("source") == "ndattribute":
								EPICSPVsAtt=self.datasetAttParsing(elem.attrib.get("ndattribute"))
								for att, value in EPICSPVsAtt.items():
									_data, _dataType = self.getPVValueType(EPICSPVsAtt["source"])
									if _dataType in {"int","time_int", "ctrl_int", "short","time_short",
						  								"ctrl_short", "enum","time_enum", "ctrl_enum", "long","time_long", "ctrl_long"}:
										_dtype = h5py.h5t.NATIVE_INT32
									elif _dataType in {"double", "time_double", "ctrl_double", "float", "time_float", "ctrl_float"}:
										_dtype = h5py.h5t.NATIVE_DOUBLE
									elif _dataType in {"char", "time_char", "ctrl_char", "time_string"}:
										_dtype = h5py.h5t.STR_NULLTERM

									_NDAttrDescription = EPICSPVsAtt["description"]
									_NDAttrName = EPICSPVsAtt["name"]
									_NDAttrSource = EPICSPVsAtt["source"]
									_NDAttrSourceType = "NDAttrSourceEPICSPV"

									"""
									record the datasets that need to be updated
									when the experiment is done
									"""
									if elem.attrib.get("when") == "OnFileClose":
										fullDatasetPath = h5Tree + "/" + elem.attrib.get("name")
										self.onFileCloseDatasets[fullDatasetPath] = EPICSPVsAtt["source"]

							"""
								when the source is "detector", then dataset attributes
								datashape and datatype are being created by reading some PVs.
								--> this step is important to be done here because once the the datatype is
								set it can never be changed
							"""
							if elem.attrib.get("source") == "detector":
								# get dimensions of the frames from the driver to create hdf5 shape
								self.numChannels = PV(self.configFile["EPICSandIOCs"]["xFlashNumChannels"]).get(timeout=self.PVTimeout, use_monitor=False)
								# define and set hdf5 chunks
								_chunks = True

						if elem.attrib.get("source") == "detector":
							dataset = h5Group.create_dataset(elem.attrib.get("name"),
							dtype='uint16', shape=(1, 1, self.numChannels),
							maxshape = (None, None, self.numChannels), chunks=_chunks)
							#compression="gzip")
						else:
							if _dtype == h5py.h5t.STR_NULLTERM:
								_dtype = dt
							dataset = h5Group.create_dataset(elem.attrib.get("name"),data=_data, dtype=_dtype, shape=_shape)

						"""
							getOtherH5Attributes method:
							Get other attributes to be inserted to the hdf5 file
							which are not mentioned in the xml layout file like:
							NDArrayDimBinning, NDArrayDimOffset, NDArrayDimReverse ...
							"""
						fixedAtts=self.getOtherH5Attributes(elem.attrib.get("source"))
						if fixedAtts:
							for att, value in fixedAtts.items():
								if att and value: # to ignore missed keys and/or values i.e. "":"value"
									dataset.attrs.create(att, value, shape=None, dtype=None)
								else:
									CLIMessage("Check the consistency of your beamline configuration file (@ {}:{})".format(att, value), "E")
									log.warning("Check the consistency of your beamline configuration file (@ {}:{})".format(att, value))
						if EPICSPVsAtt: #and defaultAttFlag=="ndattribute":
							dataset.attrs.create("NDAttrDescription", _NDAttrDescription, shape=None, dtype=dt)
							dataset.attrs.create("NDAttrName", _NDAttrName, shape=None, dtype=dt)
							dataset.attrs.create("NDAttrSource", _NDAttrSource, shape=None, dtype=dt)
							dataset.attrs.create("NDAttrSourceEPICSPV", _NDAttrSourceType, shape=None, dtype=dt)
							EPICSPVsAtt = {}

					except:
						CLIMessage("hdf5 dataset creation error | there was a problem creating the dataset {} in this tree path {}".format(elem.attrib.get("name"), h5Tree), "E")
						log.error("Error creating the dataset {} in this path {}".format(elem.attrib.get("name"), h5Tree))
						raise TypeError

				elif elem.tag == "attribute": # Adds the attributes from layout xml file to datasets
					dataset.attrs.create(elem.attrib.get("name"), elem.attrib.get("value"), shape=None, dtype=dt)

			elif event == 'end':
				if elem.text is not None and elem.tail is not None:
					if elem.tag == "group":
						indx = h5GroupList.index(elem.attrib.get("name"))
						del h5GroupList[indx]
			count =  count + 1
		log.info("dxFile format has been applied on the file {}".format(self.fName))

	def getOtherH5Attributes(self, XMLAttribName):
		"""
		A method to collect fixed attributes to be dumped into the hdf5 file.
		any dependent attributes are being imported from the beamline configurations file
		"""

		H5Attributes = {}
		if XMLAttribName == "detector":
			if "detector" in self.hdf5FixedAtts:
				if "EPICSPVs" in self.hdf5FixedAtts["detector"]:
					H5Attributes.update(self.hdf5FixedAtts["detector"]["EPICSPVs"])
				if "fixed" in self.hdf5FixedAtts["detector"]:
					H5Attributes.update(self.hdf5FixedAtts["detector"]["fixed"])

				"""
				create attributes listed in json file their values are concatenated PVs
				"""
				for att, value in H5Attributes.items():
					subValueList = []
					indx = 0
					if type(value) == list:
						for subValue in value:
							PVValue, PVType = self.getPVValueType(subValue)
							subValueList.insert(indx, PVValue)
							indx = indx + 1
						concatenatedValues = "".join(str(subValueList))
						H5Attributes[att] = concatenatedValues
		return H5Attributes

	def datasetAttParsing(self, ndattribute):
		"""
		A method used to parse the attributes of a given dataset from the layout file.
		this method does the following:
		- load the beamline specific attribute file (attribute.xml)
		- search for attribute details for a specific given dataset.
		- returns a dictionary for the values of name, type, source, dbrtype and description.

		"""
		H5Attributes = {}

		for event, elem in ET.iterparse(self.XMLH5AttFile, events=('start', 'end')):
			if event == "start":
				if elem.attrib.get("name") == ndattribute:
					H5Attributes.update({"name":elem.attrib.get("name")})
					H5Attributes.update({"type":elem.attrib.get("type")})
					H5Attributes.update({"source":elem.attrib.get("source")})
					H5Attributes.update({"dbrtype":elem.attrib.get("dbrtype")})
					H5Attributes.update({"description":elem.attrib.get("description")})
		return H5Attributes

	def getPVValueType(self, PVName):
		"""
		Checks whether a given EPICS PV is connected, if so
		returns the EPICS value ...
		"""

		pv = PV(PVName)
		counter = 3 	# wait timeout to happen three times !!!

		while pv.get(timeout=self.PVTimeout, use_monitor=False) is None:
			CLIMessage("Trying to connect to PV {}".format(PVName), "W")
			counter -=1
			if counter == 0:
				PVValue = "NOT Connected PV.."
				PVType = "NOT Connected PV.."
				break
		else:
			PVType = pv.type
			if PVType in {"char","time_char","ctrl_char"}:
				PVValue = pv.get(timeout=self.PVTimeout, use_monitor=False, as_string=True)
			else:
				PVValue = pv.get(timeout=self.PVTimeout, use_monitor=False)

		return PVValue, PVType

	def closeFile(self):
		"""
		This method is being used to add "OnFileClose" data which is mentioned in the layout.xml file
		"""

		CLIMessage("hdf5 file closing ... ", "I")
		log.info("Adding post experiment data | data on file closing")
		self.h5File = h5py.File(self.fPath + "/" + self.fName, "a")

		for datasetPath, PV in self.onFileCloseDatasets.items():
			_data, _dataType = self.getPVValueType(PV)
			if _data == "NOT Connected PV..":
				CLIMessage("Retrying getting data from {} PV... ".format(PV), "I")
				time.sleep(1)
				_data, _dataType = self.getPVValueType(PV)

			try:
				self.h5File[datasetPath][...] = _data
			except:
				try:
					self.h5File[datasetPath][...] = "NOT AVAILABLE DATA"
					log.warning("Could not update value of this dataset --> {} at file closing".format(datasetPath))	# works only with string datatypes
				except:
					log.warning("Could not update value of this dataset --> {} at file closing".format(datasetPath)) 	# works with any other datatypes