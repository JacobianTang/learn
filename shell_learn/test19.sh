#!/bin/sh
tempdir=`mktemp -d dir.XXXXXX`
cd $tempdir
tempfile1=`mktemp temp.XXXXXX`
tempfile2=`mktemp temp.XXXXXX`
exec 7>$tempfile1
exec 8>$tempfile2
echo "sending data to directory $tempdir"
echo "this is a test line of data for $tempfile1">&7
echo "this is a test line of data for $tempfile2">&8
