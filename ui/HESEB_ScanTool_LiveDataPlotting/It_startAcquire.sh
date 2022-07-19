#!/bin/bash

cd /home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting;
tmux new -d -s It_startAcquire ;
tmux send-keys -t It_startAcquire "p3" ENTER ;
tmux send-keys -t It_startAcquire "python" Space "It_Acquire.py" ENTER 
