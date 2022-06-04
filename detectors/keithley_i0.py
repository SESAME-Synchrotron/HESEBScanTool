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

class KEITHLEY_I0(Base):
	def __init__(self,name,paths,cfg={}):
		super().__init__(name)

		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg

		self.PVs["picoAmmeterI0SoftReset"].put(1) # apply soft reset before start collecting data 
		self.PVs["picoAmmeterI0Damping"].put(0) # disable damping 
		self.PVs["picoAmmeterI0TPSS"].put(0) # disable damping 


	def ACQ(self,args):
		sleepTime = 0.0001
		timerCounter = 0 

		CLIMessage("{}".format(args), "E")
		NPLC, ActualIntTime = self.getNPLC_IntTime(args["picoAmmIntTime"])
		print(NPLC, ActualIntTime)
		self.PVs["picoAmmeterI0TPSS"].put(ActualIntTime)
		self.PVs["picoAmmeterI0IntTime"].put(NPLC) ## int. time 
		time.sleep(0.2)
		# try: 
		picoReadOut = self.PVs["picoAmmeterI0AcqReadOut"].get()
		startTime = time.time()
		self.PVs["picoAmmeterI0StartAcq"].put(1)
		while True:
			if picoReadOut == self.PVs["picoAmmeterI0AcqReadOut"].get():
				pass
				timerCounter = timerCounter + 1
			else:
				break
			time.sleep(sleepTime)
			if timerCounter * sleepTime >= 10:
				CLIMessage("Collection time has reached the maximum allowed time: {} sec".format(timerCounter*sleepTime), "W")
				break
		overallIntTime = timeModule.timer(startTime)
		CLIMessage("Collection time:: {}".format(overallIntTime), "E")
		self.data["KEITHLEY_I0"] = self.PVs["picoAmmeterI0AcqReadOut"].get()
		## AN_: temp for testing the integration tiome, DELETE IT..
		self.data["KEITHLEY_I0_intTime"] = overallIntTime

	def getNPLC_IntTime(self, intTime):
		"""
		This method is used to return Number of Power Line Cycles (NPLC) and 
		average count (AVER:COUN) that are used to define the keithley intigration
		time. 

		Note: the integration time that the user is entered should be multiple of 0.25, 
		this is not a restrection from keithley but in real life choosing an integration time 
		between 0.25 to 5 second is very common. 

		but, in keithley, and because we use the averaging filter of the device, it is 
		difficult to get the exact integration time as it should be, because this time
		is calculated by this equation: 

			3∗NPLC/50∗(NumSamples∗1.0285)+ε

		where: 
			ε = 0.0076172
			3: collapses to 1 when AutoZero is disabled.

		"""
		intTime = float(intTime)

		if intTime == 0.25: 
			NPLC 	 	  = 2
			ActualIntTime = 0.256
			return NPLC, ActualIntTime
		elif intTime == 0.5: 
			NPLC 	 	  = 2
			ActualIntTime = 0.501
			return NPLC, ActualIntTime
		elif intTime == 0.75: 
			NPLC 	 	  = 2
			ActualIntTime = 0.748
			return NPLC, ActualIntTime
		elif intTime == 1.0: 
			NPLC 	 	  = 1
			ActualIntTime = 0.994
			return NPLC, ActualIntTime
		elif intTime == 1.25: 
			NPLC 	 	  = 1
			ActualIntTime = 1.241
			return NPLC, ActualIntTime
		elif intTime == 1.5: 
			NPLC 	 	  = 2
			ActualIntTime = 1.480
			return NPLC, ActualIntTime
		elif intTime == 1.75: 
			NPLC 	 	  = 2
			ActualIntTime = 1.735
			return NPLC, ActualIntTime
		elif intTime == 2.0: 
			NPLC 	 	  = 2
			ActualIntTime = 1.982
			return NPLC, ActualIntTime
		elif intTime == 2.25: 
			NPLC 	 	  = 2
			ActualIntTime = 2.229
			return NPLC, ActualIntTime
		elif intTime == 2.50: 
			NPLC 	 	  = 2
			ActualIntTime = 2.476
			return NPLC, ActualIntTime
		elif intTime == 2.75: 
			NPLC 	 	  = 2
			ActualIntTime = 2.722
			return NPLC, ActualIntTime
		elif intTime == 3.0: 
			NPLC 	 	  = 2
			ActualIntTime = 3.09
			return NPLC, ActualIntTime
		elif intTime == 3.25:
			NPLC 	 	  = 2
			ActualIntTime = 3.21
			return NPLC, ActualIntTime
		elif intTime == 3.5:
			NPLC 	 	  = 2
			ActualIntTime = 3.58
			return NPLC, ActualIntTime
		elif intTime == 3.75:
			NPLC 	 	  = 2
			ActualIntTime = 3.711
			return NPLC, ActualIntTime
		elif intTime == 4.0:
			NPLC 	 	  = 2
			ActualIntTime = 4.08
			return NPLC, ActualIntTime
		elif intTime == 5.0:
			NPLC 	 	  = 2
			ActualIntTime = 5.006
			return NPLC, ActualIntTime
		elif intTime == 6.0:
			NPLC 	 	  = 2
			ActualIntTime = 5.931
			return NPLC, ActualIntTime
		elif intTime == 7.0:
			NPLC 	 	  = 2
			ActualIntTime = 7.042
			return NPLC, ActualIntTime
		elif intTime == 8.0:
			NPLC 	 	  = 2
			ActualIntTime = 7.968
			return NPLC, ActualIntTime
		elif intTime == 9.0:
			NPLC 	 	  = 2
			ActualIntTime = 9.07
			return NPLC, ActualIntTime
		elif intTime == 10:
			NPLC 	 	  = 2
			ActualIntTime = 10.004
			return NPLC, ActualIntTime

	def postACQ(self,args):
		pass
