import time

from .base import Base
from SEDSS.SEDSupport import timeModule

class KEITHLEY_I0(Base):
	def __init__(self, name, paths, cfg={}, voltageSourceParam=[]):
		super().__init__(name)

		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg

		self.PVs["picoAmmeterI0SoftReset"].put(1)	# apply soft reset before start collecting data
		self.PVs["picoAmmeterI0Damping"].put(0)		# disable damping
		self.PVs["picoAmmeterI0TPSS"].put(0)		# put 0 in time per step sample

		self.voltageSourceEnable 		= voltageSourceParam[0]
		self.voltageSourceRange 		= voltageSourceParam[1]
		self.voltageSourceCurrentLimit  = voltageSourceParam[2]
		self.voltageSourceValue		    = voltageSourceParam[3]
		# put the values taken for the voltage source parameters after reset
		self.PVs["voltageSourceEnable"].put(self.voltageSourceEnable)
		self.PVs["voltageSourceRange"].put(self.voltageSourceRange)
		self.PVs["voltageSourceCurrentLimit"].put(self.voltageSourceCurrentLimit)
		self.PVs["voltageSourceVoltage"].put(self.voltageSourceValue)

	def ACQ(self, args):

		NPLC, ActualIntTime = self.getNPLC_IntTime(args["picoAmmIntTime"])
		self.PVs["picoAmmeterI0TPSS"].put(ActualIntTime)
		self.PVs["picoAmmeterI0IntTime"].put(NPLC)		# integration time
		startTime = time.time()
		self.PVs["picoAmmeterI0StartAcq"].put(1)
		time.sleep(0.1)

		while self.PVs["picoAmmeterI0StartAcq"].get(timeout=1, use_monitor=False):
			time.sleep(0.01)

		overallIntTime = timeModule.timer(startTime)
		self.data["KEITHLEY_I0"] = self.PVs["picoAmmeterI0AcqReadOut"].get()
		self.data["KEITHLEY_I0_intTime"] = overallIntTime

	def getNPLC_IntTime(self, intTime):
		"""
		As we use the averaging filter of KEITHLEY, the device itself does not
		accept integration time to be entered directly. The actual integration time
		is defined by this equation:
			3∗NPLC/50∗(NumSamples∗1.0285)+ε

		where:
			ε = 0.0076172
			3: collapses to 1 when AutoZero is disabled.

		By providing NPLC and the pre-calculated ActualIntTime, the IOC can
		calculate the NumSamples and then send it as well as the NPLC to the Keithley
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

	def postACQ(self, args):
		pass
