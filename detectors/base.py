import math
import sys
import epics
from SEDSS.SEDSupplements import CLIMessage

sys.path.append("..")
from common import Common

class Base:
	def __init__(self, name):
		"""
		Added by MZ.
		the following elements are default as IC detector should be chosen all the time.
		"""
		self.name = name
		self.data = {}
		self.data["Sample#"]					=	0
		self.data["Scan#"]						=	0
		self.data["Interval"]					=	0
		self.data["ENERGY-RBK"]					=	0
		# self.data["IC1[V]"]						=	0
		# self.data["IC2[V]"]						=	0
		# self.data["IC3[V]"]						=	0
		self.data["TRANS"]						=	0
		self.data["TransRef"]					=	0

		if name == "XFLASH":
			self.data["XFLASH-If"] 				= 	0
			self.data["XFLASH-FLUOR"] 			= 	0
			self.data["XFLASH-ROI_0[c/s]"] 		=	0
			self.data["XFLASH-ROI_1[c/s]"] 		=	0
			self.data["XFLASH-ROI_2[c/s]"] 		=	0
			self.data["XFLASH-ROI_3[c/s]"] 		=	0
			self.data["XFLASH-ROI_4[c/s]"] 		=	0
			self.data["XFLASH-ROI_5[c/s]"] 		=	0
			self.data["XFLASH-ROI_6[c/s]"] 		=	0
			self.data["XFLASH-ROI_7[c/s]"] 		=	0
			self.data["XFLASH-e-time[sec]"] 	= 	0
			self.data["XFLASH-DEADTIME[%]"] 	= 	0
			self.data["XFLASH-INT_TIME[sec]"] 	= 	0
			self.data["XFLASH-OCR"] 			= 	0
			self.data["XFLASH-ICR"] 			= 	0
		elif name == "FICUS":
			self.data["FICUS-If"] 				= 	0
			self.data["FICUS-FLUOR"] 			= 	0
			self.data["FICUS-ROI_0[c/s]"] 		=	0
			self.data["FICUS-ROI_1[c/s]"] 		=	0
			self.data["FICUS-ROI_2[c/s]"] 		=	0
			self.data["FICUS-ROI_3[c/s]"] 		=	0
			self.data["FICUS-ROI_4[c/s]"] 		=	0
			self.data["FICUS-ROI_5[c/s]"] 		=	0
			self.data["FICUS-ROI_6[c/s]"] 		=	0
			self.data["FICUS-ROI_7[c/s]"] 		=	0
			self.data["FICUS-e-time[sec]"]		= 	0
			self.data["FICUS-DEADTIME[%]"]		= 	0
			self.data["FICUS-INT_TIME[sec]"] 	= 	0
			self.data["FICUS-OCR"] 				= 	0
			self.data["FICUS-ICR"] 				= 	0
		elif name == "KEITHLEY_I0":
			self.data["KEITHLEY_I0"] 			= 	0
			self.data["KEITHLEY_I0_intTime"]	=	0
			self.data["mutrans"]				= 	0
		elif name == "KEITHLEY_Itrans":
			self.data["KEITHLEY_Itrans"] 		= 	0
			self.data["mutrans"]				= 	0

	def loadPVS(self, name):
		JsonPVlist = Common.loadjson('pvlist/{}.json'.format(name))
		self.PVs = {}
		DisconnectedPvs = []
		for entry, pvname in JsonPVlist["PV"].items():
			pvname = pvname["pvname"]
			PVobj = epics.PV(pvname)

			if PVobj.get() is None:
				CLIMessage("{}: is not connected".format(pvname), "E")
				DisconnectedPvs.append("{}\n".format(pvname))
			else:
				CLIMessage("{}: is connected".format(pvname), "I")
				self.PVs[entry] = PVobj

	def preACQ(self, *args, **kwargs):
		print(self.name, "preACQ is not implemented")

	def ACQ(self, *args, **kwargs):
		print(self.name, "ACQ is not implemented")

	def postACQ(self, *args, **kwargs):
		pass

	def trydiv(self, val1, val2):
		try:
			return math.log(val1 / val2)
		except:
			return 0