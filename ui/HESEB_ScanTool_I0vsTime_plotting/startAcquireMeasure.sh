#!/bin/bash

cd /home/control/HESEBScanTool/ui/HESEB_ScanTool_I0vsTime_plotting ;
tmux new -d -s startAcquireMeasure ;
tmux send-keys -t startAcquireMeasure "p3" ENTER ;
tmux send-keys -t startAcquireMeasure "python" Space "I0_AcquireMeasure.py" ENTER

