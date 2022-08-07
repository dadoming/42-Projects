#! /bin/bash

#       ARG="2 3 1 5"; ./push_swap $ARG | ./checker_linux $ARG
#
#       To use just execute the program and input numbers 
#       in prompt, the output will be the same as the whole 
#       command passed in. 

read -p "Enter nums: " ARG
./push_swap $ARG | ./checker_linux $ARG

