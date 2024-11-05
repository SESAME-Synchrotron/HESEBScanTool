import os
import sys
import argparse

from common import Common
import config
from engScanStep import ENGSCANSTEP
from engScanCont import ENGSCANCONT

try:
	import numpy as np
	import epics
	from PyQt5 import QtWidgets
except ImportError as error:
	print("Please ensure that the following packages are installed properly:\n ")
	print("pyepics\nnumpy\nPyQt5\n")
	sys.exit()

app = QtWidgets.QApplication(sys.argv)

parser = argparse.ArgumentParser(description="HESEB Scanning Tool is a software developed by DCA at SESAME to collect experimental data from HESEB Beamline at SESAME")
parser.add_argument("--testingMode", type=str, default="No" ,help="Yes/No, default is No")
args = parser.parse_args()
tMode = args.testingMode


if __name__ == "__main__":

	epics.PV("SCAN:STOP").put(1)
	os.system("killall HESEB_ScanTool_LiveDataVisualization")
	epics.PV("SCAN:STOP").put(0)		# in order to enable voltage source
	paths	= Common.loadjson("configurations/paths.json")
	cfg		= config.ConfigGUI(paths).cfg

	cfg['scanType'] = 'contScan'		 # temporary hard codded until adding Mapping scan 

	if cfg['scanType'] == 'stepEngScan':
		ENGSCANSTEP(paths=paths, cfg=cfg, testingMode=tMode)
	if cfg['scanType'] == 'contScan':
		ENGSCANCONT(paths=paths, cfg=cfg, testingMode=tMode)
	# elif cfg['scanType'] == 'stepMapScan':
	# 	MAPSCAN(paths=paths, cfg=cfg, testingMode=tMode)

	sys.exit(app.exit())
