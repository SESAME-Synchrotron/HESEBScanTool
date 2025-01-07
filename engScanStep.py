
#!/usr/bin/python3
"""
Step energy scan derived class
"""
import os
import time
from datetime import datetime, timedelta
import threading
import shutil 

import log
from heseb_step import HESEB_STEP
from SEDSS.CLIMessage import CLIMessage
from xdiWriter import XDIWriter
from SEDSS.SEDSupport import timeModule 

class ENGSCANSTEP(HESEB_STEP):
	def __init__(self, cfg, testingMode = "No"):
		super().__init__(cfg, testingMode)
		samples		 =	int(self.cfg["Nsamples"])
		scans		 =	int(self.cfg["Nscans"])
		intervals	 =	int(self.cfg["NIntervals"])
		settlingTime = float(self.cfg["settlingTime"])
		intervalsTime = 0
		for interval in range(intervals):
			points = len(self.drange(self.cfg["Intervals"][interval]["Startpoint"], self.cfg["Intervals"][interval]["Endpoint"], self.cfg["Intervals"][interval]["Stepsize"]))
			intervalsTime += (points * scans * samples * (self.cfg["Intervals"][interval]["picoAmmIntTime"] + settlingTime + 5))	# 5: time to meet energy tolerance

		currentTime = datetime.now()
		remainingTime = currentTime + timedelta(seconds=int(intervalsTime))
		self.PVs["RemainingTime"].put(remainingTime.strftime('%H:%M'), wait=True)
		self.startScan()

	def startScan(self):
		counter = 0 
		pauseCounter = 0
		breakTag = 0 
		startTime = time.time()

		self.startScanTime = time.strftime("%H:%M:%S", time.localtime())

		self.PVs["ScanStartTime"].put(self.startScanTime)
		log.info(f"Scan started at: {self.startScanTime}")

		self.clearPlot()

		log.info("Start data collection ...")
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

			self.PVs["NSamples"].put(self.cfg["Nsamples"])
			self.PVs["NScans"].put(self.cfg["Nscans"])
			self.PVs["NIntervals"].put(self.cfg["NIntervals"])
			self.PVs["CurrentSample"].put(sample)
			self.PVs["CurrentScan"].put(scan)
			self.PVs["CurrentInterval"].put(interval)
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
			for point in points:
				self.checkPause()
				currentScanInfo = []
				currentScanInfo.append({"Sample":sample})
				currentScanInfo.append({"Scan":scan})
				currentScanInfo.append({"Interval":interval})
				currentScanInfo.append({"RINGCurrent":self.PVs["RING:Current"].get()})
				currentScanInfo.append({"sampleTitle":self.cfg["Samplespositions"][sample-1]["sampleTitle"]})				 
				currentScanInfo.append({"TargetSP":point})		# tmp, delete the following line
				self.MovePGM(point, currentScanInfo)

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

				Energy = self.PVs["PGM:Energy:RBV"].get()
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
					IfDp =	ACQdata["XFLASH-If"]
					AbsorptionFluoDp =	ACQdata["XFLASH-FLUOR"]

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
				(B) Ignore writing data during pausing (shutter stopped, current goes below the limits)
				"""
				if counter == 0 or self.PVs["ScanPause"].get()==1:  
					pauseCounter = pauseCounter + 1 
					pass
				else:
					XDIWriter(expData, self.localDataPath, self.detChosen, self.creationTime ,self.expStartTimeDF, self.cfg, currentScanInfo)
					
					elapsedScanTime = timeModule.timer(startTime)					
					
					self.PVs["ElapsedTime"].put(elapsedScanTime)
					log.info(f"Elapse time scan for scan point ({counter}) is: {elapsedScanTime}")

				counter = counter +1

				stopScan = self.PVs["ScanStop"].get()
				if int(stopScan) == 1:   # exit from for loop (child) when stop is clicked
					log.warning("Scan tool has been stopped by human action")
					breakTag = 1
					break

			"""
			Transferring the data after each scan 
			"""
			self.dataTransfer()

			if breakTag == 1:
				self.stopScanning()

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
		self.PVs["ScanStop"].put(1)	# to make the interlock of voltage source
