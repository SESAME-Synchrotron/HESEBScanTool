import PyQt5
import sys
import time
import numpy as np
from SEDSS.SEDSupplements import CLIMessage
from common import Common
from .base import Base

class FICUS(Base):
	def __init__(self,name,paths,userinfo,cfg={}):
		super().__init__(name)
		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg

		self.PVs["Ficus:Erase"].put(1)
		FicusBaseDir = self.paths["ficus_workstation_data_path"]
		self.PVs["Ficus:Basedir"].put(FicusBaseDir)
		self.PVs["Ficus_ExpID"].put(userinfo["Proposal"])
	
	def ACQ(self,args):
		#0: 5ms | 1: 7.5ms | 2: 10ms | 3: 25ms | 4: 50ms | 5: 75ms | 6: 100ms | 7: 250ms | 8: 500ms | 9: 750ms | 10: 1s | 11: 2.5s | 12: 5s | 13: 7.5s | 14: 10s
		FrameDuration = args["FrameDuration"]


		CLIMessage("FrameDuration = {}, FFrameDuration == {}".format(FrameDuration, FrameDuration), "W")

		self.PVs["Ficus:FrameDuration"].put(FrameDuration)
		self.PVs["Ficus:Start"].put(1)
		
		#time.sleep(FrameDuration+0.05)
	
		Elapsedtime					=	self.data["FICUS-e-time[sec]"]	=	self.PVs["Ficus:Elapsedtime"].get()
		ROIs						=	self.PVs['Ficus:ROIs'].get()
		ROIsE						= 	np.divide(ROIs,Elapsedtime)
		self.data["FICUS-DEADTIME[%]"]	=	np.mean(self.PVs["Ficus:Deadtime"].get())
		self.data["FICUS-INT_TIME[sec]"]	=	FrameDuration
		self.data["FICUS-If"]				=	ROIsE[0]
		self.data["FICUS-ROI_0[c/s]"]		=	ROIs[0]
		self.data["FICUS-ROI_1[c/s]"]		=	ROIs[1]
		self.data["FICUS-ROI_2[c/s]"]		=	ROIs[2]
		self.data["FICUS-ROI_3[c/s]"]		=	ROIs[3]
		self.data["FICUS-ROI_4[c/s]"]		=	ROIs[4]
		self.data["FICUS-ROI_5[c/s]"]		=	ROIs[5]
		self.data["FICUS-ROI_6[c/s]"]		=	ROIs[6]
		self.data["FICUS-ROI_7[c/s]"]		=	ROIs[7]

	def postACQ(self,args):
		I0Dp	= self.data["IC1[V]"] = args["IC1[V]"]	
		ItDp	= self.data["IC2[V]"] = args["IC2[V]"]	
		It2Dp	= self.data["IC3[V]"] = args["IC3[V]"]	
		IfDp	= self.data["FICUS-If"]
		self.data["TRANS"]			=	self.trydiv(I0Dp,ItDp)
		self.data["TransRef"]		=	self.trydiv(ItDp,It2Dp)
		#self.data["FICUS-FLUOR"]			=	self.trydiv(IfDp,I0Dp)
		self.data["FICUS-FLUOR"] =	IfDp/I0Dp
		