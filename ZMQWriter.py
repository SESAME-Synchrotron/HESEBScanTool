import sys
import zmq
import h5py
import time
import log
from epics import PV

from H5Writer import H5Writer
from SEDSS.CLIMessage import CLIMessage

#####################
# Global variables
####################

GfullH5Path = None 	# Global(G) full h5 path

class ZMQWriter(H5Writer):
	def __init__(self, fName, fPath, configFile, ROIs, wMode="w"):
		super().__init__(fName, fPath, configFile, wMode)

		global GfullH5Path
		GfullH5Path = self.fPath + "/" + self.fName

		self.startTime = time.time()
		self.ZMQRType = zmq.SUB

		self.prefix = "HESEB:"
		self.PVs = self.configFile["writerPVs"]
		self.totalPointsPV = PV(self.prefix + self.PVs[self.PVs.index("TotalPoints")])
		self.missedPointsPV = PV(self.prefix + self.PVs[self.PVs.index("MissedPoints")])
		self.receivedPointsPV = PV(self.prefix + self.PVs[self.PVs.index("ReceivedPoints")])
		self.numChannels = PV(self.configFile["EPICSandIOCs"]["xFlashNumChannels"]).get()
		self.selectedROIs = {}
		for ROI in ROIs:
			self.selectedROIs[str(ROI)] = PV(self.configFile["EPICSandIOCs"]["xFlashNetValue"].replace("0", str(ROI)))
		
		self.labelROIs = {}
		for ROI in ROIs:
			self.labelROIs[str(ROI)] = PV(self.configFile["EPICSandIOCs"]["xFlashLabel"].replace("0", str(ROI))).get()
		"""
		Get ZMQ Sender settings from beamline configurations file
		Notes:
				1. ZMQSXXX: ZMQ Sender
				2. ZMQRXXX: ZMQ Receiver
		"""
		try:
			self.ZMQSettings  = self.configFile["ZMQSettings"]
			self.ZMQSType     = self.ZMQSettings["ZMQSenderSettings"]["ZMQType"]
			self.ZMQSender    = self.ZMQSettings["ZMQSenderSettings"]["ZMQSender"]
			self.ZMQSPort     = self.ZMQSettings["ZMQSenderSettings"]["ZMQPort"]
			self.ZMQSProtocol = self.ZMQSettings["ZMQSenderSettings"]["ZMQProtocol"]
			# put sender in its format i.e. "tcp://127.0.0.1:1559"
			self.ZMQSender = self.ZMQSProtocol + "://" + self.ZMQSender + ":" + self.ZMQSPort
		except:
			log.error("Problem reading the beamline configurations file")
			raise AttributeError

		CLIMessage("ZMQ type is PUB (Publisher)", "I")
		log.info("Creating ZMQ context and socket")
		self.context = zmq.Context()
		self.sock = self.context.socket(self.ZMQRType)
		self.sock.setsockopt_string(zmq.SUBSCRIBE, "")
		self.sock.bind(self.ZMQSender)

	def createDefaultDatasets(self, numPointsX, numPointsY):
		"""
		This method is used to create datasets that are associated with the indexes and positions of points to
		be collected.
		i.e. IndexX, PositionY, ..
		"""
		CLIMessage("Default datasets creation", "I")
		log.info("Start creating default datasets")
		defaultDatasets = self.configFile["defaultDatasets"]

		for dataset in defaultDatasets:

			# create datasets
			datasetOnH5 = self.h5File.create_dataset(defaultDatasets[dataset]["dataset"],
			dtype=defaultDatasets[dataset]["dtype"], shape=len(numPointsX) * len(numPointsY), chunks=True)      # create a 1 dimension dataset based on total scanning points

			# add attributes to the created dataset
			for att in defaultDatasets[dataset]["attributes"]:
				datasetOnH5.attrs[att] = defaultDatasets[dataset]["attributes"][att]

		log.info("Default datasets creation is done")

	def createRawDatasets(self, numPointsX, numPointsY, ROIs, detectors):
		"""
		This method is used to create datasets that are associated with the detector of points to
		be collected.
		i.e. Pixel, ..
		"""
		CLIMessage("Raw datasets creation", "I")
		log.info("Start creating raw datasets")
		dataset = self.configFile["rawDatasets"]["ROI_0"]

		dt = h5py.string_dtype(encoding='ascii')
		_dtype = dt # default if no dtype found

		for ROI in ROIs:
			if dataset["valueType"] == "EPICSPV":

				_data, _dataType = self.getPVValueType(dataset["value"].replace("0", str(ROI)))

				if _dataType in {"int","time_int", "ctrl_int", "short",
				"time_short","ctrl_short", "enum","time_enum", "ctrl_enum",
				"long","time_long", "ctrl_long"}: # _AN: These data types need to be validated
					_dtype = h5py.h5t.NATIVE_INT32
				elif _dataType in {"double", "time_double", "ctrl_double", "float",
				"time_float", "ctrl_float"}:
					_dtype = "double"
				elif _dataType in {"char", "time_char", "ctrl_char", "time_string"}:
					_dtype = dt

				# create datasets
				datasetOnH5 = self.h5File.create_dataset(f'{dataset["dataset"].replace("0", str(ROI))}_{self.labelROIs[str(ROI)]}',
				dtype=_dtype, shape=(len(numPointsY), len(numPointsX)), chunks=True)        # create a 2D dataset based on rows*cols >> y*x

				# add attributes to the created dataset
				for att in dataset["attributes"]:
					datasetOnH5.attrs[att]=dataset["attributes"][att].replace("0", str(ROI))

		# create transmission datasets
		availableDetectors = ['KEITHLEY_I0', 'KEITHLEY_Itrans']
		for det in detectors:
			if det in availableDetectors:
				dataset = self.configFile["transmissionDatasets"][det]

				_data, _dataType = self.getPVValueType(dataset["value"])
				if _dataType in {"int","time_int", "ctrl_int", "short",
				"time_short","ctrl_short", "enum","time_enum", "ctrl_enum",
				"long","time_long", "ctrl_long"}: # _AN: These data types need to be validated
					_dtype = h5py.h5t.NATIVE_INT32
				elif _dataType in {"double", "time_double", "ctrl_double", "float",
				"time_float", "ctrl_float"}:
					_dtype = "double"
				elif _dataType in {"char", "time_char", "ctrl_char", "time_string"}:
					_dtype = dt

				# create datasets
				datasetOnH5 = self.h5File.create_dataset(dataset["dataset"].split("_")[-1],
				dtype=_dtype,  shape=len(numPointsX) * len(numPointsY), chunks=True)        # create a 1 dimension dataset based on total scanning points

				# add attributes to the created dataset
				for att in dataset["attributes"]:
					datasetOnH5.attrs[att]=dataset["attributes"][att]

		log.info("Raw datasets creation is done")

	def receiveData(self, numPointsX, numPointsY, ROIs, scanTopo = "seq", arrayIndexX = None, arrayIndexY=None):
		"""
			Prepare the data sets to be ready to collect data points
		"""
		self.numXPoints = len(numPointsX)
		self.numYPoints = len(numPointsY)
		self.arrayXPositions = numPointsX
		self.arrayYPositions = numPointsY
		self.arrayXIndex = arrayIndexX
		self.arrayYIndex = arrayIndexY
		self.scanTopo = scanTopo

		self.totalPointsPV.put(self.numXPoints * self.numYPoints, wait=True)
		CLIMessage(f"Ready to collect {self.numXPoints * self.numYPoints} points", "I")

		self.h5file = h5py.File(GfullH5Path, 'a')  # Reopen in append mode
		self.data 		= "/exchange/xmap/data"
		self.indexX 	= "/defaults/IndexX"
		self.indexY 	= "/defaults/IndexY"
		self.positionX 	= "/defaults/PositionX"
		self.positionY 	= "/defaults/PositionY"
		self.pixel      = "/exchange/xmap/ROI_0"
		self.I0         = "/exchange/xmap/I0"
		try:
			self.It         = "/exchange/xmap/It"
		except:
			pass

		self.h5file[self.data].resize(self.numXPoints, axis=1)      # resize X axis from 1 to X points
		self.h5file[self.data].resize(self.numYPoints, axis=0)      # resize Y axis from 1 to Y points

		self.missedPoints = []          # array to store missed points
		self.totalPoints = 0            # attr to store the points

		if self.scanTopo.lower()[0:3] == "seq":
			for y in range(0,self.numYPoints):
				for x in range(0,self.numXPoints):
					self.writingData(x, y, ROIs)
		else:
			for point in zip(self.arrayXIndex, self.arrayYIndex):
				x, y = point
				self.writingData(x, y, ROIs)

		self.h5file.close()
		CLIMessage(f"total received points: {self.totalPoints - len(self.missedPoints)} out of {self.numXPoints * self.numYPoints} | "
				   f"missed points index: {'No missed points' if len(self.missedPoints) == 0 else self.missedPoints}", "I")
		log.info(f"total received points: {self.totalPoints - len(self.missedPoints)} out of {self.numXPoints * self.numYPoints} | "
				   f"missed points index: {'No missed points' if len(self.missedPoints) == 0 else self.missedPoints}")

	def writingData(self, x, y, ROIs):
		"""
			writing the received data in the datasets, if the data not received >> the value in the index dataset will be 0
		"""
		self.totalPoints +=1            # increase the received points each time (for each point)
		expData = self.sock.recv_pyobj()   # waiting until receive data

		if expData == "timeout":
			self.h5file[self.data][y, x, :] = 0
			for ROI in ROIs:
				self.h5file[f'{self.pixel.replace("0", str(ROI))}_{self.labelROIs[str(ROI)]}'][y,x] = 0
			self.missedPoints.append((x, y))
			self.missedPointsPV.put(len(self.missedPoints), wait=True)
			log.error(f"missed point index ({x, y})")
			CLIMessage(f"missed point index ({x, y})", "W")
		elif expData == "scanAborted":
			CLIMessage(f"scan has been aborted >>> received points: {self.totalPoints - len(self.missedPoints)} out of {self.numXPoints * self.numYPoints}", "E")
			log.info(f"scan has been aborted >>> received points: {self.totalPoints - len(self.missedPoints)} out of {self.numXPoints * self.numYPoints}")
			self.h5File.close()
		else:
			self.receivedPointsPV.put(self.totalPoints, wait=True)
			self.h5file[self.data][y, x, :] = list(expData["XFLASH-MCA1"][:self.numChannels])
			for ROI in ROIs:
				name = f'{self.pixel.replace("0", str(ROI))}_{self.labelROIs[str(ROI)]}'
				data = self.selectedROIs[str(ROI)].get(timeout=self.PVTimeout, use_monitor=False)
				try:
					self.h5file[name][y,x] = data / expData["KEITHLEY_I0"]
				except:
					self.h5file[name][y,x] = data
			CLIMessage(f"Total Points: {self.numXPoints * self.numYPoints} | "
						f"current point index: {x, y} | "
						f"current point position: {self.arrayXPositions[x], self.arrayYPositions[y]} | "
						f"collected points: {self.totalPoints} | "
						f"missed points: {'0' if len(self.missedPoints) == 0 else self.missedPoints} | "
						f"remaining points: {self.numXPoints * self.numYPoints - self.totalPoints}", "I")
			log.info(f"Total Points: {self.numXPoints * self.numYPoints} | "
						f"current point index: {x, y} | "
						f"current point position: {self.arrayXPositions[x], self.arrayYPositions[y]} | "
						f"collected points: {self.totalPoints} | "
						f"missed points: {'0' if len(self.missedPoints) == 0 else self.missedPoints} | "
						f"remaining points: {self.numXPoints * self.numYPoints - self.totalPoints}")

		self.h5file[self.indexX][self.totalPoints-1] = x
		self.h5file[self.indexY][self.totalPoints-1] = y
		self.h5file[self.positionX][self.totalPoints-1] = self.arrayXPositions[x]
		self.h5file[self.positionY][self.totalPoints-1] = self.arrayYPositions[y]
		self.h5file[self.I0][self.totalPoints-1] = expData["KEITHLEY_I0"]
		try:
			self.h5file[self.It][self.totalPoints-1] = expData["KEITHLEY_Itrans"]
		except:
			pass