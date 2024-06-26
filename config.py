
#!/usr/bin/python3

from forms import configWizard, samplespositionForm, intervalsForm, detectorsForm
from enum import Enum
from PyQt5 import QtWidgets, QtCore
import json
import datetime
import sys
import subprocess
import csv
import re
import os
import epics
from epics import caget 
from SEDSS.SEDSupport import readFile
from SEDSS.SEDSupplements import CLIMessage, UIMessage
from SEDSS.SEDValueValidate import CSVProposal
from SEDSS.SEDFileManager import path
from  common import Common

class ConfigGUI:
	class WizardPages(Enum):
		ExperimentType = 0
		SED = 1
		CfgFile = 2
		LoadCfg = 3
		editCfg = 4
		startscan = 5

	def __init__(self,paths):
		self.Qwiz = QtWidgets.QWizard()
		#self.QCore =
		self.guiObj = configWizard.Ui_Wizard()
		self.guiObj.setupUi(self.Qwiz)
		self.paths = paths
		self.cfg = {}
		self.expType = "users"
		self.masterExpType = "proposal" #this is a master exp type to avoid overwriting by loading config file 
		self.IntervalsGUI   = IntervalGUI()
		self.SamplesGUI     = SamplePosGUI()
		self.DetectorsGUI   = DetectorsGUI()
		self.guiObj.ExpType.nextId = self.CheckExptype
		self.guiObj.SED.nextId = self.checkPropsalID
		self.guiObj.CfgFile.nextId = self.cfgfile
		self.guiObj.CfgPath.nextId = self.loadcfg
		self.guiObj.scan_params.nextId = self.checkConfig
		self.Qwiz.button(QtWidgets.QWizard.FinishButton).clicked.connect(self.start)
		self.Qwiz.button(QtWidgets.QWizard.CancelButton).clicked.connect(self.onClose)
		self.Qwiz.setWindowFlag(QtCore.Qt.CustomizeWindowHint) # Need to be set firstly before dealing with windows buttons
		self.Qwiz.setWindowFlag(QtCore.Qt.WindowCloseButtonHint, False)
		self.guiObj.Browse.clicked.connect(self.BrowseCfgFile)
		self.guiObj.editIntrv.clicked.connect(self.editIntervals)
		self.guiObj.editSample.clicked.connect(self.editSamples)
		self.guiObj.configureDetectors.clicked.connect(self.Detectors)
		self.Qwiz.exec_()

	def onClose(self): 
		CLIMessage("===========    Close the scanning tool    ===========","W")
		epics.PV("SCAN:STOP").put(1)
		sys.exit()

	def CheckExptype(self):
		if self.guiObj.UsersExp.isChecked():
			self.expType = "proposal"
			self.masterExpType = "proposal"
			self.cfg["expType"] = self.expType
			return self.WizardPages.SED.value

		else:
			self.expType = "local"
			self.masterExpType = "local"
			self.cfg["expType"] = self.expType
			return self.WizardPages.CfgFile.value
	
	def getExpType(self):
		return self.masterExpType

	def checkPropsalID(self):
		proposal_ID = self.guiObj.PropsalID.text()
		if proposal_ID == '':
			return self.WizardPages.ExperimentType.value
		else:
			SedObj = SED()
			result = SedObj.init(proposal_ID, self.paths)
			if result:
				self.cfg["proposalID"] = SedObj.proposalID
				return self.WizardPages.CfgFile.value
			else:
				return self.WizardPages.SED.value

	def cfgfile(self):
		if self.guiObj.Create.isChecked():
			self.cfg["loadedConfig"] = "No"
			return self.WizardPages.editCfg.value
			
		else:
			self.cfg["loadedConfig"] = "Yes"
			return self.WizardPages.LoadCfg.value
			
	def loadcfg(self):
		path = self.guiObj.filePath.text()
		if not path == "":
			self.cfg["loadedConfig"] = "Yes"
			return self.WizardPages.editCfg.value
			
		else:
			return self.WizardPages.LoadCfg.value

	def editIntervals(self):
		global Nintrv
		Nintrv = self.guiObj.setNumofIterv.text()
		if Common.regexvalidation("NIntervals", Nintrv):
			Nintrv = int(Nintrv)
			self.cfg["NIntervals"] = Nintrv
			self.IntervalsGUI.setIntervalsNumber(self.cfg)
			self.IntervalsGUI.intervalDialog.exec()				
		else:
			Common.show_message(QtWidgets.QMessageBox.Critical,
								"Please enter Number of Intervals",
								"HESEB scan tool", QtWidgets.QMessageBox.Ok)
	def Detectors(self):
		if "detectors" in self.cfg.keys():
			for Detector in self.cfg["detectors"]:
				det = getattr(self.DetectorsGUI.detectors_UI, Detector)
				det.setChecked(True)
			if 'XFLASH' in self.cfg['detectors']:
				for roi in self.cfg["ROIs"]:
					checkBox = getattr(self.DetectorsGUI.detectors_UI, roi)
					checkBox.setChecked(True)
		self.DetectorsGUI.detectorsDialog.exec_()
	
	def editSamples(self):
		Nsamples = self.guiObj.setNumofSamples.text()
		if Common.regexvalidation("Nsample", Nsamples):
			Nsamples = int(Nsamples)
			self.cfg["Nsamples"] = Nsamples
			self.SamplesGUI.setSamplesNumber(self.cfg)
			self.SamplesGUI.sampleDialog.exec_()
		else:
			Common.show_message(QtWidgets.QMessageBox.Critical,
								"Please enter Number of samples",
								"HESEB scan tool", QtWidgets.QMessageBox.Ok)

	def BrowseCfgFile(self):
		try:
			self.IntervalsGUI	= IntervalGUI()
			self.SamplesGUI		= SamplePosGUI()
			self.DetectorsGUI	= DetectorsGUI()
			self.cfgpath = QtWidgets.QFileDialog.getOpenFileName(self.Qwiz, "choose configuration file", "~","*.cfg")[0]
			try:
				self.guiObj.filePath.setText(self.cfgpath)
				self.cfg = self.loadcfgfile(self.cfgpath)
			except:
				CLIMessage("Could not locate the config file", "W")
				return self.WizardPages.editCfg.value

			try: 
				NIntervals = self.cfg["NIntervals"]
				Nsamples = self.cfg["Nsamples"]
				Nscans = self.cfg["Nscans"]
				settlingTime = self.cfg["settlingTime"]
			except:
				UIMessage("Error reading config file",
					"Unable to read from configration file", 
					"Try to load another file").showCritical()
				CLIMessage("Unable to read configuration file, scanning can not continue!!","E")
				sys.exit()

			self.guiObj.setNumofIterv.setText(str(NIntervals))
			self.guiObj.setNumofSamples.setText(str(Nsamples))
			self.guiObj.setNumofScans.setText(str(Nscans))
			self.guiObj.settlingTime.setText(str(settlingTime))
			self.guiObj.setDataFileName.setText(self.cfg["DataFileName"])
			self.guiObj.edge.setCurrentText(str(self.cfg["ExpMetaData"][0]["edge"]))
			self.guiObj.sampleName.setText(str(self.cfg["ExpMetaData"][1]["sampleName"]))
			self.guiObj.energy.setText(self.cfg["ExpMetaData"][2]["energy"])
			self.guiObj.stoichiometry.setText(str(self.cfg["ExpMetaData"][3]["stoichiometry"]))
			self.guiObj.samplePrep.setText(str(self.cfg["ExpMetaData"][4]["samplePrep"]))
			# self.guiObj.vcm.setCurrentText(str(self.cfg["ExpMetaData"][5]["vcm"]))
			# self.guiObj.vfm.setCurrentText(str(self.cfg["ExpMetaData"][6]["vfm"]))
			# self.guiObj.Mono.setCurrentText(str(self.cfg["ExpMetaData"][7]["Mono"]))
			self.guiObj.userCom.setText(str(self.cfg["ExpMetaData"][5]["userCom"]))
			self.guiObj.expCom.setText(str(self.cfg["ExpMetaData"][6]["expCom"]))

			for interval in range(len(self.cfg["Intervals"])):
				self.IntervalsGUI.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.start.value,QtWidgets.QTableWidgetItem(str(self.cfg["Intervals"][interval]["Startpoint"]),0))
				self.IntervalsGUI.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.end.value,QtWidgets.QTableWidgetItem(str(self.cfg["Intervals"][interval]["Endpoint"]),0))
				self.IntervalsGUI.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.step.value,QtWidgets.QTableWidgetItem(str(self.cfg["Intervals"][interval]["Stepsize"]),0))
				self.IntervalsGUI.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.ICInt.value,QtWidgets.QTableWidgetItem(str(self.cfg["Intervals"][interval]["picoAmmIntTime"]),0))

			for sample in range(len(self.cfg["Samplespositions"])):
				self.SamplesGUI.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.X.value,QtWidgets.QTableWidgetItem(str(self.cfg["Samplespositions"][sample]["Xposition"]), 0))
				self.SamplesGUI.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.Y.value,QtWidgets.QTableWidgetItem(str(self.cfg["Samplespositions"][sample]["Yposition"]), 0))
				self.SamplesGUI.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.Z.value,QtWidgets.QTableWidgetItem(str(self.cfg["Samplespositions"][sample]["Zposition"]), 0))
				self.SamplesGUI.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.R.value,QtWidgets.QTableWidgetItem(str(self.cfg["Samplespositions"][sample]["Rotation"]), 0))
				self.SamplesGUI.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.Title.value,QtWidgets.QTableWidgetItem(str(self.cfg["Samplespositions"][sample]["sampleTitle"]), 0))

			if "KEITHLEY_I0" in self.cfg["detectors"]:
				detCheckbox = getattr(self.DetectorsGUI.detectors_UI, "KEITHLEY_I0")
				detCheckbox.setChecked(True)

			if "XFLASH" in self.cfg["detectors"]:
				detCheckbox = getattr(self.DetectorsGUI.detectors_UI, "XFLASH")
				detCheckbox.setChecked(True)
				if "ROI_0" or "ROI_1" or "ROI_2" or "ROI_3"or "ROI_4" or "ROI_5" or "ROI_6" or "ROI_7" or "ROI_8" in self.cfg["ROIs"]:
					if 'XFLASH' in self.cfg['detectors']:
						for roi in self.cfg["ROIs"]:
							checkbox = getattr(self.DetectorsGUI.detectors_UI, roi)
							checkbox.setChecked(True)
			
			if "KEITHLEY_Itrans" in self.cfg["detectors"]:
				detCheckbox = getattr(self.DetectorsGUI.detectors_UI, "KEITHLEY_Itrans")
				detCheckbox.setChecked(True)

			self.cfg["expType"] = self.masterExpType # to avoid overwriting the choosen exp type when load a config file
		except:
			CLIMessage("Problem reading the config file. Try another one","E")
			return self.WizardPages.editCfg.value

	def checkConfig(self):
		expMetaData = []
		try:
			NIntervals = self.guiObj.setNumofIterv.text()
			if NIntervals == '' or not Common.regexvalidation("NIntervals",NIntervals):
				CLIMessage("Please enter valid Number of intervals","W")
				return self.WizardPages.editCfg.value
			self.IntervalsGUI.setIntervalsNumber(self.cfg)
			Nsamples = self.guiObj.setNumofSamples.text()
			if Nsamples == '' or not Common.regexvalidation("Nsample", Nsamples):
				CLIMessage("Please enter valid number of Samples","W")
				return self.WizardPages.editCfg.value

			Nscans = self.guiObj.setNumofScans.text()
			if Nscans == '' or not Common.regexvalidation("Nscans", Nscans):
				CLIMessage("Please enter valid number of scans","W")
				return self.WizardPages.editCfg.value

			DataFileName = self.guiObj.setDataFileName.text()
			if DataFileName == '' or not Common.regexvalidation("DataFileName", DataFileName):
				CLIMessage("Please enter a valid data file name", "W")
				return self.WizardPages.editCfg.value

			settlingTime = self.guiObj.settlingTime.text()
			if settlingTime == '' or not Common.regexvalidation("settlingTime", settlingTime):
				CLIMessage("Please enter valid settling time", "W")
				return self.WizardPages.editCfg.value

			intervals = [{} for i in range(int(NIntervals))]
			for interval in range(int(NIntervals)):#range(self.IntervalsGUI.interval_UI.tableWidget.rowCount()):
				"""
				without try and except, the script will try to check the linedit text before inisialization 
				and thus generat errors 
				"""
				try: 
					start = self.IntervalsGUI.interval_UI.tableWidget.item(interval, 0).text()
					if start == '' or not Common.validate("Startpoint", start, "Please enter valid start point"):
						CLIMessage("Please check/enter the start point for interval number {}".format(interval), "W") 
						return self.WizardPages.editCfg.value

				except: 
					CLIMessage("Please check/enter the start point for interval number {}".format(interval), "W") 

				try: 
					end = self.IntervalsGUI.interval_UI.tableWidget.item(interval,1).text()
					if end == '' or not Common.validate("Endpoint", end, "Please enter valid end point"):
						CLIMessage("Please check/enter the end point for interval number {}".format(interval), "W") 
						return self.WizardPages.editCfg.value
				except:
					CLIMessage("Please check/enter the end point for interval number {}".format(interval), "W") 

				try: 
					stepsize = self.IntervalsGUI.interval_UI.tableWidget.item(interval, 2).text()
					if stepsize == '' or not Common.validate("Stepsize", end, "Please enter valid step size"):
						CLIMessage("Please check/enter the step-size for interval number {}".format(interval), "W") 
						return self.WizardPages.editCfg.value
				except: 
					CLIMessage("Please check/enter the step-size for interval number {}".format(interval), "W") 

				try:
					picoAmmIntTime = self.IntervalsGUI.interval_UI.tableWidget.item(interval, 3).text()
					if picoAmmIntTime == '' or not Common.validate("picoAmmetersIntTime", end,"Please enter valid pico ammeter integration time for "\
						"interval number {}".format(interval)):
						CLIMessage("Please check/enter the pico ammeter integration time for interval number {}".format(interval), "W") 
						return self.WizardPages.editCfg.value
					if float(picoAmmIntTime) not in (0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0):
						UIMessage("Correct KEITHLEY intTime is needed!!" , "The provide integration time for KEITHLEY PICOAMETER is "\
							"not valid", "Allowed integration time that you can set is: "\
							"0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0").showWarning()
						return self.WizardPages.editCfg.value

				except: 
					CLIMessage("Please check/enter the ICs integration time for interval number {}".format(interval), "W")

			SamplePositions = [{} for i in range(int(Nsamples))]
			for sample in range(self.SamplesGUI.sample_UI.samplepositions.rowCount()):
				try: 
					Xposition = self.SamplesGUI.sample_UI.samplepositions.item(sample, 0).text()
					if Xposition == '' or not Common.validate("Xposition", Xposition,"Please enter valid sample x position"):
						CLIMessage("Please check/enter (x) position for sample number {}".format(sample), "W") 
						return self.WizardPages.editCfg.value
					Yposition = self.SamplesGUI.sample_UI.samplepositions.item(sample, 1).text()
					if Yposition == '' or not Common.validate("Yposition", Yposition,"Please enter valid sample y position"):
						CLIMessage("Please check/enter (y) position for sample number {}".format(sample), "W") 
						return self.WizardPages.editCfg.value

					Zposition = self.SamplesGUI.sample_UI.samplepositions.item(sample, 2).text()
					if Zposition == '' or not Common.validate("Zposition", Zposition,"Please enter valid sample Z position"):
						CLIMessage("Please check/enter (Z) position for sample number {}".format(sample), "W") 
						return self.WizardPages.editCfg.value
				except: 
					CLIMessage("Please check/enter (x,y,Z) position for sample number {}".format(sample), "W")

				try:
					sampleTitle = self.SamplesGUI.sample_UI.samplepositions.item(sample, 3).text()
					if sampleTitle == '' or not Common.validate("sampleTitle", sampleTitle,"Please enter valid sample name"):
						CLIMessage("Please check/enter sample name in the Samples dialog for the sameple number: {}".format(sample), "W") 
						return self.WizardPages.editCfg.value
				except:
					CLIMessage("Please check/enter the sample name in the Samples dialog", "W")
					return self.WizardPages.editCfg.value

			####################### Metadata section ##############################

			if self.guiObj.edge.currentText() == "":
				CLIMessage("Please choose the element edge", "W")
				return self.WizardPages.editCfg.value
			else:
				#senderIndex = self.guiObj.edge.sender().index
				#print(senderIndex)
				expMetaData.append({"edge":self.guiObj.edge.currentText()})

			if self.guiObj.sampleName.text() == "":
				CLIMessage("Please enter the periodic element for this experiment", "W")
				return self.WizardPages.editCfg.value
			else:
				if Common.regexvalidation("sampleName", self.guiObj.sampleName.text()):
					expMetaData.append({"sampleName":self.guiObj.sampleName.text()})
				else:
					Common.show_message(QtWidgets.QMessageBox.Critical,
						"Enter a valid format of the periodic element please !!","HESEB scan tool",
						QtWidgets.QMessageBox.Ok)
					return self.WizardPages.editCfg.value

			##################################
			energyVal = self.guiObj.energy.text()
			#print (energyVal, type(energyVal))
			if energyVal == "":
				CLIMessage("Please enter energy", "W")
				return self.WizardPages.editCfg.value
			else:
				if Common.regexvalidation("energy", energyVal):
					expMetaData.append({"energy":self.guiObj.energy.text()})
				else:
					Common.show_message(QtWidgets.QMessageBox.Critical,
						"Enter a valid energy please !!","HESEB scan tool",
						QtWidgets.QMessageBox.Ok)
					return self.WizardPages.editCfg.value
			###################################

			if self.guiObj.stoichiometry.text() == "":
				expMetaData.append({"stoichiometry":"NONE"})
				#return self.WizardPages.editCfg.value
			else:
				expMetaData.append({"stoichiometry":self.guiObj.stoichiometry.text()})

			if self.guiObj.samplePrep.text() == "":
				CLIMessage("Please enter the sample preperation for this experiment", "W")
				return self.WizardPages.editCfg.value
			else:
				expMetaData.append({"samplePrep":self.guiObj.samplePrep.text()})

			# if self.guiObj.vcm.currentText() == "":
			# 	CLIMessage("Mirror coating | Please choose vcm element", "W")
			# 	return self.WizardPages.editCfg.value
			# else:
			# 	expMetaData.append({"vcm":self.guiObj.vcm.currentText()})

			# if self.guiObj.vfm.currentText() == "":
			# 	CLIMessage("Mirror coating | Please choose vfm element", "W")
			# 	return self.WizardPages.editCfg.value
			# else:
			# 	expMetaData.append({"vfm":self.guiObj.vfm.currentText()})

			# if self.guiObj.Mono.currentText() == "":
			# 	CLIMessage("Mirror coating | Please choose the Mono Crystal", "W")
			# 	return self.WizardPages.editCfg.value
			# else:
			# 	expMetaData.append({"Mono":self.guiObj.Mono.currentText()})

			if self.guiObj.userCom.text() == "":
				expMetaData.append({"userCom":"NONE"})
			else:
				expMetaData.append({"userCom":self.guiObj.userCom.text()})

			if self.guiObj.expCom.text() == "":
				expMetaData.append({"expCom":"NONE"})
			else:
				expMetaData.append({"expCom":self.guiObj.expCom.text()})
				
			detectors = []
			ROIs = []
			for d in self.DetectorsGUI.detectors:
				detCheckbox = getattr(self.DetectorsGUI.detectors_UI, d)
				if detCheckbox.isChecked():
					detectors.append(d)
			
			if 'XFLASH' in detectors:
				for roi in self.DetectorsGUI.ROIs:
					Checkbox = getattr(self.DetectorsGUI.detectors_UI, roi)
					if Checkbox.isChecked():
						ROIs.append(roi)

			self.cfg["ExpMetaData"] = expMetaData

			if not detectors:
				return self.WizardPages.editCfg.value

			if 'XFLASH' in detectors and not ROIs:
				CLIMessage("Since XFLASH detector is choosed, at least one ROI should be selected", "W")
				return self.WizardPages.editCfg.value

			return self.WizardPages.startscan.value
		except:
			print ("Check config")
			return self.WizardPages.editCfg.value			
	
	def start(self):
		NIntervals = self.guiObj.setNumofIterv.text()
		if NIntervals == '' or not Common.validate(
				"NIntervals", NIntervals,"Please enter valid Number of INtervals"):
			CLIMessage("Please enter valid Number of intervals", "W")
			return self.WizardPages.editCfg.value
		else:
			self.cfg["NIntervals"] = int(NIntervals)

		Nsamples = self.guiObj.setNumofSamples.text()
		if Nsamples == '' or not Common.validate("Nsample", Nsamples, "Please enter valid Number of Samples"):
			CLIMessage("Please enter a valid number of Samples, and, make sure to click on the Samples button to keep or change the default values","W")
			return self.WizardPages.editCfg.value
		else:
			self.cfg["Nsamples"] = int(Nsamples)

		Nscans = self.guiObj.setNumofScans.text()
		if Nscans == '' or not Common.validate("Nscans", Nscans, "Please enter valid Number of scans"):
			CLIMessage("Pleae enter a valid number of scans", "W")
			return self.WizardPages.editCfg.value
		else:
			self.cfg["Nscans"] = int(Nscans)
		DataFileName = self.cfg["DataFileName"] = self.guiObj.setDataFileName.text()
		if DataFileName == '' or not Common.validate("DataFileName", DataFileName,"Please enter valid data file name"):
			CLIMessage("Please enter a valid data file name","W")
			return self.WizardPages.editCfg.value
		else:
			self.cfg["DataFileName"] = DataFileName

		settlingTime = self.guiObj.settlingTime.text()
		if settlingTime == '' or not Common.regexvalidation("settlingTime", settlingTime):
			CLIMessage("Please enter valid settling time", "W")
			return self.WizardPages.editCfg.value
		else:
			self.cfg["settlingTime"]=float(settlingTime)

		intervals = [{} for i in range(int(NIntervals))]
		for interval in range(self.IntervalsGUI.interval_UI.tableWidget.rowCount()):
			start = self.IntervalsGUI.interval_UI.tableWidget.item(interval, 0).text()
			if start == '' or not Common.validate("Startpoint", start, "Please enter valid start point"):
				CLIMessage("Intervals | Please enter a valid start point", "W")
				return self.WizardPages.editCfg.value
			else:
				intervals[interval]["Startpoint"] = float(start)

			end = self.IntervalsGUI.interval_UI.tableWidget.item(interval,1).text()
			if end == '' or not Common.validate("Endpoint", end, "Please enter valid end point"):
				CLIMessage("Intervals | Please enter a valid end point", "W")
				return self.WizardPages.editCfg.value
			else:
				intervals[interval]["Endpoint"] = float(end)

			stepsize = self.IntervalsGUI.interval_UI.tableWidget.item(interval, 2).text()
			if stepsize == '' or not Common.validate("Stepsize", end, "Please enter valid step size"):
				CLIMessage("Intervals | Please enter a valid step size","W")
				return self.WizardPages.editCfg.value
			else:
				intervals[interval]["Stepsize"] = float(stepsize)

			picoAmmIntTime = self.IntervalsGUI.interval_UI.tableWidget.item(interval, 3).text()
			if picoAmmIntTime == '' or not Common.validate("picoAmmetersIntTime", end,"Please enter valid pico ammeter integration time"):
				CLIMessage("Intervals | Please enter a valid pico ammeter integration time","W")
				return self.WizardPages.editCfg.value
			else:
				# +3 in the line of code below added to compensate the indexing that is in the IOC PV but not in the list self.allowedPicoIntTime
				intervals[interval]["picoAmmIntTime"] = float(picoAmmIntTime)
		SamplePositions = [{} for i in range(int(Nsamples))]
		for sample in range(self.SamplesGUI.sample_UI.samplepositions.rowCount()):
			
			Xposition = self.SamplesGUI.sample_UI.samplepositions.item(sample, 0).text()
			if Xposition == '' or not Common.validate("Xposition", Xposition,"Please enter valid sample x position"):
				CLIMessage("Samples | Please enter a valid sample X position")
				return self.WizardPages.editCfg.value
			else:
				SamplePositions[sample]["Xposition"] = Xposition

			Yposition = self.SamplesGUI.sample_UI.samplepositions.item(sample, 1).text()
			if Yposition == '' or not Common.validate("Yposition", Yposition,"Please enter valid sample y position"):
				CLIMessage("Samples | Please enter a valid sample Y position")
				return self.WizardPages.editCfg.value
			else:
				SamplePositions[sample]["Yposition"] = Yposition

			Zposition = self.SamplesGUI.sample_UI.samplepositions.item(sample, 2).text()
			if Zposition == '' or not Common.validate("Zposition", Zposition,"Please enter valid sample Z position"):
				CLIMessage("Samples | Please enter a valid sample Z position")
				return self.WizardPages.editCfg.value
			else:
				SamplePositions[sample]["Zposition"] = Zposition

			Rot = self.SamplesGUI.sample_UI.samplepositions.item(sample, 3).text()
			if Rot == '' or not Common.validate("Rotation", Rot,"Please enter valid sample rotation position"):
				CLIMessage("Samples | Please enter a valid sample rotation position")
				return self.WizardPages.editCfg.value
			else:
				SamplePositions[sample]["Rotation"] = Rot
			
			sampleTitle = self.SamplesGUI.sample_UI.samplepositions.item(sample, 4).text()
			if sampleTitle == '' or not Common.validate("sampleTitle", sampleTitle,"Please enter valid sample name in the Samples dialog"):
				CLIMessage("Samples | Please enter a valid sample name in the Samples dialog")
				return self.WizardPages.editCfg.value
			else:
				SamplePositions[sample]["sampleTitle"] = sampleTitle
				
		detectors = []
		ROIs = []
		for d in self.DetectorsGUI.detectors:
			detCheckbox = getattr(self.DetectorsGUI.detectors_UI, d)
			if detCheckbox.isChecked():
				detectors.append(d)
		self.cfg["detectors"] = detectors

		if 'XFLASH' in self.cfg['detectors']:
			for roi in self.DetectorsGUI.ROIs:
				ROICheckbox = getattr(self.DetectorsGUI.detectors_UI, roi)
				if ROICheckbox.isChecked():
					ROIs.append(roi)
		self.cfg["ROIs"]=ROIs

		self.cfg["Intervals"] = intervals
		self.cfg["Samplespositions"] = SamplePositions

	def loadcfgfile(self, cfgfilename):
		try:
			with open(cfgfilename, 'r') as cfgfile:
				data = json.load(cfgfile)
				cfgfile.close()
				return data
		except Exception as e:
			print("cfgfile load error")
			print(e)
			sys.exit()


