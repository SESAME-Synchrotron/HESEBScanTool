
#!/usr/bin/python3
"""
Continuous energy scan derived class
"""
import os
import time
import threading
import shutil 
import decimal

import log
from heseb_cont import HESEB_CONT
from SEDSS.CLIMessage import CLIMessage
from xdiWriter import XDIWriter
from SEDSS.SEDSupport import timeModule 
from SEDSS.SEDTmuxSession import tmuxSession
# from ROIs import ROIs

class ENGSCANCONT(HESEB_CONT):
	def __init__(self, paths, cfg, testingMode = "No"):
		super().__init__(paths, cfg, testingMode)
		self.lock = False

	def startScan(self):
		counter = 0 
		pauseCounter = 0
		breakTag = 0 
		startTime = time.time()

		# allROIs = ROIs()
		# allROIs.create("ROIs.xdi")

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
		points = map(lambda intv: self.drange(intv["Startpoint"], intv["Endpoint"], intv["Stepsize"]), self.cfg["Intervals"])
		expData = {} # Experimental Data 

		self.plotting()

		for sample, scan, interval in self.generateScanPoints():
			log.info("Data collection: Sample# {}, Scan# {}, Interval# {}".format(sample, scan, interval))
			self.checkPause()
			print("#####################################################")
			CLIMessage("Scan# {}".format(scan), "I")
			CLIMessage("Sample# {}".format(sample), "I")
			CLIMessage("Interval# {}".format(interval), "I")
			print("#####################################################")

			self.PVs["SCAN:Nsamples"].put(self.cfg["Nsamples"])
			self.PVs["SCAN:Nscans"].put(self.cfg["Nscans"])
			self.PVs["SCAN:NIntervals"].put(self.cfg["NIntervals"])
			self.PVs["SCAN:CurrentSample"].put(sample)
			self.PVs["SCAN:CurrentScan"].put(scan)
			self.PVs["SCAN:CurrentInterval"].put(interval)

			self.MoveSmpX(self.cfg["Samplespositions"][sample-1]["Xposition"]) # becuase sample starts from 1 
			self.MoveSmpY(self.cfg["Samplespositions"][sample-1]["Yposition"]) # becuase sample starts from 1 
			self.MoveSmpZ(self.cfg["Samplespositions"][sample-1]["Zposition"]) # becuase sample starts from 1 
			self.MoveSmpRot(self.cfg["Samplespositions"][sample-1]["Rotation"]) # becuase sample starts from 1 

			currentInterval = self.cfg["Intervals"][interval-1]
			startPoint = currentInterval["Startpoint"]
			endPoint = currentInterval["Endpoint"]
			stepSize = currentInterval["Stepsize"]
			picoAmmIntTime = currentInterval["picoAmmIntTime"]
			
			points = self.drange(startPoint, endPoint, stepSize)
			scanTime = self.getStepMovementTime(picoAmmIntTime, len(points))

			print(f"Energy Start: {self.start}, Energy End: {self.end}")
			print("move PGM to start point")
			self.MovePGM(startPoint)
			print("go to end point ...")
			moveThread = threading.Thread(target=self.MovePGM, args=(endPoint, scanTime), daemon=True)
			moveThread.start()

			for val in points:
				while True:
					energyRBV = float(self.PVs["PGM:Energy:RBV"].get())
					if energyRBV >= val:
						print("-" * 50)
						print(f"energy value (actual, RBV): ({val}, {energyRBV})")

						self.checkPause()

						currentScanInfo = []
						currentScanInfo.append({"Sample":sample})
						currentScanInfo.append({"Scan":scan})
						currentScanInfo.append({"Interval":interval})
						currentScanInfo.append({"RINGCurrent":self.PVs["RING:Current"].get()})
						currentScanInfo.append({"sampleTitle":self.cfg["Samplespositions"][sample-1]["sampleTitle"]})
						currentScanInfo.append({"TargetSP":val})		# tmp, delete the following line 

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

						ACQdata={**ACQdata, **det.data}
						log.info("Collecting data from detectors")
						expData.update(ACQdata)

						log.info("Applying post acquisition for selected detectors if applicable")
						for det in self.detectors:
							det.postACQ(ACQdata)
							ACQdata={**ACQdata, **det.data} 
							expData.update(ACQdata)

						Energy = energyRBV
						log.info("reading PGM energy: {}".format (Energy))

						IfDp = 0.0
						AbsorptionFluoDp = 0.0
						AbsorptionTrDp = 0.0
						ACQdata["Sample#"] = sample
						ACQdata["Scan#"] = scan
						ACQdata["Interval"] = interval
						ACQdata["ENERGY-RBK"] =	Energy
						expData.update(ACQdata)
						I0Dp = ACQdata["KEITHLEY_I0"]
						
						if "KEITHLEY_Itrans" in self.cfg["detectors"]:
							ItDp = ACQdata["KEITHLEY_Itrans"]
							AbsorptionTrDp = ItDp / I0Dp

						if "XFLASH" in self.cfg["detectors"]:
							IfDp = ACQdata["XFLASH-If"]
							AbsorptionFluoDp = ACQdata["XFLASH-FLUOR"]

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
						# log.info("collect all ROIs")
						# allROIs.acquire()
						
						"""
						(A) Ignore writing the 1st point, and, 
						(B) Ignore writing data during pausing (shutter stopped, current goes below the limits)
						"""
						scanPaused = self.PVs["SCAN:pause"].get()
						if counter == 0 or scanPaused == 1:
							pauseCounter = pauseCounter + 1 
						else:
							XDIWriter(expData, self.localDataPath, self.detChosen, self.creationTime ,self.expStartTimeDF, self.cfg, currentScanInfo)

							elapsedScanTime = timeModule.timer(startTime)					
							self.PVs["SCAN:Elapse"].put(elapsedScanTime)

						"""
						Stop PGM in case scan paused
						"""
						if scanPaused == 1:
							# self.PVs["DCM:Ctrl"].put(1)
							while self.PVs["SCAN:pause"].get() == 1:
								time.sleep(0.005)
							# self.PVs["DCM:Ctrl"].put(3)
							# self.motors["DCM:Energy:SP"].move(endPoint)		

						stopScan = self.PVs["SCAN:Stop"].get()
						if int(stopScan) == 1:   # exit from for loop (child) when stop is clicked
							log.warning("Scan tool has been stopped by human action")
							breakTag = 1

						counter = counter +1
						break
					time.sleep(0.005)

				if breakTag == 1:
					self.stopScanning()

			self.dataTransfer()

		print("#########################################################################")
		scanTime = timeModule.timer(startTime)
		log.info("Scan is finished | actual scan time is: {}, total number of points: {}".format(str(scanTime), counter))
		if pauseCounter > 1:
			log.warning("Ignored points | total number: {}. Check the experiment log file to see what was caused the pausing".format(pauseCounter))
		print("#########################################################################")
		log.info("Data file folder: {}".format(self.localDataPath))
		CLIMessage("Data file folder: {}".format(self.localDataPath),"M")
		print("#################################################")
		os.rename("SED_Scantool.log", "SEDScanTool_{}.log".format(self.creationTime))
		shutil.move("SEDScanTool_{}.log".format(self.creationTime), "{}/SEDScanTool_{}.log".format(self.localDataPath, self.creationTime))
		self.dataTransfer()
		# shutil.move("ROIs.xdi", "{}/ROIs_{}.xdi".format(self.localDataPath, self.creationTime))
		tmuxSession(self.tmuxSessionToKill).kill()
		self.PVs["SCAN:Stop"].put(1)	# to make the interlock of voltage source

	def getStepMovementTime(self, time, points):
		detectors = self.cfg['detectors']
		KeithleyLatency = float(self.limits['keithleyLatency'])
		XFalshLatency = float(self.limits['xflashLatency'])
		PGMLatency = float(self.limits['PGMLatency'])
		ICDataFrameTime = time + PGMLatency + KeithleyLatency

		return ICDataFrameTime * points

	def drange(self, start, stop, step, prec=10):
		log.info("Calculating energy points")
		decimal.getcontext().prec = prec

		start = decimal.Decimal(start).quantize(decimal.Decimal('1.0000'))
		stop = decimal.Decimal(stop).quantize(decimal.Decimal('1.0000'))
		step = decimal.Decimal(step)

		points = []
		r = start

		while r <= stop:
			points.append(float(r))
			r += step

		return points
	
	def signal_handler(self, sig, frame):
		if not self.lock:
			self.lock = True
			log.warning("stop PGM")
			# self.PVs["DCM:Ctrl"].put(0)
			time.sleep(1)
			# self.PVs["DCM:Ctrl"].put(3)
			# self.PVs["DCM:Speed"].put(float(self.scanLimits["monoThetaDefaultSpeed"]))
			super().signal_handler(sig, frame)
		
