
#!/usr/bin/python3
"""
Step energy scan derived class
"""
import time
import threading
import shutil 
import os

from heseb_step import HESEB_XRFSTEP
from SEDSS.CLIMessage import CLIMessage
from xdiWriter import XDIWriter
from SEDSS.SEDFileManager import path
from SEDSS.SEDTransfer import SEDTransfer
from SEDSS.SEDSupport import timeModule 
from SEDSS.SEDTmuxSession import tmuxSession
import log
import glob

class ENGSCAN (HESEB_XRFSTEP):
	def __init__(self, paths, cfg, testingMode = "No"):
		super().__init__(paths, cfg, testingMode)

	def startScan(self):
		counter = 0 
		pauseCounter = 0
		breakTag = 0 
		startTime = time.time()

		self.startScanTime = time.strftime("%H:%M:%S", time.localtime())

		self.PVs["SCAN:Start"].put(self.startScanTime)
		log.info(f"Scan started at: {self.startScanTime}")

		self.clearPlot()

		log.info("Start data collection ...")
		self.PVs["USERINFO:Proposal"].put(self.userinfo["Proposal"])
		self.PVs["USERINFO:Email"].put(self.userinfo["Email"])
		self.PVs["USERINFO:Beamline"].put(self.userinfo["Beamline"])
		self.PVs["USERINFO:StartTime"].put(self.userinfo["Begin"])
		self.PVs["USERINFO:EndTime"].put(self.userinfo["End"])
		points		=	map(lambda intv: self.drange(intv["Startpoint"],intv["Endpoint"],intv["Stepsize"]),self.cfg["Intervals"])
		expData = {} # Experimental Data 

		self.plotting()

		for sample,scan,interval in self.generateScanPoints():
			log.info("Data collection: Sample# {}, Scan# {}, Interval# {}".format(sample, scan, interval))
			self.checkPause()
			print ("#####################################################")
			CLIMessage("Scan# {}".format(scan), "I")
			CLIMessage("Sample# {}".format(sample), "I")
			CLIMessage("Interval# {}".format(interval), "I")
			print ("#####################################################")
			#self.clearPlot()
			# CSS GUI
			self.PVs["SCAN:Nsamples"].put(self.cfg["Nsamples"])
			self.PVs["SCAN:Nscans"].put(self.cfg["Nscans"])
			self.PVs["SCAN:NIntervals"].put(self.cfg["NIntervals"])
			self.PVs["SCAN:CurrentSample"].put(sample)
			self.PVs["SCAN:CurrentScan"].put(scan)
			self.PVs["SCAN:CurrentInterval"].put(interval)
			self.MoveSmpX(self.cfg["Samplespositions"][sample-1]["Xposition"]) # becuase sample starts from 1 
			self.MoveSmpY(self.cfg["Samplespositions"][sample-1]["Yposition"]) # becuase sample starts from 1 
			self.MoveSmpZ(self.cfg["Samplespositions"][sample-1]["Zposition"]) # becuase sample starts from 1 
			currentInterval = self.cfg["Intervals"][interval-1]
			startpoint = currentInterval["Startpoint"]
			endpoint = currentInterval["Endpoint"]
			stepsize = currentInterval["Stepsize"]
			
			picoAmmIntTime = currentInterval["picoAmmIntTime"]
			
			
			points = self.drange(startpoint,endpoint,stepsize)
			# epics.PV("K6487:1:RST.PROC").put(1)
			# epics.PV("K6487:1:Damping").put(0)
			# epics.PV("K6487:1:TimePerSampleStep").put(0)
			for point in points:
				self.checkPause()
				curentScanInfo = []
				curentScanInfo.append({"Sample":sample})
				curentScanInfo.append({"Scan":scan})
				curentScanInfo.append({"Interval":interval})
				curentScanInfo.append({"RINGCurrent":self.PVs["RING:Current"].get()})
				curentScanInfo.append({"sampleTitle":self.cfg["Samplespositions"][sample-1]["sampleTitle"]})

				# tmp, delete the following line 
				curentScanInfo.append({"TargetSP":point})
				self.MovePGM(point, curentScanInfo)
				args= {}
				args["picoAmmIntTime"] = picoAmmIntTime
				ACQdata = {}
				detThreadList = []
				log.info("Prepare a parallel thread for each selected detector")
				for det in self.detectors:
					detThreading = threading.Thread(target=det.ACQ, args=(args,), daemon=True)
					detThreadList.append(detThreading)

				log.info("Start detectors threads")
				for thread in detThreadList: 
					thread.start()

				log.info("Joining the detector threads") 
				for thread in detThreadList:
					thread.join()

				ACQdata={**ACQdata,**det.data}
				log.info("Collecting data from detectors")
				expData.update(ACQdata)
				log.info("Applying post acquisition for selected detectors if applicable")
				for det in self.detectors:
					det.postACQ(ACQdata)
					ACQdata={**ACQdata,**det.data} 
					expData.update(ACQdata)

				Energy	=	self.PVs["PGM:Energy:RBV"].get()
				log.info("reading PGM energy: {}".format (Energy))
				IfDp = 0.0
				AbsorptionFluoDp = 0.0
				AbsorptionTrDp = 0.0
				ACQdata["Sample#"] = sample
				ACQdata["Scan#"] = scan
				ACQdata["Interval"] = interval
				ACQdata["ENERGY-RBK"]	=	Energy
				expData.update(ACQdata)
				I0Dp					=	ACQdata["KEITHLEY_I0"]
				
				if "KEITHLEY_Itrans" in self.cfg["detectors"]:
					ItDp = ACQdata["KEITHLEY_Itrans"]
					AbsorptionTrDp = ItDp / I0Dp

				if "XFLASH" in self.cfg["detectors"]:
					IfDp					=	ACQdata["XFLASH-If"]
					AbsorptionFluoDp		=	ACQdata["XFLASH-FLUOR"]


				self.Energy.append(Energy)
				self.I0.append(I0Dp)
				try:
					self.It.append(ItDp)
				except:
					pass
				self.AbsTr.append(AbsorptionTrDp)
				self.If.append(IfDp)
				self.AbsFlu.append(AbsorptionFluoDp)
				self.setPlotData()

				log.info("Writing data to xdi file")
				
				"""
				(A) Ignore writing the 1st point, and, 
				(B) Ignore writing data during pausing (shutter stoped, curent goes below the limites )
				"""
				if counter == 0 or self.PVs["SCAN:pause"].get()==1:  
					pauseCounter = pauseCounter +1 
					pass
				else:
					XDIWriter(expData, self.localDataPath, self.detChosen, self.creationTime ,self.expStartTimeDF, self.cfg, curentScanInfo)
					
					elapsedScanTime = timeModule.timer(startTime)					
					
					self.PVs["SCAN:Elapse"].put(elapsedScanTime)
					log.info(f"Elapse time scan for scan point ({counter}) is: {elapsedScanTime}")

				counter = counter +1

				self.stopScan = self.PVs["SCAN:Stop"].get()
				if int(self.stopScan) == 1:   # exit from for loop (child) when stop is clicked
					log.warning("Scan tool has been stopped by human action")
					breakTag = 1
					break

			"""
			Transfering the data after each scan 
			"""

			self.dataTransfer()

			if breakTag == 1: 		# exit from for loop (parent) when stop is clicked
				self.stopScanning()

		print("#########################################################################")
		scanTime = timeModule.timer(startTime)
		log.info("Scan is fininshed | actual scan time is: {}, total number of points: {}".format(str(scanTime), counter))
		if pauseCounter > 1:
			log.warning("Ignored points | total number: {}. Check the experiment log file to see what was caused the pausing".format(pauseCounter))
		#CLIMessage("	scan is fininshed :)    Scan time: {}, total number of points: {}".format(str(scanTime), counter), "I")
		print("#########################################################################")
		log.info("Data file folder: {}".format(self.localDataPath))
		CLIMessage("Data file folder: {}".format(self.localDataPath),"M")
		print("#################################################")
		os.rename("SED_Scantool.log", "SEDScanTool_{}.log".format(self.creationTime))
		shutil.move("SEDScanTool_{}.log".format(self.creationTime), "{}/SEDScanTool_{}.log".format(self.localDataPath, self.creationTime))
		self.dataTransfer()
		tmuxSession(self.tmuxSessionToKill).kill()
		self.PVs["SCAN:Stop"].put(1)	# to make the interlock of voltage source
		
	def dataTransfer(self):
		# try:
		# SEDTransfer(self.localDataPath, self.paths["AutoCopyDS"]).scp()
		if self.cfg["expType"] == "proposal":
			SEDTransfer(self.localDataPath, self.paths["DS"]+":"+self.userinfo["Experimental_Data_Path"]).scp()
		else: 
			IHPath = path(self.paths['SED_TOP'], beamline = 'HESEB').getIHPath()
			SEDTransfer(self.localDataPath, self.paths["DS"]+":"+IHPath).scp()
		log.info("Data transfer is done")
		# except:
		# 	log.error("Problem transfering the data")