class SamplePosGUI:
	class SampleCols(Enum):
		X	=	0
		Y	=	1
		Z   =   2
		R 	=  	3
		Title = 4

	def __init__(self):
		self.sampleDialog = QtWidgets.QDialog()
		self.sample_UI = samplespositionForm.Ui_Dialog()
		self.sample_UI.setupUi(self.sampleDialog)

	def setSamplesNumber(self, cfg):
		Nsamples = cfg["Nsamples"]
		self.sample_UI.samplepositions.setRowCount(Nsamples)
		"""
		bring default x and y positions 
		"""
		PVs = readFile("pvlist/HESEB.json").readJSON()
		XpositionPV = PVs["Motors"]["SMP:X"]["pvname"]
		YpositionPV = PVs["Motors"]["SMP:Y"]["pvname"] 
		ZpositionPV = PVs["Motors"]["SMP:Z"]["pvname"] 
		RotPV = PVs["Motors"]["SMP:Rot"]["pvname"] 
		if "Samplespositions" in cfg.keys():
			for sample in range(Nsamples):
				sampleTitle = ""
				Xposition = ""
				Yposition = ""
				Zposition = ""
				Rot = ""
				if sample < len(cfg["Samplespositions"]):
					try:
						Xposition = self.sample_UI.samplepositions.item(sample, 0).text()
						Yposition = self.sample_UI.samplepositions.item(sample, 1).text()
						Zposition = self.sample_UI.samplepositions.item(sample, 2).text()
						Rot = self.sample_UI.samplepositions.item(sample, 3).text()
						sampleTitle = self.sample_UI.samplepositions.item(sample, 4).text()
					except:
						print("")
					try:	

						if Xposition == "" or Yposition == "" or Zposition == "" or Rot == "" or sampleTitle =="": # bring x and y values fro the first time from cfg file
							self.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.X.value,QtWidgets.QTableWidgetItem(str(cfg["Samplespositions"][sample]["Xposition"]), 0))
							self.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.Y.value,QtWidgets.QTableWidgetItem(str(cfg["Samplespositions"][sample]["Yposition"]), 0))
							self.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.Z.value,QtWidgets.QTableWidgetItem(str(cfg["Samplespositions"][sample]["Zposition"]), 0))
							self.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.R.value,QtWidgets.QTableWidgetItem(str(cfg["Samplespositions"][sample]["Rotation"]), 0))
							self.sample_UI.samplepositions.setItem(sample, SamplePosGUI.SampleCols.Title.value,QtWidgets.QTableWidgetItem(str(cfg["Samplespositions"][sample]["sampleTitle"]), 0))
					except:
						CLIMessage("Unable to read x, y and z positions (or Sample Name) from the configuration file for "\
							"the sample number {}".format(sample), "W")
		else: 
			CurentXPosition = caget(XpositionPV)
			CurentYPosition = caget(YpositionPV)
			CurentZPosition = caget(ZpositionPV)
			CurentRotPosition = caget(RotPV)
			try: # try to get text for the first interval, ... if not set the curent x y positions 
				XpositionInt0 = self.sample_UI.samplepositions.item(0, 0).text() # x position interval 0
				YpositionInt0 = self.sample_UI.samplepositions.item(0, 1).text() # y position interval 0 
				ZpositionInt0 = self.sample_UI.samplepositions.item(0, 2).text() # Z position interval 0 
				RotInt0 = self.sample_UI.samplepositions.item(0, 3).text() # Z position interval 0 

				if XpositionInt0 == "": 
					self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.X.value,QtWidgets.QTableWidgetItem(str(CurentXPosition), 0))
				if YpositionInt0 == "":
					self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.Y.value,QtWidgets.QTableWidgetItem(str(CurentYPosition), 0))
				if ZpositionInt0 == "":
					self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.Z.value,QtWidgets.QTableWidgetItem(str(CurentZPosition), 0))
				if RotInt0 == "":
					self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.R.value,QtWidgets.QTableWidgetItem(str(CurentRotPosition), 0))

			except:
				self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.X.value,QtWidgets.QTableWidgetItem(str(CurentXPosition), 0))
				self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.Y.value,QtWidgets.QTableWidgetItem(str(CurentYPosition), 0))
				self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.Z.value,QtWidgets.QTableWidgetItem(str(CurentZPosition), 0))
				self.sample_UI.samplepositions.setItem(0, SamplePosGUI.SampleCols.R.value,QtWidgets.QTableWidgetItem(str(CurentRotPosition), 0))


