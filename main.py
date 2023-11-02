#!/usr/bin/python3.6

import sys
import argparse
from common import Common
import config

from engScan import ENGSCAN

try:
	import numpy as np
	import epics
	from PyQt5 import QtWidgets
except ImportError as error:
	print("Please ensure that the following packages are installed properly:\n ")
	print("pyepics\nnumpy\nPyQt5\n")
	sys.exit()

# import heseb

app = QtWidgets.QApplication(sys.argv)

#########################################################
parser = argparse.ArgumentParser(description="XAFS/XRF Scanning Tool "\
 "is a software developed by DCA at SESAME to collect exprimintal data from XAFS / XRF Beamline at SESAME ")
parser.add_argument('--testingMode', type=str,default = "No" ,help="Yes/No, default is No")
#########################################################
args = parser.parse_args()
tMode = args.testingMode


if __name__ == "__main__":
	paths	= Common.loadjson("configrations/paths.json")
	cfg		= config.ConfigGUI(paths).cfg

	cfg['scanType'] = 'stepEngScan' # temprory hard codded untill adding Mapping scan 

	if cfg['scanType'] == 'stepEngScan':
		ENGSCAN(paths = paths, cfg = cfg, testingMode = tMode)
	elif cfg['scanType'] == 'stepMapScan':
		MAPSCAN(paths = paths, cfg = cfg, testingMode = tMode)

	sys.exit(app.exit())
