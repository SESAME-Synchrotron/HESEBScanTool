import epics
import time

def access_rights_callback(read_access, write_access, pv=None):
    print ("{} - read={}, write={}".format(pv.pvname, read_access, write_access))

# should immediately see the message upon connection
apv = epics.PV('I11R1-MO-MC2:OH-GRATING-STP-ROTX', access_callback=access_rights_callback)

try:
    start = time.time()
    while (time.time() - start) < 30:
        time.sleep(0.25)
except KeyboardInterrupt:
    pass