class IntervalGUI:
	class IntervalCols(Enum):
		start	=	0
		end		=	1
		step	=	2
		ICInt	=	3
		GlobalCfg = {} 
		
	def __init__(self):
		self.intervalDialog = QtWidgets.QDialog()
		self.interval_UI = intervalsForm.Ui_Dialog()
		self.interval_UI.setupUi(self.intervalDialog)
		self.interval_UI.buttonBox.clicked.connect(self.saveIntervals)
		self.Intervals = []

	def saveIntervals(self):
		#print ("dffsdfsdfs", len(self.FicusIntTimeDic))
		global GlobalCfg
		#print (GlobalCfg)
		#self.Intervals = [{} for i in range(int(len(self.FicusIntTimeDic)))]
		self.Intervals = [{} for i in range(int(Nintrv))]
		#for interval in range(len(self.FicusIntTimeDic)):
		# CLIMessage("Intervals: {},  len(self.FicusIntTimeDic): {}".format(Nintrv, len(self.FicusIntTimeDic)), "E")
		for interval in range(Nintrv):
			try:
				self.Intervals[interval]["Startpoint"] =   self.interval_UI.tableWidget.item(interval, 0).text()
				self.Intervals[interval]["Endpoint"]   =   self.interval_UI.tableWidget.item(interval, 1).text()
				self.Intervals[interval]["Stepsize"]   =   self.interval_UI.tableWidget.item(interval, 2).text()
				self.Intervals[interval]["picoAmmIntTime"] =   self.interval_UI.tableWidget.item(interval, 3).text()
			except:
				pass
	def setIntervalsNumber(self, cfg):
		
		NIntervals = cfg["NIntervals"]
		global GlobalCfg
		GlobalCfg = cfg
		self.interval_UI.tableWidget.setRowCount(NIntervals)
		if "Intervals" in cfg.keys():
			if len(cfg["Intervals"]) > len(self.Intervals):
				self.Intervals = cfg["Intervals"]
			for interval in range(NIntervals): 
				try:
					self.Intervals[interval]["Startpoint"] = self.interval_UI.tableWidget.item(interval, 0).text()
					self.Intervals[interval]["Endpoint"] = self.interval_UI.tableWidget.item(interval, 1).text()
					self.Intervals[interval]["Stepsize"] = self.interval_UI.tableWidget.item(interval, 2).text()
					self.Intervals[interval]["picoAmmIntTime"] = self.interval_UI.tableWidget.item(interval, 3).text()
					# self.Intervals[interval]["DetIntTime"] = self.FicusIntTimeDic[interval]
				except:
					pass 
			self.interval_UI.tableWidget.clearContents()
			for interval in range(NIntervals):
				if interval < len(self.Intervals):
					if self.Intervals[interval]:
						self.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.start.value,QtWidgets.QTableWidgetItem(str(self.Intervals[interval]["Startpoint"]),0))
						self.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.end.value,QtWidgets.QTableWidgetItem(str(self.Intervals[interval]["Endpoint"]),0))
						self.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.step.value,QtWidgets.QTableWidgetItem(str(self.Intervals[interval]["Stepsize"]),0))
						self.interval_UI.tableWidget.setItem(interval, IntervalGUI.IntervalCols.ICInt.value,QtWidgets.QTableWidgetItem(str(self.Intervals[interval]["picoAmmIntTime"]),0))
