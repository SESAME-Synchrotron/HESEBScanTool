TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = HESEB
# HESEB.dbd will be created and installed
DBD += HESEB.dbd

# HESEB.dbd will be made up from these files:
HESEB_DBD += base.dbd

# Include dbd files from all support applications:
#HESEB_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#HESEB_LIBS += xxx

# HESEB_registerRecordDeviceDriver.cpp derives from HESEB.dbd
HESEB_SRCS += HESEB_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
HESEB_SRCS_DEFAULT += HESEBMain.cpp
HESEB_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#HESEB_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
HESEB_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

