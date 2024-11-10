#!../../bin/linux-x86_64/HESEB

< iocBoot/iocHESEB/envPaths

epicsEnvSet("EPICS_CA_MAX_ARRAY_BYTES", 2000000)
epicsEnvSet("P", "HESEB:")

dbLoadDatabase "dbd/HESEB.dbd"
HESEB_registerRecordDeviceDriver pdbbase

dbLoadTemplate("$(TOP)/iocBoot/iocHESEB/experiment.substitutions")
dbLoadTemplate("$(TOP)/iocBoot/iocHESEB/plot.substitutions")
dbLoadTemplate("$(TOP)/iocBoot/iocHESEB/others.substitutions")

iocInit
