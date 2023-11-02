from heseb import HESEB
import log
import time
from SEDSS.CLIMessage import CLIMessage


class HESEB_XRFSTEP(HESEB):
	def __init__(self, paths, cfg, testingMode):
		super().__init__(cfg, testingMode)
	
	
	def MovePGM(self,SP, curentScanInfo=None):

		self.PVs["PGM:Energy:Reached"].put(0, wait=True) # set the energy reached pv to False before start moving the PGM
		self.PVs["PGM:Energy:SP"].put(SP, wait=True) # set the energy to the PGM 
		time.sleep(.15) # adding some delay to let the motor stat moving.
		log.info("Move PGM to energy: {}".format(SP)) 
		"""
		the following loop tries to put the scan tool in wait state untill the PGM energy is reached by: 
			1. Keep checking the Grating & M2 motors status (DMOV)
			2. Keep checking the energy reached PV 
		Notes: 
			1. loop conditioning must be satisfied because energy PV is set to 0 before start moving the PGM.
			2. checkToleranceEvery variable can be changed in limites.josn file 
		"""
		if curentScanInfo != None:
			CLIMessage("PGM is moving ... to {} for Sample({}), Scan({}) and Interval({})".format(SP, 
				curentScanInfo[0]["Sample"], curentScanInfo[1]["Scan"], curentScanInfo[2]["Interval"]), "IG")

		while not self.motors["PGM:Grating"].get("DMOV") or not self.motors["PGM:M2"].get("DMOV") or int (self.PVs["PGM:Energy:Reached"].get(use_monitor=False)) != 1:
			time.sleep(self.scanLimites["checkToleranceEvery"])
		"""
		the loop below has been added because the one above was not enough to get energy RBV within the allowed tolerances. The main issue is that energy RBV is a PROC PV 
		relies on many parameters to be calculated, this means, after reaching the target prositions of the PGM motors the final energy RBV needs some time to be calculated. 
		however, the loop does the following: 
			1. Periodically checks the energy RBV if it is within the given tolerances, if yes breaks the loop 
			2. if not, waits until the maximum wait time condition is met. 

		Notes: 
			1. energyRBVTolerance, checkToleranceEvery & maxTime2MeetTolerance variables can be changed/defined in the "configrations/limites.json" file 
			2. the three variables above have a big impact on the energy precision and scan time. 
		"""
		# CLIMessage("Energy : {}".format (self.PVs["PGM:Energy:RBV"].get(use_monitor = False)))
		
		print("\n")
		timeCounter = 0 
		while not (float(SP) - self.scanLimites["energyRBVTolerance"]) <= float (self.PVs["PGM:Energy:RBV"].get()) <= (float(SP) + self.scanLimites["energyRBVTolerance"]):
			#CLIMessage("Trying to reach the energy SP within the given tolerance", "IG")
			self.PVs["PGM:Energy:SP"].put(SP, wait=True)
			time.sleep(self.scanLimites["checkToleranceEvery"])
			timeCounter = timeCounter + 1
			if timeCounter * self.scanLimites["checkToleranceEvery"] >= self.scanLimites["maxTime2MeetTolerance"]:
				log.warning("Reaching maximum wait time to reach the target energy")
				break
	
		#self.PVs["PGM:Energy:Reached"].put(1, wait=True)
		time.sleep(self.cfg["settlingTime"])