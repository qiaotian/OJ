#!/bin/bash

function usage() {
	echo 
	echo " ===== Warning ====="
	echo "You must run this script at  ~/workspace/China_Intern_Cpp directory"
	echo 
	echo "Usage : $0 (InternId) (YourName(No space))"
	echo "   Ex : $0 001 YeMao "
}

## main

pwd | grep China_Intern_Cpp
if [ $? -ne 0 ];then
	usage
	exit 1
fi

if [ $# -lt 2 ];then
	usage
	exit 1
fi

number=$1
name=$2

tar zcvf ${number}_${name}_Project.tar.gz `find . -maxdepth 1 -type d ! -name "Debug" | grep -v -e "^.$" -e "./csv_org" -e "./csv_mass"`

echo
echo "${number}_${name}_Project.tar.gz Created. "
ls -l ${number}_${name}_Project.tar.gz

