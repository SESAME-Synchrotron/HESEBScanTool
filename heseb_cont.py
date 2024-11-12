import time
import log

from heseb import HESEB
from SEDSS.CLIMessage import CLIMessage

class HESEB_CONT(HESEB):
	def __init__(self, cfg, testingMode):
		super().__init__(cfg, testingMode)

	def MovePGM(self, SP, scanTime=None, currentScanInfo=None):

		log.info(f"Move PGM to target energy: {SP}")

		self.PVs["PGM:Energy:Reached"].put(0, wait=True) # set the energy reached pv to False before start moving the PGM
		self.PVs["PGM:Energy:SP"].put(SP, wait=True)
		time.sleep(1)

		if scanTime:
			self.gratingVelo.put((abs(float(self.gratingVal.get()) - float(self.gratingRBV.get()))) / scanTime)
			self.m2Velo.put((abs(float(self.m2Val.get()) - float(self.m2RBV.get()))) / scanTime)

		self.motors["PGM:Grating"].put("stop_go", 3) # Go
		time.sleep(0.1)
		self.motors["PGM:M2"].put("stop_go", 3) # Go

		time.sleep(1) # adding some delay to let the motor start moving
		"""
		the following loop tries to put the scan tool in wait state until the PGM energy is reached by:
			1. Keep checking the Grating & M2 motors status (DMOV)
			2. Keep checking the energy reached PV
		Notes:
			1. loop conditioning must be satisfied because energy PV is set to 0 before start moving the PGM.
			2. checkToleranceEvery variable can be changed in limits.json file
		"""
		while not self.motors["PGM:Grating"].get("DMOV") or not self.motors["PGM:M2"].get("DMOV") or int(self.PVs["PGM:Energy:Reached"].get(use_monitor=False)) != 1:
			if currentScanInfo != None:
				CLIMessage(f"PGM is moving to {SP} for Sample({currentScanInfo[0]['Sample']}), Scan({currentScanInfo[1]['Scan']}) and Interval({currentScanInfo[2]['Interval']})", "IG")
			else:
				CLIMessage(f"PGM is moving to {SP:.4f}, RBV: {self.PVs['PGM:Energy:RBV'].get():.4f} ... ", "IG")
			time.sleep(0.005)
		"""
		the loop below has been added because the one above was not enough to get energy RBV within the allowed tolerances. The main issue is that energy RBV is a PROC PV
		relies on many parameters to be calculated, this means, after reaching the target positions of the PGM motors the final energy RBV needs some time to be calculated.
		however, the loop does the following:
			1. Periodically checks the energy RBV if it is within the given tolerances, if yes breaks the loop
			2. if not, waits until the maximum wait time condition is met.

		Notes:
			1. energyRBVTolerance, checkToleranceEvery & maxTime2MeetTolerance variables can be changed/defined in the "configurations/limits.json" file
			2. the three variables above have a big impact on the energy precision and scan time.
		"""

		if scanTime is None:
			print("\n")
			timeCounter = 0
			while not(float(SP) - self.scanLimits["energyRBVTolerance"]) <= float(self.PVs["PGM:Energy:RBV"].get()) <= (float(SP) + self.scanLimits["energyRBVTolerance"]):
				self.PVs["PGM:Energy:SP"].put(SP, wait=True)
				time.sleep(self.scanLimits["checkToleranceEvery"])
				timeCounter = timeCounter + 1
				if timeCounter * self.scanLimits["checkToleranceEvery"] >= self.scanLimits["maxTime2MeetTolerance"]:
					log.warning("Reaching maximum wait time to reach the target energy")
					break