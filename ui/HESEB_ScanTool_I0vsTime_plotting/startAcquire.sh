#!/bin/bash

cd /home/control/HESEBScanTool/ui/HESEB_ScanTool_I0vsTime_plotting ;
tmux new -d -s startAcquire ;
tmux send-keys -t startAcquire "p3" ENTER ;
tmux send-keys -t startAcquire "python" Space "I0_Acquire.py" ENTER 
