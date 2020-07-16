#!/bin/sh
val1=10
val2=11
if [ $val1 -gt 5 ]
then
	echo "the test value $val1 is greater than 5"
fi

if [ $val1 -eq $val2 ]
then
	echo "the values are equal"
else
	echo "the values are different"
fi

