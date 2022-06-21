import subprocess

import sys, string, os

#from matplotlib.pyplot import cla

plotI0 = "/home/control/bin/HESEB_ScanTool_I0"
plotI0_It = "/home/control/bin/HESEB_ScanTool"


class anas():
    def plotting(self):
        detectors = [1,2]
        if 1 in detectors:
            self.plotting = plotI0_It

        else:
            self.plotting = plotI0

        subprocess.Popen(self.plotting)

a = anas()
a.plotting()
