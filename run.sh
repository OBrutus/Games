#!/bin/bash
echo "compiling..."
g++ ./src/2048.cpp -o 2048
g++ ./src/tower.cpp -o tower
g++ ./src/21-sticks.c -o 21-sticks

if [ $? -ne "0" ]
then
	echo "some err. occured"
	exit
fi

clear
echo "Compiled!"
echo -eE "You can now go for \n'./2048' and '.tower'"
