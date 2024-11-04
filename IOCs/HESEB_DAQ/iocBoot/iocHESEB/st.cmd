#!../../bin/linux-x86_64/HESEB

< iocBoot/iocHESEB/envPaths

epicsEnvSet("P", "HESEB:")

dbLoadDatabase "dbd/HESEB.dbd"
HESEB_registerRecordDeviceDriver pdbbase

dbLoadTemplate("$(TOP)/iocBoot/iocHESEB/HESEB.substitutions")

iocInit
