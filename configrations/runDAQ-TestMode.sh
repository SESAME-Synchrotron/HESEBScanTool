#!/bin/bash

cd /home/control/HESEBScanTool;

tmux kill-session -t HESEB_DAQ
tmux new -d -s HESEB_DAQ ;
tmux send-keys -t HESEB_DAQ "p3" ENTER ;
tmux send-keys -t HESEB_DAQ "python" Space "main.py" Space "--testingMode" Space "yes" ENTER
                                                                              

#cd /home/control/HESEBScanTool
#p3
#python main.py --testingMode yes
