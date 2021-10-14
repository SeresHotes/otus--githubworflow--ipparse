#!/bin/bash
echo "hello"
cat ${2} | ${1} | dos2unix > output.txt
echo '24e7a7b2270daee89c64d3ca5fb3da1a  output.txt' | md5sum -c
a=$?
rm output.txt
exit $a