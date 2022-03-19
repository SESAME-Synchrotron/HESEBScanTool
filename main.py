#!/usr/bin/python3.6

import sys
import argparse

try:
	import numpy as np
	import epics
	from PyQt5 import QtWidgets
except ImportError as error:
	print("Please ensure that the following packages are installed properly:\n ")
	print("pyepics\nnumpy\nPyQt5\n")
	sys.exit()

import heseb

app = QtWidgets.QApplication(sys.argv)

#########################################################
parser = argparse.ArgumentParser(description="XAFS/XRF Scanning Tool "\
 "is a software developed by DCA at SESAME to collect exprimintal data from XAFS / XRF Beamline at SESAME ")
parser.add_argument('--testingMode', type=str,default = "No" ,help="Yes/No, default is No")
#########################################################
args = parser.parse_args()
tMode = args.testingMode


if __name__ == "__main__":
    heseb.HESEBSCAN(testingMode = tMode)
    sys.exit(app.exit())
