import sys
import time
import epics 
from SEDSS.SEDSupport import readFile
from SEDSS.SEDSupplements import UIMessage

''' The main purpose of this script is to check the scan is stucked or so on..., if yes the scan will stopped within 1 second '''

voltagePVs = readFile("pvlist/KEITHLEY_I0.json").readJSON()     
HESEB_PVs  = readFile("pvlist/HESEB.json").readJSON()

def countdown(t):
    
    while t:
        mins, secs = divmod(t, 60)
        timer = '{:02d}:{:02d}'.format(mins, secs)
        print(timer, end="\r")
        time.sleep(1)
        t -= 1

while True:

    voltageSourceValue  = epics.PV(voltagePVs["PV"]["voltageSourceRange"]["pvname"]).get()
    pausingStatus       = epics.PV(HESEB_PVs["PV"]["SCAN:pause"]["pvname"]).get()
    pointsStatus        = epics.PV(HESEB_PVs["PV"]["PGM:Energy:RBV"]["pvname"]).get()
    
    if epics.PV("SCAN:STOP").get() == 1:
        sys.exit()
        
    if voltageSourceValue in {1,2}:
        if (pausingStatus == 1) or pointsStatus == epics.PV(HESEB_PVs["PV"]["PGM:Energy:RBV"]["pvname"]).get():
            
            print(voltageSourceValue,    pausingStatus,      pointsStatus)
            countdown(int(60))

            if voltageSourceValue in {1,2}:
                if (pausingStatus == 1) or pointsStatus == epics.PV(HESEB_PVs["PV"]["PGM:Energy:RBV"]["pvname"]).get():

                    epics.PV("VOLTAGE:VALIDATION").put(1)
                    # UIMessage("Scan is stopped","Scan has been stopped","No scan activities have been seen over the last one minute.")
                    # sys.exit()
                    
    time.sleep(1)
