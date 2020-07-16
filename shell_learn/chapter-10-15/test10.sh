#!/bin/sh
count=1
cat /etc/passwd | while read line
do 
	echo "Line #$count :$line"
	count=$[ $count + 1 ]
done