class DetectorsGUI:		
	def __init__(self):
		self.detectors = ["KEITHLEY_I0", "KEITHLEY_Itrans", "XFLASH"]
		self.ROIs = ['ROI_0','ROI_1','ROI_2', 'ROI_3', 'ROI_4', 'ROI_5', 'ROI_6', 'ROI_7', 'ROI_8']
		self.detectorsDialog = QtWidgets.QDialog()
		self.detectors_UI = detectorsForm.Ui_Dialog()
		self.detectors_UI.setupUi(self.detectorsDialog)


class SED:
	Header = ['Proposal', 'Title', 'Proposer', 'Email', 'Beamline', 'Begin', 'End', 'Assigned shifts', 'Assigned hours', 'Semester', 'Experimental_Data_Path']

	def init(self, proposalID, paths):
		self.proposalID = proposalID
		self.paths = paths
		todayProposal = os.path.exists("metadata/Scanning_Tool.csv")
		if todayProposal:
			if self.getPropsalData(proposalID):
				return True
			else:
				return False
		else:
			UIMessage("Error reading today's metadata file",
					"Scanning_Tool.csv files is not exist", 
					"Try to start the experiment again, if the problem continues please contact the DCA Group").showCritical()
			CLIMessage("Error reading today's metadata file","E")
	def parsePropsalFile(self, filename):
		data = {}
		ProposalData = csv.reader(open(filename, 'r'))
		header = next(ProposalData)
		if not len(header) == len(SED.Header):
			print("invalid file: missing columns")
			Common.show_message(QtWidgets.QMessageBox.Critical,"Invalid Metadata file: missing columns","HESEB scan tool",QtWidgets.QMessageBox.Ok)
			sys.exit()

		for col_name in header:
			if not col_name in SED.Header:
				print("invalid file: unexpected column(s)")
				Common.show_message(QtWidgets.QMessageBox.Critical,"Invalid Metadata file: unexpected column(s)","HESEB scan tool",QtWidgets.QMessageBox.Ok)
				sys.exit()	

		for col in header:
			data[col] = None

		propsal = next(ProposalData)
		data = dict(zip(header, propsal))
		result , propsal_data = self.validatePropsalData(data)
		if result == True:
			return propsal_data
		else:
			Common.show_message(QtWidgets.QMessageBox.Critical,"Invalid Metadata file: metadata validation failed","HESEB scan tool",QtWidgets.QMessageBox.Ok)
			print(result)
			sys.exit()


	def validatePropsalData(self,propsal):
		propsal_data    = {}
		result = True
		for entry,value in propsal.items():
			if Common.regexvalidation(entry,value):
				propsal_data[entry] = value
			else:
				result = "vaildation error: {}|{}".format(entry,value)
				break
		return result,propsal_data

	def getPropsalData(self,proposal_ID):
		found = None
		if Common.regexvalidation("Proposal", proposal_ID):
			proposal_ID = int(proposal_ID)
			propsal_data = self.parsePropsalFile("metadata/Scanning_Tool.csv")
			if int(propsal_data["Proposal"]) == proposal_ID:
				found = 'ScheduledToday'
			else:
				propsal_data = CSVProposal('metadata/HESEBScheduledProposals.csv', proposal_ID).lookup()
				if not propsal_data == False:
					found = 'NotScheduledToday'
					# print(propsal_data)
					propPath = path(beamline='HESEB', semester = propsal_data['Semester'], proposal = propsal_data['Proposal'], path=self.paths['SED_TOP'])
					propsal_data["Experimental_Data_Path"] = propPath.getPropPath()
					confirmation = UIMessage('HESEB scan tool | proposal is not scheduled for today!!', "The proposal {} is not "\
						"scheduled for today!!. Proposal ID is a unique SED dataset identifier, it is important to make sure that it is your's"\
						" as PI or you are a member in this proposal,"\
						" otherwise, you would not have access to the data associated with this scan.".format(proposal_ID), "Only authorised people (i.e. beamline scientists "\
						"or DCA team members), proposal PI or proposal participant can procceed with this proposal ({}). "\
						" Do you want to continue?".format(proposal_ID)).showYNQuestion()
					if not confirmation:
						return False
					
		else:
			Common.show_message(QtWidgets.QMessageBox.Critical,"invalid proposal ID","HESEB scan tool",QtWidgets.QMessageBox.Ok)
			return False

		if not found == None:
			try:
				UsersinfoFile = open('configrations/userinfo.json','w')
				json.dump(propsal_data,UsersinfoFile, indent=2)
				UsersinfoFile.close()
				PathsFile = open('configrations/paths.json', 'r+')
				PathsFileData = json.load(PathsFile)
				PathsFileData["users_data_path"] = propsal_data["Experimental_Data_Path"]
				PathsFile.close()
				PathsFile = open('configrations/paths.json', 'w')
				json.dump(PathsFileData,PathsFile, indent=2)
				PathsFile.close()
				return True
			except Exception as e:
				Common.show_message(QtWidgets.QMessageBox.Critical,"local configuration files missing","HESEB scan tool",QtWidgets.QMessageBox.Ok)
				return False 
		else:
			Common.show_message(QtWidgets.QMessageBox.Critical,"wrong proposal ID or not scheduled","Proposal ID vedrification",QtWidgets.QMessageBox.Ok)
			return False