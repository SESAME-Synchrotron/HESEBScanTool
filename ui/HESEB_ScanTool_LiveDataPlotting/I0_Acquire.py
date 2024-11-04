import os
import sys
import time
import multiprocessing
from os.path import exists
from epics import PV

dataFilePath = "I0.txt"
indexFilePath = "I0_Index.txt"

I0Plot = PV("PLOT:I0")
I0Index = PV("I0:PLOT:INDEX")
I0IntTimeGUI = PV("I0:INT:TIME")
I0Reset = PV("K6487:1:RST.PROC")
I0Damping = PV("K6487:1:Damping") 			
I0Sampling = PV("K6487:1:TimePerSampleStep")
I0Run = PV("I0:RUN")
I0IntTime = PV("K6487:1:IntegrationTime")
I0Acquire = PV("K6487:1:Acquire")
I0AcquireProc = PV("K6487:1:Acquire.PROC")

def appendNewLine(fileName, txt):
	"""Append given text as a new line at the end of file"""

	with open(fileName, "a+") as f:
		f.seek(0)
		data = f.read()
		if len(data) > 0:
			f.write("\n")
		f.write(txt)

def getNPLC_IntTime(intTime):
	"""
	As we use the averaging filter of KEITHELY, the device it self does not
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

def dataToWaveForm():

	while True:
		data = []
		index = []

		if os.path.exists(indexFilePath):
			indexFile = open(indexFilePath, 'r')
			indexLines = indexFile.readlines()
			for line in indexLines:
				index.append(int(line.strip()))

		if os.path.exists(dataFilePath):
			dataFile = open(dataFilePath, 'r')
			dataLines = dataFile.readlines()

			for line in dataLines:
				data.append(float(line.strip()))

		I0Plot.put(data, wait=True)
		I0Index.put(index, wait=True)

		time.sleep(1)

if __name__ == "__main__":

	try:
		os.remove(dataFilePath)
		os.remove(indexFilePath)
	except:
		pass

	p1 = multiprocessing.Process(target=dataToWaveForm, args=())
	p1.start()

	intTime_ = I0IntTimeGUI.get()		# Integration time from GUI
	NPLC, ActualIntTime = getNPLC_IntTime(intTime_)
	I0Reset.put(1)		# Apply soft reset before start collecting data.
	I0Damping.put(0) 	# disable damping
	I0Sampling.put(0) 	# put 0 in time per step sample
	I0_run = I0Run.get()	# I0:RUN >> trigger to start (0:Start, 1:Stop).

	i = 0
	while(I0_run == 0 and i < 3001):

		I0Sampling.put(ActualIntTime)
		I0IntTime.put(NPLC)
		I0AcquireProc.put(1)
		time.sleep(0.1)

		while I0AcquireProc.get(timeout=1, use_monitor=False):
			time.sleep(0.1)

		currentPicoRead = I0Acquire.get()
		i =+1
		I0_run = I0Run.get()

		appendNewLine(dataFilePath, str(currentPicoRead))
		appendNewLine(indexFilePath, str(i))

	I0_run = I0Run.get()
	if (I0_run == 1 or i >= 3000):
		sys.exit()
