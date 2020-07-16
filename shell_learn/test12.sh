#!/bin/sh
#redirecting file input
exec 0< testfile
count=1
while read line
do
	echo "line #$count: $line"
	count=$[ $count +1 ]
done

