#!/bin/bash

cd /home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting;
tmux kill-session -t I0_startAcquire ;
tmux kill-session -t It_startAcquire ;
