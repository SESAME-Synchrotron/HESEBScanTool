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

		self.allowedPicoIntTime = [10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1]
		#the actual allowed IntTimes are ["Passive", "Event"," I/O Intr", 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1]


	def ACQ(self,args):
		
		picoAmmIntTimeIndex = int(args["picoAmmIntTimeIndex"])
		self.PVs["picoAmmeter1CurrentRange"].put(picoAmmIntTimeIndex)
		time.sleep( float( self.allowedPicoIntTime[picoAmmIntTimeIndex - 3] ) )
		
		try: 
			self.data["KEITHLEY_I0"] = self.PVs["picoAmmeter1Current"].get()
		except:
			CLIMessage("Warning: Please check the KETEK Detector", "E")
			pass

	def postACQ(self,args):
		# I0Dp	= self.data["IC1[V]"] = args["IC1[V]"]	
		# ItDp	= self.data["IC2[V]"] = args["IC2[V]"]	
		# It2Dp	= self.data["IC3[V]"] = args["IC3[V]"]	
		# IfDp	= self.data["KETEK-If"]
		# #print("I0Dp: ", I0Dp, "ItDp: ", ItDp, "It2Dp: ", It2Dp, "IfDp:", IfDp )
		# self.data["TRANS"]			=	self.trydiv(I0Dp,ItDp)
		# self.data["TransRef"]		=	self.trydiv(ItDp,It2Dp)
		# #print ("Trans: ", self.data["TRANS"], "TransRef: ", self.data["TransRef"])
		# #self.data["KETEK-FLUOR"]    =	self.trydiv(IfDp,I0Dp)
		# self.data["KETEK-FLUOR"]    =	IfDp/I0Dp
		pass
