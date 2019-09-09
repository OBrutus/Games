#!/bin/bash
echo "compiling..."
g++ ./src/2048.cpp -o 2048
g++ ./src/tower.cpp -o tower

if [ $? -ne "0" ]
then
	echo "some err. occured"
	exit
fi

clear
echo "Compiled!"
echo -eE "You can now go for \n'./2048' and '.tower'"
