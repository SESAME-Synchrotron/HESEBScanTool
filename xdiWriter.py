import epics 
import os
import time
from SEDSS.SEDSupplements import CLIMessage
import fileinput
import sys
from SEDSS.SEDSupport import readFile, dataTransfer, timeModule 

class XDIWriter: 
	"""
	rawData: raw data recevied from the scanning tool
	filePath: file path 
	fileName: file name 
	detChosen: a list contains the detector chosen. 
	expStartTime: Experiment start data and time to be part of the file name 
	cfg: includes experiment configurations
	curentScanInfo: contains information about the current scan (i.e. scan number, interval number)

	"""
	def __init__(self, rawData, filePath, detChosen, expStartTime, expStartTimeDF, cfg, curentScanInfo): 
		self.cfg = cfg
		self.curentScanInfo = curentScanInfo
		self.data = rawData
		self.fileName = self.cfg["DataFileName"]
		self.filePath = filePath 
		self.detChosen = detChosen
		self.scanNum = rawData["Scan#"]
		self.expStartTime = expStartTime
		self.expStartTimeDF = expStartTimeDF

		############ Meta Data collection from cfg ############

		self.numScans = self.cfg["Nscans"]
		self.numIntervals = self.cfg["NIntervals"]
		self.numSamples = self.cfg["Nsamples"]
		self.settlingTime = self.cfg["settlingTime"]
		self.scanNum = self.curentScanInfo[1]["Scan"]
		self.intervalNum = self.curentScanInfo[2]["Interval"]
		self.sampleNum = self.curentScanInfo[0]["Sample"]
		self.sampleTitle = self.curentScanInfo[4]["sampleTitle"]
		self.edge = self.cfg["ExpMetaData"][0]["edge"]
		self.sampleName = self.cfg["ExpMetaData"][1]["sampleName"]
		self.energy = self.cfg["ExpMetaData"][2]["energy"]
		self.stoichiometry = self.cfg["ExpMetaData"][3]["stoichiometry"]
		self.samplePrep = self.cfg["ExpMetaData"][4]["samplePrep"]
		self.vcm = self.cfg["ExpMetaData"][5]["vcm"]
		self.vfm = self.cfg["ExpMetaData"][6]["vfm"]
		self.Mono = self.cfg["ExpMetaData"][7]["Mono"]
		self.userCom = self.cfg["ExpMetaData"][8]["userCom"]
		self.expCom = self.cfg["ExpMetaData"][9]["expCom"]
		self.RINGCurrent = self.curentScanInfo[3]["RINGCurrent"]
		# tmp delete this line belwo. 
		self.currentSP = self.curentScanInfo[5]["TargetSP"]

		self.personalInfoFlage = 0

		
		if self.cfg["expType"] == "proposal":
			try: 
				self.propInfo = readFile("configrations/userinfo.json").readJSON()
				self.proposalID = self.propInfo["Proposal"]
				self.propTitle = self.propInfo["Title"]
				self.PI = self.propInfo["Proposer"]
				self.PIEmail = self.propInfo["Email"]
				self.personalInfoFlage = 1
			except: 
				pass

		self.d_spacing = 3.1356 if self.Mono == "Si 111" else 1.6374

		self.createXDIFile()

	def createXDIFile(self):
		"""
		this method does the follwoing: 
		- generats the file name 
		- creats xdi file in respect to the chosen detector
		"""
		self.fullFileName = self.filePath +"/" + self.fileName + "_" + self.sampleTitle + "_" + "Scan" + str(self.data["Scan#"]) + "_" + self.expStartTime + ".xdi"
		#print (self.fullFileName)
		if "KEITHLEY_I0" in self.detChosen:
			if "KEITHLEY_Itrans"  in self.detChosen: 
				if "BRUKER" in self.detChosen: 
					self.createKEITHLEY_I0_Itrans_Bruker()
					self.fillKEITHLEY_I0_Itrans_Bruker()
				else:
					self.createKEITHLEY_I0_Itrans()
					self.fillKEITHLEY_I0_Itrans()
			elif "BRUKER" in self.detChosen: 
				self.createKEITHLEY_I0_Bruker()
				self.fillKEITHLEY_I0_Bruker()
			else:
				self.createKEITHLEY_I0()
				self.fillKEITHLEY_I0()


		else: 
			CLIMessage("xdiWriter can't recognize the chosen detector","E")
		self.onClose()
	
	def createKEITHLEY_I0(self):
		
		if not os.path.exists(self.fullFileName): 
			f = open (self.fullFileName, "w")
			f.write("# XDI/1.0 SED_HESEB/0.9\n")
			f.write("# Column.1: PGM energy (eV)\n")
			f.write("# Column.2: I0\n")
			if self.personalInfoFlage == 1:
				f.write("# Experiment.Type: Proposal\n")
				f.write("# Proposal.ID: {}\n".format(self.proposalID))
				f.write("# Proposal.title: {}\n".format(self.propTitle))
				f.write("# PI: {}\n".format(self.PI))
				f.write("# PI Email: {}\n".format(self.PIEmail))
			else: 
				f.write("# Experiment.Type: Local\n")
			f.write("# Base.file_name: {}\n".format(self.fileName))
			f.write("# Element.edge: {}\n".format(self.edge))
			f.write("# Mono.name: {}\n".format(self.Mono))
			f.write("# Mono.d_spacing: {}\n".format(self.d_spacing))
			f.write("# Mono.settling_time: {}\n".format(self.settlingTime))
			f.write("# Beamline.name: HESEB | Soft X-ray beamline (ID11)\n")
			f.write("# Beamline.collimation: slits\n")
			f.write("# Beamline.focusing: no\n")
			f.write("# Beamline.harmonic_rejection: mirror coating VCM: {}, VFM: {}\n".format(self.vcm, self.vfm))
			f.write("# Facility.name: SESAME Synchrotron-light\n")
			f.write("# Facility.energy: 2.50 GeV\n")
			f.write("# Facility.current: {}\n".format(self.RINGCurrent))
			f.write("# Facility.xray_source: SESAME Bending Magnet\n")
			f.write("# Scan.start_time: {}\n".format(str(self.expStartTimeDF) ))
			f.write("# Scan.end_time: xxx\n")
			f.write("# Scan.edge_energy: {}\n".format(self.energy))
			f.write("# Scan.number: {}/{} -- intervals: {}, samples: {}\n".format(self.scanNum, self.numScans, self.numIntervals, self.numSamples))
			f.write("# Element.symbol: {}\n".format(self.sampleName))
			f.write("# Sample.stoichiometry: {}\n".format(self.stoichiometry))
			f.write("# Sample.prep: {}\n".format(self.samplePrep))
			f.write("# ///\n")
			f.write("# Experiment comments and remarks: {}\n".format(self.expCom))
			f.write("# User comments and remarks: {}\n".format(self.userCom))
			f.write("#----\n")
			f.write("#(1)energy    (2)I0    3 intTime\n")
			f.close()

	def fillKEITHLEY_I0(self):
		f = open (self.fullFileName, "a")
		f.write("%10.6e  %10.6e   %s\n" 
		%(float(self.data["ENERGY-RBK"]), float(self.data["KEITHLEY_I0"]), self.data["KEITHLEY_I0_intTime"]))
		f.close()


	def createKEITHLEY_I0_Itrans(self):
		
		if not os.path.exists(self.fullFileName): 
			f = open (self.fullFileName, "w")
			f.write("# XDI/1.0 SED_HESEB/0.9\n")
			f.write("# Column.1: energy eV\n")
			f.write("# Column.2: I0\n")
			f.write("# Column.2: Itrans\n")
			if self.personalInfoFlage == 1:
				f.write("# Experiment.Type: Proposal\n")
				f.write("# Proposal.ID: {}\n".format(self.proposalID))
				f.write("# Proposal.title: {}\n".format(self.propTitle))
				f.write("# PI: {}\n".format(self.PI))
				f.write("# PI Email: {}\n".format(self.PIEmail))
			else: 
				f.write("# Experiment.Type: Local\n")
			f.write("# Base.file_name: {}\n".format(self.fileName))
			f.write("# Element.edge: {}\n".format(self.edge))
			f.write("# Mono.name: {}\n".format(self.Mono))
			f.write("# Mono.d_spacing: {}\n".format(self.d_spacing))
			f.write("# Mono.settling_time: {}\n".format(self.settlingTime))
			f.write("# Beamline.name: HESEB | Soft X-ray beamline (ID11)\n")
			f.write("# Beamline.collimation: slits\n")
			f.write("# Beamline.focusing: no\n")
			f.write("# Beamline.harmonic_rejection: mirror coating VCM: {}, VFM: {}\n".format(self.vcm, self.vfm))
			f.write("# Facility.name: SESAME Synchrotron-light\n")
			f.write("# Facility.energy: 2.50 GeV\n")
			f.write("# Facility.current: {}\n".format(self.RINGCurrent))
			f.write("# Facility.xray_source: SESAME Bending Magnet\n")
			f.write("# Scan.start_time: {}\n".format(str(self.expStartTimeDF) ))
			f.write("# Scan.end_time: xxx\n")
			f.write("# Scan.edge_energy: {}\n".format(self.energy))
			f.write("# Scan.number: {}/{} -- intervals: {}, samples: {}\n".format(self.scanNum, self.numScans, self.numIntervals, self.numSamples))
			f.write("# Element.symbol: {}\n".format(self.sampleName))
			f.write("# Sample.stoichiometry: {}\n".format(self.stoichiometry))
			f.write("# Sample.prep: {}\n".format(self.samplePrep))
			f.write("# ///\n")
			f.write("# Experiment comments and remarks: {}\n".format(self.expCom))
			f.write("# User comments and remarks: {}\n".format(self.userCom))
			f.write("#----\n")
			f.write("#(1)energyRBV  (tmp_EnergySP)   RBV_SP_diff  (2)I0   (3)Itrans\n")
			f.close()


	def fillKEITHLEY_I0_Itrans(self):
		f = open (self.fullFileName, "a")
		f.write("%10.6e  %10.6e  %.9f  %10.6e  %10.6e \n" 
		%(float(self.data["ENERGY-RBK"]), float(self.currentSP),abs(float(self.data["ENERGY-RBK"])-float(self.currentSP)), float(self.data["KEITHLEY_I0"]), float(self.data["KEITHLEY_Itrans"])))
		f.close()

	def onClose(self): 
		#f = open (self.fullFileName, "a")
		scanEndTime = "Scan.end_time: {}".format(str(time.strftime("%Y-%m-%dT%H:%M:%S")) )
		for line in fileinput.input(self.fullFileName, inplace=1):
			line = line.replace("Scan.end_time: xxx", scanEndTime)
			sys.stdout.write(line)