#!/bin/sh
exec 1>testout
echo "This is test of redirectiong all about"
echo "from a scipt to another file"
echo "without having to redirect every individual line"

exec 2>testerror
echo "but this shoud go to the testerror" >&2 
echo "this output should to the testout"
