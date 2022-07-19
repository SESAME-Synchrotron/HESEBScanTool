import epics
import sys
import time
from datetime import datetime


intTime_ = epics.PV("INT:TIME").get()
intTime_ = 1
epics.PV("K6487:1:RST.PROC").put(1) # apply soft reset before start collecting data 
#epics.PV("K6487:1:Damping").put(0) # disable damping 
#epics.PV("K6487:1:TimePerSampleStep").put(0) # put 0 in time per step sample
CalibrationEnergy = epics.PV("CALIB:ENERGY").get() # PV to avoid running scanning tool and live data visualization in the sme time
epics.PV("K6487:1:Measure.DISA").put(1) 

i = 0
data = []
dataIndex = []
streamedData = []

#while(CalibrationEnergy == 0): # 1 stoped, 0 go 
while(1): # 1 stoped, 0 go 

    #CalibrationEnergy = epics.PV("CALIB:ENERGY").get() 
    sleepTime = 0.05
    timerCounter = 0 
    avgValue = 0

    #time.sleep(0.2)
    epics.PV("K6487:1:Measure.DISA").put(0) # enable measuring process

    while (timerCounter * sleepTime <= intTime_):

        streamedData.append(epics.PV("K6487:1:Measure").get())
        timerCounter = timerCounter + 1
        time.sleep(sleepTime)

    print(time.strftime("%H:%M:%S", time.localtime()))      
    time.sleep(0.05)
    #avgValue = sum(streamedData) / len(streamedData)
            
    #i= i+1
    #data.append(avgValue)
    #dataIndex.append(i)
    #epics.PV("PLOT:I0").put(data, wait = True)
    
    #epics.PV("PLOT:INDEX").put(dataIndex, wait = True)

    #if i % 10 == 0:
        #pass
    	#print(i)
    	#epics.PV("K6487:1:RST:PROC").put(1)
    	#epics.PV("K6487:1:Damping").put(0)
    	#epics.PV("K6487:1:TimePerSampleStep").put(0)
    	
CalibrationEnergy = epics.PV("CALIB:ENERGY").get()
if (CalibrationEnergy == 1):

    epics.PV("K6487:1:Measure.DISA").put(1) 
    time.sleep(sleepTime)
    sys.exit()

