#!/bin/bash			##to call shell(bash)

## Shell script for controlling LEDs in 4-circuit ladder
## On a root shell:
## ./ctrl.sh 1 for on
## ./ctrl.sh 0 for off

set -x				##to print whatever you are executing on shell

gpios=(47 48 49 60)		##array of pins
state=${1:-0}			## for user input (1 stands for user has passed : 0 is default value)

echo "Usage: $0 0/1 for off/on"	##echo for user to understand what to pass

for i in "${gpios[@]}"		##for i in the length of array(i will go from 0 to length of array)
do				## { for for loop
	echo $state > /sys/class/gpio/gpio$i/value	##command to pass value to the gpio value var
done				## } for for loop
