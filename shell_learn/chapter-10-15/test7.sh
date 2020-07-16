#!/bin/sh
dir=~/learn/*
for file in $dir
do
	if [ -d $file ]
	then
		echo "this is a directory $file"
	elif [ -f $file ]
	then
		echo "this is a file $file"
	fi
done
