#!/bin/sh
list_var="Nevada job self"
IFS=$'\n'

for var in `cat ./test1.sh`
do
	echo $var
done
