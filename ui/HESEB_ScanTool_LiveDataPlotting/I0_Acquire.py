import epics
import sys
import time
from datetime import datetime 
import multiprocessing
import os 
from os.path import exists

def append_new_line(file_name, text_to_append):
    """Append given text as a new line at the end of file"""
    # Open the file in append & read mode ('a+')
    with open(file_name, "a+") as file_object:
        # Move read cursor to the start of file.
        file_object.seek(0)
        # If file is not empty then append '\n'
        data = file_object.read()
        if len(data) > 0:
            file_object.write("\n")
        # Append text at the end of file
        file_object.write(text_to_append)

def getNPLC_IntTime(intTime):
	"""
	As we use the averaging filter of KIETHELY, the device it self does not 
	accept integration time to be entered directlly. The actual integration time 
	is defined by this equation:  
		3∗NPLC/50∗(NumSamples∗1.0285)+ε
	where: 
		ε = 0.0076172
		3: collapses to 1 when AutoZero is disabled.
	
	By providing NPLC and the pre-caculated ActualIntTime, the IOC can 
	calculate the NumSamples and then send it as well as the NPLC to the keithley 
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
    I0Data = []
    I0Index = []
    fileExistTrigger = 0

    while True:
        I0Data = []
        I0Index = []
        
        if os.path.exists("I0_Index.txt"):
            I0IndexFile = open('I0_Index.txt', 'r')
            I0IndexLines = I0IndexFile.readlines()
            # Strips the newline character
            for line in I0IndexLines:
                I0Index.append(int(line.strip()))
                #print (I0Index)
                # epics.PV("I0:PLOT:INDEX").put(I0Index, wait = True)
                #time.sleep(1)
        else:
            pass

        if os.path.exists("I0.txt"):
            print("FFFFFFF")
            I0File = open('I0.txt', 'r')
            I0Lines = I0File.readlines()
            # Strips the newline character
            for line1 in I0Lines:
                I0Data.append(float(line1.strip()))
                print(I0Data)
                # epics.PV("PLOT:I0").put(I0Data, wait = True)
                #time.sleep(1)
        else:
            print("No file")
            pass
        epics.PV("PLOT:I0").put(I0Data, wait = True)
        epics.PV("I0:PLOT:INDEX").put(I0Index, wait = True)
        
        print("----------------------------------------")
        
       
        time.sleep(1)

    time.sleep(1)
    print ("Sleep")

try:
	os.remove("/home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting/I0.txt")
	os.remove("/home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting/I0_Index.txt")
except:
   print ("did not find the file")
   pass


p1 = multiprocessing.Process(target=dataToWaveForm, args=())
p1.start()



intTime_ = epics.PV("I0:INT:TIME").get()
NPLC, ActualIntTime = getNPLC_IntTime(intTime_)
epics.PV("K6487:1:RST.PROC").put(1) # apply soft reset before start collecting data 
epics.PV("K6487:1:Damping").put(0) # disable damping 
epics.PV("K6487:1:TimePerSampleStep").put(0) # put 0 in time per step sample
I0_run = epics.PV("I0:RUN").get()
time.sleep(0.1)

i = 0
data = []
dataIndex = []

#epics.PV("PLOT:I0").put(data, wait = True)
#epics.PV("I0:PLOT:Index").put(dataIndex, wait = True)

while(I0_run == 0):

    I0_run = epics.PV("I0:RUN").get()
    sleepTime = 0.1
    timerCounter = 0 

    epics.PV("K6487:1:TimePerSampleStep").put(ActualIntTime)
    epics.PV("K6487:1:IntegrationTime").put(NPLC) ## int. time 
    

    picoReadOut = epics.PV("K6487:1:Acquire").get()
    epics.PV("K6487:1:Acquire.PROC").put(1)
    time.sleep(0.1)

    while True:
        currentPicoRead = epics.PV("K6487:1:Acquire").get()
        if picoReadOut == currentPicoRead:
            pass
            timerCounter = timerCounter + 1

        else:

            #data.append(epics.PV("K6487:1:Acquire").get())
            dataIndex.append(i)
            break

        time.sleep(sleepTime)

        if timerCounter * sleepTime >= ActualIntTime * 1.5:
            break
  
        
    i= i+1
  
    append_new_line ("I0.txt", str(currentPicoRead))
    append_new_line ("I0_Index.txt", str(i))


I0_run = epics.PV("I0:RUN").get()
if (I0_run == 1):

    sys.exit()

if __name__ == "__main__":
    print("dddss")
