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
    countDownLen = intTime_ 

    #time.sleep(0.2)
    epics.PV("K6487:1:Measure.DISA").put(0) # enable measuring process

    while (countDownLen <= intTime_):
        mins, secs = divmod(countDownLen, 60)
        timer = '{}:{}'.format(mins, secs)
        print(timer, end="\r")
        countDownLen -=0.01
        streamedData.append(epics.PV("K6487:1:Measure").get())
        time.sleep(sleepTime)

    #print(time.strftime("oo %H:%M:%S", time.localtime()))      
    #time.sleep(0.05)
    
