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

		self.loadPVS(name)
		self.paths	= paths
		self.cfg = cfg
		self.PVs["xFlash_status_rate"].put(9) # 0.1 Second
		self.PVs["xFlash_data_rate"].put(9) # 0.1 Second
		self.PVs["xFlash_realtime"].put(0.0)
		self.PVs["xFlash_livetime"].put(0.0)

	def ACQ(self,args):		
		mapScanFlag = False
		try: 
			if args["scanTopology"] in ('Snake', 'Sequential', 'Diagonal'):
				FrameDuration = args["FrameDuration"]
				mapScanFlag = True
			else:
				FrameDuration = args["picoAmmIntTime"]
		except:
			FrameDuration = args["picoAmmIntTime"]
			
		self.PVs["xFlash_realtime"].put(FrameDuration)
		self.PVs["xFlash_erasestart"].put(1, wait=True)
		# time.sleep(FrameDuration+2)

		ROIs = self.cfg["ROIs"]
		selectedROIs = []
		for ROI in ROIs:
			selectedROIs.append(int(ROI[-1]))

		if mapScanFlag:
			self.data["XFLASH-MCA1"]			= self.PVs["xFlash_mca1"].get()
		else: 
			Elapsedtime						= self.data["XFLASH-e-time[sec]"]	=	self.PVs["xFlash_elapsedtime"].get()
			ROIsE							= [self.PVs["xFlash_ROI_0"].get() / Elapsedtime,self.PVs["xFlash_ROI_1"].get() / Elapsedtime,self.PVs["xFlash_ROI_2"].get() / Elapsedtime,self.PVs["xFlash_ROI_3"].get() / Elapsedtime,self.PVs["xFlash_ROI_4"].get() / Elapsedtime,self.PVs["xFlash_ROI_5"].get() / Elapsedtime,self.PVs["xFlash_ROI_6"].get() / Elapsedtime,self.PVs["xFlash_ROI_7"].get() / Elapsedtime]
			self.data["XFLASH-DEADTIME[%]"]	= self.PVs["xFlash_deadtime"].get()
			self.data["XFLASH-INT_TIME[sec]"]= FrameDuration
			self.data["XFLASH-If"]			= ROIsE[0]

			for ROI in selectedROIs:
				self.data[f"XFLASH-ROI_{ROI}[c/s]"] = self.PVs[f"xFlash_ROI_{ROI}"].get() / Elapsedtime

			self.data["XFLASH-INT_TIME[sec]"]= self.PVs["xFlash_livetime"].get()

		if self.data["XFLASH-If"] == 0:
			CLIMessage("Warning: Please check the XFLASH Detector", "W")
		#CLIMessage("XFLASH-End ACQ:: {}".format(datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S.%f')), "E")

	def postACQ(self,args):	
		# CLIMessage("ARGS at PostACQ {}".format(args), "E")
		I0Dp	= self.data["KEITHLEY_I0"] = args["KEITHLEY_I0"]
		if "KEITHLEY_Itrans" in args:
			ItDp	= self.data["KEITHLEY_Itrans"] = args["KEITHLEY_Itrans"]	
			self.data["TRANS"] = self.trydiv(I0Dp,ItDp)
			print("*********************************************************************************")	
		IfDp	= self.data["XFLASH-If"]
		try:
			self.data["XFLASH-FLUOR"]    =	IfDp/I0Dp
		except:
			self.data["XFLASH-FLUOR"]    =	0
			CLIMessage ("No data from XFLASH ", "E")
		
