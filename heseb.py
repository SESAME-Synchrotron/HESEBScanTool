#!/usr/bin/python3

import config
import csv
import datetime
import decimal
import json
import os
import re
import sys
import time
import itertools
from common import Common
from detectors.ficus import FICUS
from detectors.ketek import KETEK
from detectors.ic import IC
from detectors.keithley_i0 import KEITHLEY_I0
from detectors.keithley_itrans import KEITHLEY_ITRANS
from SEDSS.SEDSupplements import CLIMessage
from SEDSS.SEDSupport import readFile, dataTransfer, timeModule 
from SEDSS.SEDTmuxSession import tmuxSession
# from SEDSS.SEDFileManager import path
# from SEDSS.SEDTransfer import SEDTransfer
import threading
from xdiWriter import XDIWriter
import threading
import log
import shutil 
import signal
import subprocess
import math


try:
	import PyQt5
	import epics
	import numpy as np
except ImportError as e:
	print("Please make sure the following packages are installed:")
	print("PyQt5, epics, numpy")

class HESEB:
	def __init__(self,cfg, testingMode = "No"):
		# 
		#epics.PV("SCAN:STOP").put(0)
		log.setup_custom_logger("./SED_Scantool.log")
		log.info("Start scanning tool")
		self.loadPVS("HESEB")
		self.PVs["SCAN:Stop"].put(0)  			# disable stop function
		self.PVs["SCAN:pause"].put(0) 			# flush scan pause pv 
		self.PVs["Calibration:Energy"].put(1)   # disable I0 vs time plotting
		self.PVs["I0:TRIGGER"].put(1)   		# disable I0 vs time plotting
		self.PVs["It:TRIGGER"].put(1)  		    # disable It vs time plotting
		# self.PVs["Voltage:Validation"].put(0)	# enable voltage source
		# epics.PV("VOLTAGE:VALIDATION").put(0)	# enable voltage source

		self.KeithelyI0PV = readFile("pvlist/KEITHLEY_I0.json").readJSON()
		self.voltageSourcePARAM = []
		# get the values of voltage source parameters before reset 
		self.voltageSourcePARAM.append(epics.PV(self.KeithelyI0PV["PV"]["voltageSourceEnable"]["pvname"]).get())
		self.voltageSourcePARAM.append(epics.PV(self.KeithelyI0PV["PV"]["voltageSourceRange"]["pvname"]).get())
		self.voltageSourcePARAM.append(epics.PV(self.KeithelyI0PV["PV"]["voltageSourceCurrentLimit"]["pvname"]).get())
		self.voltageSourcePARAM.append(epics.PV(self.KeithelyI0PV["PV"]["voltageSourceVoltageRBV"]["pvname"]).get())

		self.paths		= Common.loadjson("configrations/paths.json")
		self.cfg		= cfg
		self.scanLimites = readFile("configrations/limites.json").readJSON()
		#log.info("Experiment configurations: ({})".format(json.dumps(self.cfg, indent=2, sort_keys=True)))
		log.info("Experiment scan limites: ({})".format(json.dumps(self.scanLimites, indent=2, sort_keys=True)))
		CLIMessage(" Confegrations to be implemented: {}".format(self.cfg), "M")
		self.detChosen = None 
		self.userinfo	= Common.loadjson("configrations/userinfo.json")
		self.initPaths()
		self.initPGM()
		self.initDetectors()
		# Set ^C interrupt to abort the scan
		signal.signal(signal.SIGINT, self.signal_handler)

		if testingMode == "No":
			log.info("Testing mode: No")
			self.runPauseMonitor()
		else:
			log.info("Testing mode: Yes")


		self.tmuxSessionToKill = ['voltageSourceValidation', 'I0_startAcquire']
		tmuxSession(self.tmuxSessionToKill).kill()
		
		subprocess.Popen("./voltageSourceValidation.sh")
		self.startScan()

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
		for entry,pvname in JsonPVlist["PV"].items():
			pvname=pvname["pvname"]
			PVobj = epics.PV(pvname)
			if PVobj.get() is None:
				#print("{} : is not connected\n".format(pvname))
				CLIMessage("{} : is not connected".format(pvname), "E")
				DisconnectedPvs.append("{}\n".format(pvname))
			else:
				#print("{} : is connected\n".format(pvname))
				CLIMessage("{} : is connected".format(pvname), "I")
				self.PVs[entry] = PVobj

		for entry,mtrname in JsonPVlist["Motors"].items():
			pvname=mtrname["pvname"]
			MTRobj = epics.Motor(pvname)
			if MTRobj is None:
				#print("{} : is not connected\n".format(pvname))
				CLIMessage("{} : is not connected".format(pvname), "E")
				DisconnectedPvs.append("{}\n".format(pvname))
			else:
				#print("{} : is connected\n".format(pvname))
				CLIMessage("{} : is connected".format(pvname), "I")
				self.motors[entry] = MTRobj

		if len(DisconnectedPvs):
			log.error("Disconnected PVs: {}".format(DisconnectedPvs))
			Common.show_message(PyQt5.QtWidgets.QMessageBox.Critical,"The following PVs are disconnected:\n {}".format(" ".join(DisconnectedPvs)),"scan tool" ,PyQt5.QtWidgets.QMessageBox.Ok)
			sys.exit() 		
						
	def initPaths(self):
		log.info("Paths initialization")
		self.creationTime = str(time.strftime("%Y%m%dT%H%M%S"))
		self.BasePath			=	"{}/{}-{}".format(self.paths["local_data_path"],self.cfg["DataFileName"],self.creationTime)
		self.cfgfilepath		=	"{}/{}_config_{}.cfg".format(self.BasePath,self.cfg["DataFileName"],self.creationTime) 
		self.localDataPath		=   "{}".format(self.BasePath)
		#self.PVs["SCAN:Path"].put(self.localDataPath)

		if not os.path.exists(self.BasePath):
			log.info("Create base directory: {}".format(self.BasePath))
			os.makedirs(self.BasePath)
		
		with open(self.cfgfilepath,'w') as cfgfile:
			json.dump(self.cfg,cfgfile)
			cfgfile.close()

		self.dataFileName	=	"{}-{}.dat".format(self.cfg["DataFileName"], str(datetime.datetime.now()))
		self.dataFileFullPath		=	"{}/{}".format(self.localDataPath, self.dataFileName)
		self.expStartTimeDF = str(time.strftime("%Y-%m-%dT%H:%M:%S")) # to be added to xdi file as a content

		"""
		Writing the data path into file to be available to the plotting tool. 
		"""
		with open("./tmp/SEDPath.txt",'w') as SEDPath:
			SEDPath.write(self.localDataPath)
			SEDPath.close()

		if not os.path.exists(self.localDataPath): 
			os.makedirs(self.localDataPath)
	
	def drange(self,start,stop,step,prec=10):
		log.info("Calculating energy points")
		decimal.getcontext().prec = prec
		points = []
		r= decimal.Decimal(start)
		step = decimal.Decimal(step)
		while r <=stop:
			points.append(float(r))
			r += step
		return points
	
	def generateScanPoints(self):
		log.info("Calculating samples, scans and Intervals")
		Samples		=	range(1,self.cfg["Nsamples"]+1)
		Scans		=	range(1,self.cfg["Nscans"]+1)
		Intervals	=	range(1,self.cfg["NIntervals"]+1)
		return itertools.product(Samples,Scans,Intervals)    	

	def initPGM(self):
		log.info("PGM initialization")
		self.PVs["SCAN:pause"].put(0, wait=True) # set pause flag to Fales 
		self.motors["PGM:Grating"].put("stop_go",0) # Stop
		time.sleep(0.1)
		self.motors["PGM:Grating"].put("stop_go",3) # Go
		time.sleep(0.1)
		self.motors["PGM:M2"].put("stop_go",0) # Stop
		time.sleep(0.1)
		self.motors["PGM:M2"].put("stop_go",3) # Go
		time.sleep(0.1)

		self.PVs["PGM:Energy:Reached"].put(1, wait = True)
		self.energy0 = self.cfg["Intervals"][0]["Startpoint"]
		log.info("Move PGM to initial energy ({})".format(self.energy0))
		self.MovePGM(self.energy0)

			
	def MoveSmpX(self,SP):
		log.info("Move sample X to: {}".format(SP))
		self.motors["SMP:X"].put("stop_go",3) # Go
		self.motors["SMP:X"].move(SP)
		time.sleep(1) 
		while not self.motors["SMP:X"].done_moving:
			CLIMessage("sample X moving ...", "IG")
			time.sleep(1)
	
	def MoveSmpY(self,SP):
		log.info("Move sample Y to: {}".format(SP))
		self.motors["SMP:Y"].put("stop_go",3) # Go
		self.motors["SMP:Y"].move(SP)
		time.sleep(1) 
		while not self.motors["SMP:Y"].done_moving:
			CLIMessage("sample Y moving ...", "IG")
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
		self.PVs["PLOT:Energy"].put(self.Energy)
		self.PVs["PLOT:I0"].put(self.I0)
		self.PVs["PLOT:It"].put(self.It)
		self.PVs["PLOT:It2"].put(self.It2)
		self.PVs["PLOT:AbsTr"].put(self.AbsTr)
		self.PVs["PLOT:AbsTr2"].put(self.AbsTr2)
		self.PVs["PLOT:If"].put(self.If)
		self.PVs["PLOT:AbsFlu"].put(self.AbsFlu)
	
	def setPlotData(self):
		log.info("Setting plots data")
		self.PVs["PLOT:Energy"].put(self.Energy)
		self.PVs["PLOT:I0"].put(self.I0)
		self.PVs["PLOT:It"].put(self.It)
		self.PVs["PLOT:It2"].put(self.It2)
		self.PVs["PLOT:AbsTr"].put(self.AbsTr[1:])
		self.PVs["PLOT:AbsTr2"].put(self.AbsTr2)
		self.PVs["PLOT:If"].put(self.If)
		self.PVs["PLOT:AbsFlu"].put(self.AbsFlu)

	def checkPause(self):
		diffTime = 0 
		pauseFlag = 0 
		startTime = time.time()
		while self.PVs["SCAN:pause"].get():
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
		KeithelyI0OK = True
		ringLowerCurrent = self.scanLimites["SRLowerCurrent"] 
		ringUpperCurrent = self.scanLimites["SRUpperCurrent"]
		KeithelyI0LowerLimit = self.scanLimites["KEITHELY_I0LowerRBV"]

		#reading detectors PVs
		KeithelyI0ReadOut = epics.PV(self.KeithelyI0PV["PV"]["picoAmmeterI0AcqReadOut"]["pvname"])
		
		"""
		setup writing flages to avoid continues writing logs in the log file
		"""
		currentLogFlag = 0
		photonShutterLogFlag = 0
		radiationShutterLogFlag = 0
		KeithelyI0LogFlag = 0
		
		while True:
			photonShutterStatus = self.PVs["photonShutter:Status"].get()
			radiationShutterStatus = self.PVs["radiationShutter:Status"].get()
			#StopperStatus = self.PVs["STOPPER:Status"].get()
			currentCurrent = self.PVs["RING:Current"].get()
			KeithelyI0ReadOut = epics.PV(self.KeithelyI0PV["PV"]["picoAmmeterI0AcqReadOut"]["pvname"]).get()

			################### Check current parameters ###############
			if ringLowerCurrent <= currentCurrent <= ringUpperCurrent:
				currentOk = True
				if currentLogFlag == 1: 
					log.warning("SR current is returned to allowed limites, now it is: {} mA."
						.format(currentCurrent))
					currentLogFlag = 0
			else:
				currentOk = False
				if currentLogFlag == 0:
					log.warning("Scan is paused | SR current is: {} mA.".format(currentCurrent))
					currentLogFlag = 1

			################### Check photonShutter parameters ###############
			#print (self.PVs["photonShutter:Status"].get())
			if photonShutterStatus == 1: # shutter is open 1, undefined 0, 2 closed, 3 interlocked 
				photonShutterOk = True
				if photonShutterLogFlag == 1: 
					log.warning("Photon Shutter status is returned to allowed limites, now it is: open")
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
					log.warning("Radiation shutter status is returned to allowed limites, now it is: open")
					radiationShutterLogFlag =0
			else:
				radiationShutterOk = False
				if radiationShutterLogFlag == 0:
					log.warning("Scan is paused | Radiation shutter status is: closed")
					radiationShutterLogFlag = 1

			#################### Check ROIs if current, shutters and stopper are okay ###############
			if currentOk and photonShutterOk and radiationShutterOk  == True:
				#################### Check Keithely_I0 ####################
				if KeithelyI0ReadOut >= KeithelyI0LowerLimit:
					KeithelyI0OK = True
					if KeithelyI0LogFlag == 1: 
						log.warning("Keithely_I0 value is returned to allowed limites, it is now {}"
							.format(KeithelyI0ReadOut))
						KeithelyI0LogFlag = 0
				else:
					KeithelyI0OK = False
					if KeithelyI0LogFlag == 0: 
						log.warning("Scan is paused | Keithely_I0 readout({}) is below the allowed limit ({})"
							.format(KeithelyI0ReadOut,KeithelyI0LowerLimit))
						KeithelyI0LogFlag = 1

			# if any of below is false, pause the scan 
			if False in (currentOk, photonShutterOk, radiationShutterOk, KeithelyI0OK): 
				self.PVs["SCAN:pause"].put(1) # 1 pause, 0 release
			else:
				self.PVs["SCAN:pause"].put(0)
			time.sleep(self.scanLimites["checkLimitesEvery"]) # time in seconds 
	
	def stopScanning(self):
		
		self.PVs["SCAN:Stop"].put(1)	# to make the interlock of voltage source
		self.PVs["PGM:Energy:Reached"].put(1, wait=True)
		log.warning("Stop button has been pressed, runinig scan is terminated !!")
		os.rename("SED_Scantool.log", "SEDScanTool_{}.log".format(self.creationTime))
		shutil.move("SEDScanTool_{}.log".format(self.creationTime), "{}/SEDScanTool_{}.log".format(self.localDataPath, self.creationTime))
		self.dataTransfer()
		sys.exit()

	def initDetectors(self):
		#self.available_detectors = ["IC1","IC2","IC3","KETEK","FICUS"]
		log.info("Detectors initialization")
		self.available_detectors = ["IC","KETEK","FICUS"]
		self.Ingtime = [0.005, 0.0075, 0.01, 0.025, 0.05, 0.075, 0.1, 0.25, 0.5, 0.75, 1, 2.5, 5, 7.5, 10]
		self.detectors = []
		detlist = self.cfg["detectors"]
		log.info("Chosen detectors are {}".format(detlist))
		self.detChosen = detlist
		for det in detlist:
			if det in ("IC1", "IC2", "IC3"):
				cfg={}
				self.detectors.append(IC("IC", self.paths))
			elif det == "KETEK":
				self.detectors.append(KETEK("KETEK",self.paths))
			elif det == "FICUS":
				self.detectors.append(FICUS("FICUS",self.paths,self.userinfo))
			elif det == "KEITHLEY_I0":
				self.detectors.append(KEITHLEY_I0("KEITHLEY_I0",self.paths,self.userinfo,self.voltageSourcePARAM))
			elif det == "KEITHLEY_Itrans":
				self.detectors.append(KEITHLEY_ITRANS("KEITHLEY_ITRANS",self.paths,self.userinfo))
			elif not det in self.available_detectors:
				raise Exception("Unknown detector")
				log.error("Unknown detector is Chosen")

	def plotting(self):
		#################### Plotting ####################
		if "KEITHLEY_Itrans" in self.cfg["detectors"]:
			plotting = self.paths["HESEB_ScanTool_I0_It"]
			log.info("HESEB_ScanTool_I0_It started")
		
		else:
			plotting = self.paths["HESEB_ScanTool_I0"]
			log.info("HESEB_ScanTool_I0 started")
		
		self.plot = plotting
		subprocess.Popen(self.plot)


	def signal_handler(self, sig, frame):
		"""Calls abort_scan when ^C is typed"""
		if sig == signal.SIGINT:
			self.PVs["SCAN:Stop"].put(1)	# to make the interlock of voltage source
			self.PVs["PGM:Energy:Reached"].put(1, wait=True)
			log.warning("Ctrl + C (^C) has been pressed, runinig scan is terminated !!")
			os.rename("SED_Scantool.log", "SEDScanTool_{}.log".format(self.creationTime))
			shutil.move("SEDScanTool_{}.log".format(self.creationTime), "{}/SEDScanTool_{}.log".format(self.localDataPath, self.creationTime))
			self.dataTransfer()
			sys.exit()
