import os
import sys
import time
import fileinput
from SEDSS.SEDSupport import readFile

class XDIWriter:
	"""
	rawData: raw data received from the scanning tool
	filePath: file path
	fileName: file name
	detChosen: a list contains the detector chosen.
	expStartTime: Experiment start data and time to be part of the file name
	cfg: includes experiment configurations
	currentScanInfo: contains information about the current scan (i.e. scan number, interval number)
	"""
	def __init__(self, rawData, filePath, detChosen, expStartTime, expStartTimeDF, cfg, currentScanInfo):
		self.cfg = cfg
		self.currentScanInfo = currentScanInfo
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
		self.scanNum = self.currentScanInfo[1]["Scan"]
		self.intervalNum = self.currentScanInfo[2]["Interval"]
		self.sampleNum = self.currentScanInfo[0]["Sample"]
		self.sampleTitle = self.currentScanInfo[4]["sampleTitle"]
		self.edge = self.cfg["ExpMetaData"][0]["edge"]
		self.sampleName = self.cfg["ExpMetaData"][1]["sampleName"]
		self.energy = self.cfg["ExpMetaData"][2]["energy"]
		self.stoichiometry = self.cfg["ExpMetaData"][3]["stoichiometry"]
		self.samplePrep = self.cfg["ExpMetaData"][4]["samplePrep"]
		# self.vcm = self.cfg["ExpMetaData"][5]["vcm"]
		# self.vfm = self.cfg["ExpMetaData"][6]["vfm"]
		# self.Mono = self.cfg["ExpMetaData"][7]["Mono"]
		self.userCom = self.cfg["ExpMetaData"][5]["userCom"]
		self.expCom = self.cfg["ExpMetaData"][6]["expCom"]
		self.RINGCurrent = self.currentScanInfo[3]["RINGCurrent"]
		self.currentSP = self.currentScanInfo[5]["TargetSP"]			# tmp delete this line
		self.personalInfoFlage = 0

		ROIs = self.cfg["ROIs"]
		self.selectedROIs = []
		for ROI in ROIs:
			self.selectedROIs.append(int(ROI[-1]))

		if self.cfg["expType"] == "proposal":
			try:
				self.propInfo = readFile("configurations/userinfo.json").readJSON()
				self.proposalID = self.propInfo["Proposal"]
				self.propTitle = self.propInfo["Title"]
				self.PI = self.propInfo["Proposer"]
				self.PIEmail = self.propInfo["Email"]
				self.personalInfoFlage = 1
			except:
				pass

		self.d_spacing = 3.1356 	# if self.Mono == "Si 111" else 1.6374

		self.createXDIFile()

	def createXDIFile(self):
		"""
		this method does the following:
		- generates the file name
		- creates xdi file in respect to the chosen detector
		"""
		self.fullFileName = self.filePath + "/" + self.fileName + "_" + self.sampleTitle + "_" + "Scan" + str(self.data["Scan#"]) + "_" + self.expStartTime + ".xdi"

		# KEITHLEY_I0 is already chosen
		if "KEITHLEY_Itrans"  in self.detChosen:
			if "XFLASH" in self.detChosen:
				self.createKEITHLEY_I0_Itrans_XFLASH()
				self.fillKEITHLEY_I0_Itrans_XFLASH()
			else:
				self.createKEITHLEY_I0_Itrans()
				self.fillKEITHLEY_I0_Itrans()
		elif "XFLASH" in self.detChosen:
			self.createKEITHLEY_I0_XFLASH()
			self.fillKEITHLEY_I0_XFLASH()
		else:
			self.createKEITHLEY_I0()
			self.fillKEITHLEY_I0()
		self.onClose()

	def createKEITHLEY_I0(self):
		if not os.path.exists(self.fullFileName):
			f = open (self.fullFileName, "w")
			f.write("# XDI/1.0 SED_HESEB/0.9\n")
			f.write("# Column.1: PGM energy (eV) - Set point\n")
			f.write("# Column.2: PGM energy (eV) - Read back\n")
			f.write("# Column.3: I0\n")
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
			# f.write("# Mono.name: {}\n".format(self.Mono))
			f.write("# Mono.d_spacing: {}\n".format(self.d_spacing))
			f.write("# Mono.settling_time: {}\n".format(self.settlingTime))
			f.write("# Beamline.name: HESEB | Soft X-ray beamline (ID11)\n")
			f.write("# Beamline.collimation: slits\n")
			f.write("# Beamline.focusing: no\n")
			# f.write("# Beamline.harmonic_rejection: mirror coating VCM: {}, VFM: {}\n".format(self.vcm, self.vfm))
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
			f.write("#(1)energy_SP    (1)energy_RBV    (3)I0\n")
			f.close()

	def fillKEITHLEY_I0(self):
		f = open (self.fullFileName, "a")
		f.write("%10.6e  %10.6e  %10.6e\n" 
		%(float(self.currentSP), float(self.data["ENERGY-RBK"]),float(self.data["KEITHLEY_I0"])))
		f.close()

	def createKEITHLEY_I0_Itrans(self):
		if not os.path.exists(self.fullFileName):
			f = open (self.fullFileName, "w")
			f.write("# XDI/1.0 SED_HESEB/0.9\n")
			f.write("# Column.1: PGM energy (eV) - Set point\n")
			f.write("# Column.2: PGM energy (eV) - Read back\n")
			f.write("# Column.3: I0\n")
			f.write("# Column.4: Itrans\n")
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
			# f.write("# Mono.name: {}\n".format(self.Mono))
			f.write("# Mono.d_spacing: {}\n".format(self.d_spacing))
			f.write("# Mono.settling_time: {}\n".format(self.settlingTime))
			f.write("# Beamline.name: HESEB | Soft X-ray beamline (ID11)\n")
			f.write("# Beamline.collimation: slits\n")
			f.write("# Beamline.focusing: no\n")
			# f.write("# Beamline.harmonic_rejection: mirror coating VCM: {}, VFM: {}\n".format(self.vcm, self.vfm))
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
			f.write("#(1)energy_SP   (2)energy_RBV   (3)I0   (4)Itrans\n")
			f.close()

	def fillKEITHLEY_I0_Itrans(self):
		f = open (self.fullFileName, "a")
		f.write("%10.6e  %10.6e  %10.6e  %10.6e \n" 
		%(float(self.currentSP), float(self.data["ENERGY-RBK"]), float(self.data["KEITHLEY_I0"]), float(self.data["KEITHLEY_Itrans"])))
		f.close()

	def createKEITHLEY_I0_Itrans_XFLASH(self):
		if not os.path.exists(self.fullFileName):
			f = open (self.fullFileName, "w")
			f.write("# XDI/1.0 SED_HESEB/0.9\n")
			f.write("# Column.1: PGM energy (eV) - Set point\n")
			f.write("# Column.2: PGM energy (eV) - Read back\n")
			f.write("# Column.3: I0\n")
			f.write("# Column.4: Itrans\n")
			f.write("# Column.5: mutrans (log(I0/Itrans) \n")
			f.write("# Column.6: XFLASH-Ifluor \n")
			f.write("# Column.7: XFLASH-mufluor \n")
			f.write("# Column.8: XFLASH-INT_TIME[sec]\n")
			startCol = 9
			header = "(1)energy_SP   (2)energy_RBV   (3)I0   (4)Itrans   (5)mutrans   (6)XFLASH-Ifluor   (7)XFLASH-mufluor   (8)XFLASH-INT_TIME[sec]"
			for ROI in self.selectedROIs:
				f.write(f"# Column.{startCol}: XFLASH-ROI_{ROI}\n")
				header = header + f"   ({startCol})XFLASH-ROI_{ROI}"
				startCol += 1
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
			f.write("# Mono.d_spacing: {}\n".format(self.d_spacing))
			f.write("# Mono.settling_time: {}\n".format(self.settlingTime))
			f.write("# Beamline.name: HESEB | Soft X-ray beamline (ID11)\n")
			f.write("# Beamline.collimation: slits\n")
			f.write("# Beamline.focusing: no\n")
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
			f.write(header)
			f.write("\n")
			f.close()

	def fillKEITHLEY_I0_Itrans_XFLASH(self):
		f = open (self.fullFileName, "a")
		baseFormat = "%10.6e   %10.6e   %10.6e   %10.6e   %10.6e   %10.6e   %10.6e   %10.6e"
		data = (float(self.currentSP), 
		  	float(self.data["ENERGY-RBK"]), 
			float(self.data["KEITHLEY_I0"]),
			float(self.data["KEITHLEY_Itrans"]),
			float(self.data["TRANS"]),
			float(self.data["XFLASH-If"]),
			float(self.data["XFLASH-FLUOR"]),
			float(self.data["XFLASH-INT_TIME[sec]"]))

		ROIsFormat = ""
		ROIsData = []

		ROIsFormat = "   ".join(["%10.6e"] * len(self.selectedROIs))
		ROIsData = [float(self.data[f"XFLASH-ROI_{ROI}[c/s]"]) for ROI in self.selectedROIs]

		fullFormat = baseFormat + "   " + ROIsFormat + "\n"
		fullData = data + tuple(ROIsData)

		f.write(fullFormat % fullData)
		f.close()

	def createKEITHLEY_I0_XFLASH(self):
		if not os.path.exists(self.fullFileName):
			f = open (self.fullFileName, "w")
			f.write("# XDI/1.0 SED_HESEB/0.9\n")
			f.write("# Column.1: PGM energy (eV) - Set point\n")
			f.write("# Column.2: PGM energy (eV) - Read back\n")
			f.write("# Column.3: I0\n")
			f.write("# Column.4: XFLASH-Ifluor \n")
			f.write("# Column.5: XFLASH-mufluor \n")
			f.write("# Column.6: XFLASH-INT_TIME[sec]\n")
			startCol = 7
			header = "(1)energy_SP   (2)energy_RBV   (3)I0   (4)XFLASH-Ifluor   (5)XFLASH-mufluor   (6)XFLASH-INT_TIME[sec]"
			for ROI in self.selectedROIs:
				f.write(f"# Column.{startCol}: XFLASH-ROI_{ROI}\n")
				header = header + f"   ({startCol})XFLASH-ROI_{ROI}"
				startCol += 1
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
			f.write("# Mono.d_spacing: {}\n".format(self.d_spacing))
			f.write("# Mono.settling_time: {}\n".format(self.settlingTime))
			f.write("# Beamline.name: HESEB | Soft X-ray beamline (ID11)\n")
			f.write("# Beamline.collimation: slits\n")
			f.write("# Beamline.focusing: no\n")
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
			f.write(header)
			f.write("\n")
			f.close()

	def fillKEITHLEY_I0_XFLASH(self):
		f = open (self.fullFileName, "a")

		baseFormat = "%10.6e   %10.6e   %10.6e   %10.6e   %10.6e   %10.6e"
		data = (float(self.currentSP),
			float(self.data["ENERGY-RBK"]), 
			float(self.data["KEITHLEY_I0"]),
			float(self.data["XFLASH-If"]),
			float(self.data["XFLASH-FLUOR"]),
			float(self.data["XFLASH-INT_TIME[sec]"]))

		ROIsFormat = ""
		ROIsData = []

		ROIsFormat = "   ".join(["%10.6e"] * len(self.selectedROIs))
		ROIsData = [float(self.data[f"XFLASH-ROI_{ROI}[c/s]"]) for ROI in self.selectedROIs]

		fullFormat = baseFormat + "   " + ROIsFormat + "\n"
		fullData = data + tuple(ROIsData)

		f.write(fullFormat % fullData)
		f.close()

	def onClose(self):
		scanEndTime = "Scan.end_time: {}".format(str(time.strftime("%Y-%m-%dT%H:%M:%S")) )
		for line in fileinput.input(self.fullFileName, inplace=1):
			line = line.replace("Scan.end_time: xxx", scanEndTime)
			sys.stdout.write(line)