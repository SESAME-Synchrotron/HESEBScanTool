#!/bin/bash

tmux new -d -s voltageSourceValidation ;
tmux send-keys -t voltageSourceValidation "p3" ENTER ;
tmux send-keys -t voltageSourceValidation "python" Space "voltageSourceValidation.py" ENTER 
