import json
import epics
import common
import PyQt5
import sys
import time
from datetime import datetime 
from SEDSS.SEDSupplements import CLIMessage
from SEDSS.SEDSupport import timeModule

from .base import Base

class KEITHLEY_ITRANS(Base):
	def __init__(self,name,paths,cfg={}):
		super().__init__(name)

		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg

		self.PVs["picoAmmeterItransSoftReset"].put(1) # apply soft reset before start collecting data 
		self.PVs["picoAmmeterItransTPSS"].put(0) # put 0 in time per step sample 


	def ACQ(self,args):
		sleepTime = 0.0001
		timerCounter = 0 

		#CLIMessage("{}".format(args), "E")
		NPLC, ActualIntTime = self.getNPLC_IntTime(args["picoAmmIntTime"])
		#print(NPLC, ActualIntTime)
		self.PVs["picoAmmeterItransTPSS"].put(ActualIntTime)
		self.PVs["picoAmmeterItransIntTime"].put(NPLC) ## int. time 
		time.sleep(0.2)
		# try: 
		picoReadOut = self.PVs["picoAmmeterItransAcqReadOut"].get()
		startTime = time.time()
		self.PVs["picoAmmeterItransStartAcq"].put(1)

		while self.PVs["picoAmmeterItransStartAcq"].get(use_monitor=False):
		# while epics.PV("K6485:1:Acquire.PROC").get():
			
			time.sleep(.01)
		# while True:
		# 	if picoReadOut == self.PVs["picoAmmeterItransAcqReadOut"].get():
		# 		pass
		# 		timerCounter = timerCounter + 1
		# 	else:
		# 		break
		# 	time.sleep(sleepTime)
		# 	if timerCounter * sleepTime >= ActualIntTime * 5:
		# 		"""
		# 		Maximum waiting time is the double of the actual integration
		# 		time. 
				
		# 		This is needed only when kiethely returns a value that
		# 		equals the previous collected one!!

		# 		Maybe this part can be removed if we get a precise acquire:stat 
		# 		PV ...
		# 		"""
		# 		CLIMessage("Collection time has reached the maximum allowed time: {} sec".format(timerCounter*sleepTime), "W")
		# 		break
		overallIntTime = timeModule.timer(startTime)
		#CLIMessage("Collection time:: {}".format(overallIntTime), "E")
		self.data["KEITHLEY_Itrans"] = self.PVs["picoAmmeterItransAcqReadOut"].get()
		## AN_: temp for testing the integration tiome, DELETE IT..
		self.data["KEITHLEY_Itrans_intTime"] = overallIntTime

	def getNPLC_IntTime(self, intTime):
		"""
		As we use the averaging filter of KIETHELY, the device it self does not 
		accept integration time to be entered directlly. The actual integration time 
		is defined by this equation:  
			3∗NPLC/50∗(NumSamples∗1.0285)+ε

		where: 
			ε = 0.0076172
			3: collapses to 1 when AutoZero is disabled.
		
		By providing NPLC and the pre-caculated ActualIntTime, the IOC can 
		calculate the NumSamples and then send it as well as the NPLC to the keithley 
		device. 

		"""
		intTime = float(intTime)

		if intTime == 0.25: 			# 4 Samples
			NPLC 	 	  = 1
			ActualIntTime = 0.27
			return NPLC, ActualIntTime
		elif intTime == 0.5: 			# 7 Samples
			NPLC 	 	  = 1
			ActualIntTime = 0.45
			return NPLC, ActualIntTime
		elif intTime == 0.75: 			# 11 Samples
			NPLC 	 	  = 1
			ActualIntTime = 0.74
			return NPLC, ActualIntTime
		elif intTime == 1.0: 			# 15 Samples
			NPLC 	 	  = 1
			ActualIntTime = 0.94
			return NPLC, ActualIntTime
		elif intTime == 1.25: 			# 18 Samples
			NPLC 	 	  = 1
			ActualIntTime = 1.12
			return NPLC, ActualIntTime
		elif intTime == 1.5: 			# 12 Samples
			NPLC 	 	  = 2
			ActualIntTime = 1.49
			return NPLC, ActualIntTime
		elif intTime == 1.75: 			# 14 Samples
			NPLC 	 	  = 2
			ActualIntTime = 1.74
			return NPLC, ActualIntTime
		elif intTime == 2.0: 			# 16 Samples
			NPLC 	 	  = 2
			ActualIntTime = 1.99
			return NPLC, ActualIntTime
		elif intTime == 2.25: 			# 17 Samples
			NPLC 	 	  = 2
			ActualIntTime = 2.12
			return NPLC, ActualIntTime
		elif intTime == 2.50: 			# 19 Samples
			NPLC 	 	  = 2
			ActualIntTime = 2.37
			return NPLC, ActualIntTime
		elif intTime == 2.75: 			# 21 Samples
			NPLC 	 	  = 2
			ActualIntTime = 2.61
			return NPLC, ActualIntTime
		elif intTime == 3.0: 			# 23 Samples
			NPLC 	 	  = 2
			ActualIntTime = 2.85
			return NPLC, ActualIntTime
		elif intTime == 3.25:			# 25 Samples
			NPLC 	 	  = 2
			ActualIntTime = 3.11
			return NPLC, ActualIntTime
		elif intTime == 3.5:			# 27 Samples
			NPLC 	 	  = 2
			ActualIntTime = 3.35
			return NPLC, ActualIntTime
		elif intTime == 3.75:			# 29 Samples
			NPLC 	 	  = 2
			ActualIntTime = 3.6
			return NPLC, ActualIntTime
		elif intTime == 4.0:			# 31 Samples
			NPLC 	 	  = 2
			ActualIntTime = 3.84
			return NPLC, ActualIntTime
		elif intTime == 5.0:			# 39 Samples
			NPLC 	 	  = 2
			ActualIntTime = 4.83
			return NPLC, ActualIntTime
		elif intTime == 6.0:			# 47 Samples
			NPLC 	 	  = 2
			ActualIntTime = 5.81
			return NPLC, ActualIntTime
		elif intTime == 7.0:			# 54 Samples
			NPLC 	 	  = 2
			ActualIntTime = 6.68
			return NPLC, ActualIntTime
		elif intTime == 8.0:			# 62 Samples
			NPLC 	 	  = 2
			ActualIntTime = 7.66
			return NPLC, ActualIntTime
		elif intTime == 9.0:			# 70 Samples
			NPLC 	 	  = 2
			ActualIntTime = 8.65
			return NPLC, ActualIntTime

	def postACQ(self,args):
		pass
