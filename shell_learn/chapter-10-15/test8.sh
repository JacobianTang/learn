#!/bin/sh
var1=10
while echo $var1 
	[ $var1 -gt 0 ]
do
	echo $var1
	var1=$[ $var1-1 ] 
done
