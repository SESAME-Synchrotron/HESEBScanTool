import json
import epics
import common
import PyQt5
import sys
import time
from datetime import datetime 
from SEDSS.SEDSupplements import CLIMessage

from .base import Base

class KEITHLEY_I0(Base):
	def __init__(self,name,paths,cfg={}):
		super().__init__(name)

		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg


	def ACQ(self,args):
		
		# picoAmmIntTime = int(args["picoAmmIntTime"])
		# self.PVs["picoAmmeter1CurrentRange"].put(picoAmmIntTime)
		
		# time.sleep( float( self.allowedPicoIntTime[picoAmmIntTime - 3] ) )
		# print ("float( self.allowedPicoIntTime[picoAmmIntTime - 3] )", float( self.allowedPicoIntTime[picoAmmIntTime - 3] ))
		try: 
			self.PVs["picoAmmeterI0IntTime"].put(args["picoAmmIntTime"])
			self.PVs["picoAmmeterI0StartAcq"].put(1)
			time.sleep(args["picoAmmIntTime"])
			self.data["KEITHLEY_I0"] = self.PVs["picoAmmeterI0AcqReadOut"].get()
			print ("avrg current ", self.data["KEITHLEY_I0"], "args[picoAmmIntTime]:  ", args["picoAmmIntTime"])
		except:
			CLIMessage("Warning: Please check the KEITHLEY_I0 Detector", "E")
			pass

	def postACQ(self,args):
		pass
