import json
import epics
import common
import PyQt5
import sys
import time
from datetime import datetime 
from SEDSS.CLIMessage import CLIMessage

from .base import Base

class XFLASH(Base):
	def __init__(self,name,paths,cfg={}):
		super().__init__(name)

		#print ("pvname::::", name, "pvpath::::;", paths, "cfg::::", cfg)
		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg

		self.PVs["xFlash_status_rate"].put(9)
		self.PVs["xFlash_data_rate"].put(9)
		self.PVs["xFlash_realtime"].put(0.0)
		self.PVs["xFlash_livetime"].put(0.0)

	def ACQ(self,args):
		
		mapScanFlag = False
		#CLIMessage("XFLASH-Start ACQ:: {}".format(datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S.%f')), "E")
		try: 
			if args["scanTopology"] in ('Snake', 'Sequential', 'Diagonal'):
				FrameDuration = args["FrameDuration"]
				mapScanFlag = True
			else:
				FrameDuration = args["ICsIntTime"]
		except:
			FrameDuration = args["ICsIntTime"]
		#CLIMessage("XFLASH FrameDuration:::: {}".format(FrameDuration), "E")
		self.PVs["xFlash_realtime"].put(FrameDuration)
		
		#for tr in range(3):
		#	if self.PVs["xFlash_ok"].get():
		#		self.PVs["xFlash_stop"].put(1)
		#		#time.sleep(0.1)
		self.PVs["xFlash_erasestart"].put(1, wait=True)
		#time.sleep(FrameDuration)
		
		#for tr in range(3):
		#	if self.PVs["xFlash_ok"].get():
		#		self.PVs["xFlash_stop"].put(1)
		#		#time.sleep(0.1)

		if mapScanFlag:
			self.data["XFLASH-MCA1"]			= self.PVs["xFlash_mca1"].get()
		else: 
			Elapsedtime						= self.data["XFLASH-e-time[sec]"]	=	self.PVs["xFlash_elapsedtime"].get()
			ROIsE							= [self.PVs["xFlash_ROI_0"].get() / Elapsedtime,self.PVs["xFlash_ROI_1"].get() / Elapsedtime,self.PVs["xFlash_ROI_2"].get() / Elapsedtime,self.PVs["xFlash_ROI_3"].get() / Elapsedtime,self.PVs["xFlash_ROI_4"].get() / Elapsedtime,self.PVs["xFlash_ROI_5"].get() / Elapsedtime,self.PVs["xFlash_ROI_6"].get() / Elapsedtime,self.PVs["xFlash_ROI_7"].get() / Elapsedtime]
			self.data["XFLASH-DEADTIME[%]"]	= self.PVs["xFlash_deadtime"].get()
			self.data["XFLASH-INT_TIME[sec]"]= FrameDuration
			self.data["XFLASH-If"]			= ROIsE[0]
			self.data["XFLASH-ROI_0[c/s]"]	= self.PVs["xFlash_ROI_0"].get()
			self.data["XFLASH-ROI_1[c/s]"]	= self.PVs["xFlash_ROI_1"].get()
			self.data["XFLASH-ROI_2[c/s]"]	= self.PVs["xFlash_ROI_2"].get()
			self.data["XFLASH-ROI_3[c/s]"]	= self.PVs["xFlash_ROI_3"].get()
			self.data["XFLASH-ROI_4[c/s]"]	= self.PVs["xFlash_ROI_4"].get()
			self.data["XFLASH-ROI_5[c/s]"]	= self.PVs["xFlash_ROI_5"].get()
			self.data["XFLASH-ROI_6[c/s]"]	= self.PVs["xFlash_ROI_6"].get()
			self.data["XFLASH-ROI_7[c/s]"]	= self.PVs["xFlash_ROI_7"].get()
			self.data["XFLASH-INT_TIME[sec]"]= self.PVs["xFlash_livetime"].get()
			# self.data["XFLASH-OCR"]			= self.PVs["xFlash_dxp_OCR"].get()
			# self.data["XFLASH-ICR"]			= self.PVs["xFlash_dxp_ICR"].get()

		#print ("-----", self.data["XFLASH-IF"])

		if self.data["XFLASH-If"] == 0:
			CLIMessage("Warning: Please check the XFLASH Detector", "W")
		#CLIMessage("XFLASH-End ACQ:: {}".format(datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S.%f')), "E")

	def postACQ(self,args):
		I0Dp	= self.data["IC1[V]"] = args["IC1[V]"]	
		ItDp	= self.data["IC2[V]"] = args["IC2[V]"]	
		It2Dp	= self.data["IC3[V]"] = args["IC3[V]"]	
		IfDp	= self.data["XFLASH-If"]
		#print("I0Dp: ", I0Dp, "ItDp: ", ItDp, "It2Dp: ", It2Dp, "IfDp:", IfDp )
		self.data["TRANS"]			=	self.trydiv(I0Dp,ItDp)
		self.data["TransRef"]		=	self.trydiv(ItDp,It2Dp)
		#print ("Trans: ", self.data["TRANS"], "TransRef: ", self.data["TransRef"])
		#self.data["XFLASH-FLUOR"]    =	self.trydiv(IfDp,I0Dp)
		self.data["XFLASH-FLUOR"]    =	IfDp/I0Dp
