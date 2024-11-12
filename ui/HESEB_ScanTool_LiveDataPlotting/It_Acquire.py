import os
import sys
import time
import threading
import argparse
from os.path import exists
from tendo import singleton
from epics import PV

try:
	me = singleton.SingleInstance()
except:
	sys.exit()

dataFilePath = "It.txt"
indexFilePath = "It_Index.txt"

ItPlot = PV("HESEB:Plot:It")
ItIndex = PV("HESEB:Plot:It:Index")
ItReset = PV("K6485:1:RST.PROC")
ItSampling = PV("K6485:1:TimePerSampleStep")
ItRun = PV("HESEB:Run:It")
ItIntTime = PV("K6485:1:IntegrationTime")
ItAcquire = PV("K6485:1:Acquire")
ItAcquireProc = PV("K6485:1:Acquire.PROC")

ItPlot.put(0, wait=True)
ItIndex.put(0, wait=True)

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
	elif intTime == 0.5: 			# 7 Samples
		NPLC 	 	  = 1
		ActualIntTime = 0.45
	elif intTime == 0.75: 			# 11 Samples
		NPLC 	 	  = 1
		ActualIntTime = 0.74
	elif intTime == 1.0: 			# 15 Samples
		NPLC 	 	  = 1
		ActualIntTime = 0.94
	elif intTime == 1.25: 			# 18 Samples
		NPLC 	 	  = 1
		ActualIntTime = 1.12
	elif intTime == 1.5: 			# 12 Samples
		NPLC 	 	  = 2
		ActualIntTime = 1.49
	elif intTime == 1.75: 			# 14 Samples
		NPLC 	 	  = 2
		ActualIntTime = 1.74
	elif intTime == 2.0: 			# 16 Samples
		NPLC 	 	  = 2
		ActualIntTime = 1.99
	elif intTime == 2.25: 			# 17 Samples
		NPLC 	 	  = 2
		ActualIntTime = 2.12
	elif intTime == 2.50: 			# 19 Samples
		NPLC 	 	  = 2
		ActualIntTime = 2.37
	elif intTime == 2.75: 			# 21 Samples
		NPLC 	 	  = 2
		ActualIntTime = 2.61
	elif intTime == 3.0: 			# 23 Samples
		NPLC 	 	  = 2
		ActualIntTime = 2.85
	elif intTime == 3.25:			# 25 Samples
		NPLC 	 	  = 2
		ActualIntTime = 3.11
	elif intTime == 3.5:			# 27 Samples
		NPLC 	 	  = 2
		ActualIntTime = 3.35
	elif intTime == 3.75:			# 29 Samples
		NPLC 	 	  = 2
		ActualIntTime = 3.6
	elif intTime == 4.0:			# 31 Samples
		NPLC 	 	  = 2
		ActualIntTime = 3.84
	elif intTime == 5.0:			# 39 Samples
		NPLC 	 	  = 2
		ActualIntTime = 4.83
	elif intTime == 6.0:			# 47 Samples
		NPLC 	 	  = 2
		ActualIntTime = 5.81
	elif intTime == 7.0:			# 54 Samples
		NPLC 	 	  = 2
		ActualIntTime = 6.68
	elif intTime == 8.0:			# 62 Samples
		NPLC 	 	  = 2
		ActualIntTime = 7.66
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

		ItPlot.put(data, wait=True)
		ItIndex.put(index, wait=True)

		time.sleep(1)

if __name__ == "__main__":

	parser = argparse.ArgumentParser(description='HESEB Live Data Visualization (It vs Time)')
	parser.add_argument('time', type=float)
	args = parser.parse_args()
	intTime = args.time

	try:
		os.remove(dataFilePath)
		os.remove(indexFilePath)
	except:
		pass

	thread = threading.Thread(target=dataToWaveForm, args=(), daemon=True)
	thread.start()

	NPLC, ActualIntTime = getNPLC_IntTime(intTime)
	ItReset.put(1)		# Apply soft reset before start collecting data
	ItSampling.put(0) 	# put 0 in time per step sample
	It_run = ItRun.get()	# trigger to start (0:Start, 1:Stop)

	i = 0
	while(It_run == 1 and i < 3001):

		ItSampling.put(ActualIntTime)
		ItIntTime.put(NPLC)
		ItAcquireProc.put(1)
		time.sleep(0.1)

		while ItAcquireProc.get(timeout=1, use_monitor=False):
			time.sleep(0.1)

		currentPicoRead = ItAcquire.get()
		i = i + 1
		It_run = ItRun.get()

		appendNewLine(dataFilePath, str(currentPicoRead))
		appendNewLine(indexFilePath, str(i))