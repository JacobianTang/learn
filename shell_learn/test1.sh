#!/bin/sh
trap "echo 'Sorry! I have trapped ctrl_c'" SIGINT SIGTERM
echo this is a test program
count=1
while [ $count -le 10 ]
do
	echo "Loop #$count"
	sleep 1
	count=$[$count +1]
done
echo this is end of test program
