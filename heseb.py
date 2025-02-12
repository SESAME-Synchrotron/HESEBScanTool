#!/usr/bin/python3

import os
import sys
import time
import datetime
import shutil
import signal
import subprocess
import decimal
import json
import threading
import PyQt5
import epics
import itertools

import log
from common import Common
from detectors.keithley_i0 import KEITHLEY_I0
from detectors.keithley_itrans import KEITHLEY_ITRANS
from detectors.xflash import XFLASH
from SEDSS.SEDSupplements import CLIMessage
from SEDSS.SEDSupport import readFile
from SEDSS.SEDTransfer import SEDTransfer
from SEDSS.SEDFileManager import path

class HESEB:
	def __init__(self, cfg, testingMode="No"):
		log.setup_custom_logger("./SED_Scantool.log")
		log.info("Start scanning tool")
		self.loadPVS("HESEB")
		self.testingMode = testingMode.strip().capitalize()
		self.PVs["ScanPause"].put(0)
		self.PVs["CalibrationEnergy"].put(1)
		self.PVs["I0Trigger"].put(0)   		# disable I0 vs time plotting
		self.PVs["ItTrigger"].put(0)  		# disable It vs time plotting

		self.grating = "I11R1-MO-MC2:OH-GRATING-STP-ROTX"
		self.gratingRBV   = epics.PV(self.grating + ".RBV")
		self.gratingVal   = epics.PV(self.grating + ".VAL")
		self.gratingVelo  = epics.PV(self.grating + ".VELO")
		self.gratingSpeed = epics.PV(self.grating + ".VMAX")

		self.m2 = "I11R1-MO-MC2:OH-M2-STP-ROTX"
		self.m2RBV   = epics.PV(self.m2 + ".RBV")
		self.m2Val   = epics.PV(self.m2 + ".VAL")
		self.m2Velo  = epics.PV(self.m2 + ".VELO")
		self.m2Speed = epics.PV(self.m2 + ".VMAX")

		self.KeithelyI0PV = readFile("pvlist/KEITHLEY_I0.json").readJSON()
		KeithelyItransPV = readFile("pvlist/KEITHLEY_ITRANS.json").readJSON()
		self.voltageSourcePARAM = []
		# get the values of voltage source parameters before reset
		self.voltageSourcePARAM.append(bool(epics.PV(KeithelyItransPV["PV"]["voltageSourceEnableRBV"]["pvname"]).get(timeout=1, use_monitor=False)))
		self.voltageSourcePARAM.append(int(epics.PV(KeithelyItransPV["PV"]["voltageSourceRangeRBV"]["pvname"]).get(timeout=1, use_monitor=False)))
		self.voltageSourcePARAM.append(float(epics.PV(KeithelyItransPV["PV"]["voltageSourceCurrentLimitRBV"]["pvname"]).get(timeout=1, use_monitor=False)))
		self.voltageSourcePARAM.append(float(epics.PV(KeithelyItransPV["PV"]["voltageSourceVoltageRBV"]["pvname"]).get(timeout=1, use_monitor=False)))

		self.paths		= Common.loadjson("configurations/paths.json")
		self.cfg		= cfg
		self.scanLimits = readFile("configurations/limits.json").readJSON()
		log.info("Experiment scan limits: ({})".format(json.dumps(self.scanLimits, indent=2, sort_keys=True)))
		CLIMessage("Configurations to be implemented: {}".format(self.cfg), "M")
		self.detChosen = None
		self.userinfo = Common.loadjson("configurations/userinfo.json")
		self.initPaths()
		self.initPGM()
		self.initDetectors()

		signal.signal(signal.SIGINT, self.signal_handler)

		if self.testingMode == "No":
			log.info("Testing mode: No")
			self.runPauseMonitor()
		else:
			log.info("Testing mode: Yes")

	def runPauseMonitor(self):
		log.info("start pause trigger monitor")
		PauseMonitorThread = threading.Thread(target=self.pauseTrigger, args=(), daemon=True)
		PauseMonitorThread.start()

	def loadPVS(self,name):
		log.info("load PVs")
		JsonPVlist = Common.loadjson("pvlist/{}.json".format(name))
		self.PVs = {}
		self.motors = {}
		DisconnectedPvs = []
		for entry, pvname in JsonPVlist["PV"].items():
			pvname = pvname["pvname"]
			PVobj = epics.PV(pvname)
			if PVobj.get() is None:
				CLIMessage("{}: is not connected".format(pvname), "E")
				DisconnectedPvs.append("{}\n".format(pvname))
			else:
				CLIMessage("{}: is connected".format(pvname), "I")
				self.PVs[entry] = PVobj

		for entry, mtrname in JsonPVlist["Motors"].items():
			pvname = mtrname["pvname"]
			MTRobj = epics.Motor(pvname)
			if MTRobj is None:
				CLIMessage("{}: is not connected".format(pvname), "E")
				DisconnectedPvs.append("{}\n".format(pvname))
			else:
				CLIMessage("{}: is connected".format(pvname), "I")
				self.motors[entry] = MTRobj

		if len(DisconnectedPvs):
			log.error("Disconnected PVs: {}".format(DisconnectedPvs))
			Common.show_message(PyQt5.QtWidgets.QMessageBox.Critical,"The following PVs are disconnected:\n {}".format(" ".join(DisconnectedPvs)),"scan tool", PyQt5.QtWidgets.QMessageBox.Ok)
			sys.exit()

	def initPaths(self):
		log.info("Paths initialization")
		self.creationTime = str(time.strftime("%Y%m%dT%H%M%S"))
		self.BasePath			=	"{}/{}-{}".format(self.paths["local_data_path"], self.cfg["DataFileName"], self.creationTime)
		self.cfgFilePath		=	"{}/{}_config_{}.cfg".format(self.BasePath, self.cfg["DataFileName"], self.creationTime)
		self.localDataPath		=   "{}".format(self.BasePath)

		if not os.path.exists(self.BasePath):
			log.info("Create base directory: {}".format(self.BasePath))
			os.makedirs(self.BasePath)

		with open(self.cfgFilePath, 'w') as cfgFile:
			json.dump(self.cfg, cfgFile)
			cfgFile.close()

		self.dataFileName =	"{}-{}.dat".format(self.cfg["DataFileName"], str(datetime.datetime.now()))
		self.dataFileFullPath =	"{}/{}".format(self.localDataPath, self.dataFileName)
		self.h5FileName 	=   "{}-{}".format(self.cfg["DataFileName"], self.creationTime)
		self.expStartTimeDF = str(time.strftime("%Y-%m-%dT%H:%M:%S")) # to be added to xdi file as a content
		self.PVs["SEDPath"].put(self.localDataPath)
		if not os.path.exists(self.localDataPath):
			os.makedirs(self.localDataPath)

	def drange(self, start, stop, step, prec=10):
		log.info("Calculating energy points")
		decimal.getcontext().prec = prec
		points = []
		r = decimal.Decimal(start)
		step = decimal.Decimal(step)
		while r <= stop:
			points.append(float(r))
			r += step
		return points

	def generateScanPoints(self):
		log.info("Calculating samples, scans and Intervals")
		Samples		=	range(1, self.cfg["Nsamples"]+1)
		Scans		=	range(1, self.cfg["Nscans"]+1)
		Intervals	=	range(1, self.cfg["NIntervals"]+1)
		return itertools.product(Samples, Scans, Intervals)

	def initPGM(self):
		log.info("PGM initialization")
		self.PVs["ScanPause"].put(0, wait=True) # set pause flag to False
		self.motors["PGM:Grating"].put("stop_go", 0) # Stop
		time.sleep(0.1)
		self.motors["PGM:Grating"].put("stop_go", 3) # Go
		time.sleep(0.1)
		self.gratingVelo.put(float(self.gratingSpeed.get()))
		self.m2Velo.put(float(self.m2Speed.get()))
		time.sleep(0.1)
		self.motors["PGM:M2"].put("stop_go", 0) # Stop
		time.sleep(0.1)
		self.motors["PGM:M2"].put("stop_go", 3) # Go
		time.sleep(0.1)

		self.PVs["PGM:Energy:Reached"].put(1, wait=True)
		if self.cfg['scanType'] != 'stepMapScan':
			self.energy0 = self.cfg["Intervals"][0]["Startpoint"]
			log.info("Move PGM to initial energy ({})".format(self.energy0))
			self.MovePGM(self.energy0)

	def MoveSmpX(self, SP):
		log.info("Move sample X to: {}".format(SP))
		self.motors["SMP:X"].put("stop_go",3) # Go
		self.motors["SMP:X"].move(SP)
		time.sleep(1)
		while not self.motors["SMP:X"].done_moving:
			CLIMessage("sample X moving ...", "IG")
			time.sleep(1)

	def MoveSmpY(self,SP):
		log.info("Move sample Y to: {}".format(SP))
		self.motors["SMP:Y"].put("stop_go", 3) # Go
		self.motors["SMP:Y"].move(SP)
		time.sleep(1)
		while not self.motors["SMP:Y"].done_moving:
			CLIMessage("sample Y moving ...", "IG")
			time.sleep(1)

	def MoveSmpZ(self, SP):
		log.info("Move sample Z to: {}".format(SP))
		self.motors["SMP:Z"].put("stop_go", 3) # Go
		self.motors["SMP:Z"].move(SP)
		time.sleep(1)
		while not self.motors["SMP:Z"].done_moving:
			CLIMessage("sample Z moving ...", "IG")
			time.sleep(1)

	def MoveSmpRot(self,SP):
		log.info("Move sample rotation to: {}".format(SP))
		self.motors["SMP:Rot"].put("stop_go", 3) # Go
		self.motors["SMP:Rot"].move(SP)
		time.sleep(1)
		while not self.motors["SMP:Rot"].done_moving:
			CLIMessage("sample Rotation moving ...", "IG")
			time.sleep(1)

	def clearPlot(self):
		log.info("Clear plots PVs and parameters")
		self.Energy	= []
		self.I0		= []
		self.It		= []
		self.It2	= []
		self.AbsTr	= []
		self.AbsTr2	= []
		self.If		= []
		self.AbsFlu	= []
		self.ROI0	= []
		self.ROI1	= []
		self.ROI2	= []
		self.ROI3	= []
		self.ROI4	= []
		self.ROI5	= []
		self.ROI6	= []
		self.ROI7	= []
		self.PVs["Plot:Energy"].put(self.Energy)
		self.PVs["Plot:I0"].put(self.I0)
		self.PVs["Plot:It"].put(self.It)
		self.PVs["Plot:It2"].put(self.It2)
		self.PVs["Plot:AbsTr"].put(self.AbsTr)
		self.PVs["Plot:AbsTr2"].put(self.AbsTr2)
		self.PVs["Plot:If"].put(self.If)
		self.PVs["Plot:ROI0"].put(self.ROI0)
		self.PVs["Plot:ROI1"].put(self.ROI1)
		self.PVs["Plot:ROI2"].put(self.ROI2)
		self.PVs["Plot:ROI3"].put(self.ROI3)
		self.PVs["Plot:ROI4"].put(self.ROI4)
		self.PVs["Plot:ROI5"].put(self.ROI5)
		self.PVs["Plot:ROI6"].put(self.ROI6)
		self.PVs["Plot:ROI7"].put(self.ROI7)

	def setPlotData(self):
		log.info("Setting plots data")
		self.PVs["Plot:Energy"].put(self.Energy)
		self.PVs["Plot:I0"].put(self.I0)
		self.PVs["Plot:It"].put(self.It)
		self.PVs["Plot:It2"].put(self.It2)
		self.PVs["Plot:AbsTr"].put(self.AbsTr[1:])
		self.PVs["Plot:AbsTr2"].put(self.AbsTr2)
		self.PVs["Plot:If"].put(self.If)
		self.PVs["Plot:AbsFlu"].put(self.AbsFlu)
		self.PVs["Plot:ROI0"].put(self.ROI0)
		self.PVs["Plot:ROI1"].put(self.ROI1)
		self.PVs["Plot:ROI2"].put(self.ROI2)
		self.PVs["Plot:ROI3"].put(self.ROI3)
		self.PVs["Plot:ROI4"].put(self.ROI4)
		self.PVs["Plot:ROI5"].put(self.ROI5)
		self.PVs["Plot:ROI6"].put(self.ROI6)
		self.PVs["Plot:ROI7"].put(self.ROI7)

	def checkPause(self):
		diffTime = 0
		pauseFlag = 0
		startTime = time.time()
		while self.PVs["ScanPause"].get():
			pauseFlag = 1
			diffTime = time.time() - startTime
			CLIMessage("Scan is paused | pausing time(sec): {}".format(diffTime), "IO")
			time.sleep(0.1)

		if pauseFlag == 1:
			log.warning("Scan was paused | pausing time(sec): %f ", diffTime)

	def pauseTrigger(self):
		currentOk = True
		photonShutterOk = True
		radiationShutterOk = True
		GV6OK = True
		KeithelyI0OK = True
		ringLowerCurrent = self.scanLimits["SRLowerCurrent"]
		ringUpperCurrent = self.scanLimits["SRUpperCurrent"]
		KeithelyI0LowerLimit = self.scanLimits["KEITHELY_I0LowerRBV"]
		KeithelyI0ReadOutPV = epics.PV(self.KeithelyI0PV["PV"]["picoAmmeterI0AcqReadOut"]["pvname"])

		"""
		setup writing flags to avoid continues writing logs in the log file
		"""
		currentLogFlag = 0
		photonShutterLogFlag = 0
		radiationShutterLogFlag = 0
		GV6LogFlag = 0
		KeithelyI0LogFlag = 0

		while True:
			photonShutterStatus = self.PVs["photonShutter:Status"].get()
			radiationShutterStatus = self.PVs["radiationShutter:Status"].get()
			GV6Status = self.PVs["GV6:Status"].get()
			currentCurrent = self.PVs["RING:Current"].get()
			KeithelyI0ReadOut = KeithelyI0ReadOutPV.get()

			################### Check current parameters ###############
			if ringLowerCurrent <= currentCurrent <= ringUpperCurrent:
				currentOk = True
				if currentLogFlag == 1:
					log.warning("SR current is returned to allowed limits, now it is: {} mA."
						.format(currentCurrent))
					currentLogFlag = 0
			else:
				currentOk = False
				if currentLogFlag == 0:
					log.warning("Scan is paused | SR current is: {} mA.".format(currentCurrent))
					currentLogFlag = 1

			################### Check photonShutter parameters ###############
			if photonShutterStatus == 1: # shutter is open 1, undefined 0, 2 closed, 3 interlocked
				photonShutterOk = True
				if photonShutterLogFlag == 1:
					log.warning("Photon Shutter status is returned to allowed limits, now it is: open")
					photonShutterLogFlag = 0
			else:
				photonShutterOk = False
				if photonShutterLogFlag == 0:
					log.warning("Scan is paused | Photon shutter status is: closed")
					photonShutterLogFlag = 1

			################### Check radiationShutter parameters ###############
			if radiationShutterStatus == 1: # shutter is open 1, undefined 0, 2 closed, 3 interlocked
				radiationShutterOk = True
				if radiationShutterLogFlag == 1:
					log.warning("Radiation shutter status is returned to allowed limits, now it is: open")
					radiationShutterLogFlag = 0
			else:
				radiationShutterOk = False
				if radiationShutterLogFlag == 0:
					log.warning("Scan is paused | Radiation shutter status is: closed")
					radiationShutterLogFlag = 1

			################### Check GV6 parameters ###############
			if GV6Status == 3: # GV6 is open 3, 1 closed
				GV6OK = True
				if GV6LogFlag == 1:
					log.warning("GV6 status is returned to allowed limits, now it is: open")
					GV6LogFlag = 0
			else:
				GV6OK = False
				if GV6LogFlag == 0:
					log.warning("Scan is paused | GV6 status is: closed")
					GV6LogFlag = 1

			#################### Check ROIs if current, shutters and stopper are okay ###############
			if currentOk and photonShutterOk and radiationShutterOk and GV6OK  == True:
				#################### Check Keithely_I0 ####################
				if KeithelyI0ReadOut >= KeithelyI0LowerLimit:
					KeithelyI0OK = True
					if KeithelyI0LogFlag == 1:
						log.warning("Keithely_I0 value is returned to allowed limits, it is now {}"
							.format(KeithelyI0ReadOut))
						KeithelyI0LogFlag = 0
				else:
					KeithelyI0OK = False
					if KeithelyI0LogFlag == 0:
						log.warning("Scan is paused | Keithely_I0 readout({}) is below the allowed limit ({})"
							.format(KeithelyI0ReadOut,KeithelyI0LowerLimit))
						KeithelyI0LogFlag = 1

			# if any of below is false, pause the scan
			if False in (currentOk, photonShutterOk, radiationShutterOk, GV6OK, KeithelyI0OK):
				self.PVs["ScanPause"].put(1) # 1 pause, 0 release
			else:
				self.PVs["ScanPause"].put(0)
			time.sleep(self.scanLimits["checkLimitsEvery"]) # time in seconds

	def stopScanning(self):
		self.PVs["ScanStop"].put(1)	# to make the interlock of voltage source
		self.PVs["PGM:Energy:Reached"].put(1, wait=True)
		log.warning("Stop button has been pressed, running scan is terminated!!")
		os.rename("SED_Scantool.log", "SEDScanTool_{}.log".format(self.creationTime))
		shutil.move("SEDScanTool_{}.log".format(self.creationTime), "{}/SEDScanTool_{}.log".format(self.localDataPath, self.creationTime))
		self.dataTransfer()
		sys.exit()

	def initDetectors(self):
		log.info("Detectors initialization")
		self.available_detectors = ["IC", "XFLASH"]
		self.detectors = []
		detlist = self.cfg["detectors"]
		log.info("Chosen detectors are {}".format(detlist))
		self.detChosen = detlist
		for det in detlist:
			if det == "XFLASH":
				self.detectors.append(XFLASH("XFLASH", self.paths, self.cfg | self.userinfo))
			elif det == "KEITHLEY_I0":
				self.detectors.append(KEITHLEY_I0("KEITHLEY_I0", self.paths, self.userinfo))
			elif det == "KEITHLEY_Itrans":
				self.detectors.append(KEITHLEY_ITRANS("KEITHLEY_ITRANS", self.paths, self.userinfo, self.voltageSourcePARAM))
			elif not det in self.available_detectors:
				raise Exception("Unknown detector")

	def plotting(self):
		#################### Plotting GUIs ####################
		plotList = []
		if "KEITHLEY_Itrans" in self.cfg["detectors"]:
			plottingGUI = self.paths["HESEB_ScanTool_I0_It"]
			plotList.append(plottingGUI)
			log.info("HESEB_ScanTool_I0_It plotting started")
		else:
			plottingGUI = self.paths["HESEB_ScanTool_I0"]
			plotList.append(plottingGUI)
			log.info("HESEB_ScanTool_I0 started")

		if "XFLASH" in self.cfg["detectors"]:
			plottingGUI = self.paths["HESEB_ScanTool_XFLASH"]
			plotList.append(plottingGUI)
			log.info("HESEB_ScanTool_XFLASH plotting started")

		for plotGUI in plotList:
			subprocess.Popen(plotGUI)

	def dataTransfer(self):
		if self.testingMode == "Yes":
			SEDTransfer(self.localDataPath, self.paths["DS"] + ":" + self.paths["SED_TOP"] + "/" + self.paths["SED_Test"]).scp()
		else:
			try:
				if self.cfg["expType"] == "proposal":
					SEDTransfer(self.localDataPath, self.paths["DS"] + ":" + self.userinfo["Experimental_Data_Path"]).scp()
				else: 
					IHPath = path(self.paths["SED_TOP"], beamline = "HESEB").getIHPath()
					SEDTransfer(self.localDataPath, self.paths["DS"] + ":" + IHPath).scp()
				log.info("Data transfer is done")
			except:
				log.error("Problem transferring the data")

	def signal_handler(self, sig, frame):
		""" Calls abort_scan when ^C is typed """
		if sig == signal.SIGINT:
			self.PVs["ScanStop"].put(1)	# to make the interlock of voltage source
			self.PVs["PGM:Energy:Reached"].put(1, wait=True)
			log.warning("Ctrl + C (^C) has been pressed, running scan is terminated!!")
			os.rename("SED_Scantool.log", "SEDScanTool_{}.log".format(self.creationTime))
			shutil.move("SEDScanTool_{}.log".format(self.creationTime), "{}/SEDScanTool_{}.log".format(self.localDataPath, self.creationTime))
			self.dataTransfer()
			sys.exit()
