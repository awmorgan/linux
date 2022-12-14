#!/usr/local/bin/bash

# this script will get the header dependencies for a given c file
# and copy them to the myusb directory maintaining the directory
# structure

# print all the commands
#set -x

# the first argument is the .o file that the c file will be compiled to
o_file=$1

# remove the .o file if it exists
if [ -f $o_file ]; then
    rm $o_file
fi

# this is the command to build the .o file
cmd="lkmake ARCH=arm64 CC=clang CROSS_COMPILE=aarch64-linux-gnu- $o_file V=1"
# cmd="lkmake ARCH=arm64 CC=clang CROSS_COMPILE=aarch64-linux-gnu- $o_file --dry-run"
# $cmd
# exit

# run the command and save the output to a variable
output=$($cmd)

# for each line in the output, if it starts with 1 or more spaces and clang or
# just clang, then save it to cmd1
cmd1=$(echo "$output" | grep -E "^(clang| {1,}clang)")

# now the cmd1 variable should have this substring in it: "-o drivers/scsi/scsi.o"
# now take the command and replace the "-o drivers/scsi/scsi.o" with "-E -o drivers/scsi/scsi.o"
# use a different delimiter in sed so that the / in the path doesn't cause problems
cmd2=$(echo "$cmd1" | sed "s#-o $o_file#-E -o $o_file#")

# find the brew clang, in a bin directory
# find /usr/local/Cellar/llvm -name clang
clang_cmd=$(find /usr/local/Cellar/llvm -name clang | grep bin)

# replace the clang command with the brew clang command in cmd2
cmd2=$(echo "$cmd2" | sed "s#clang#$clang_cmd#")

# now run the new command
$cmd2

# now get the dependencies from the preprocessed c file
# grep the o_file for the lines that begin with " # 1 "
grep -E "^# 1 " $o_file | awk '{print $3}' | sort | uniq | sed "s#\"##g" | grep -v '<built-in>' | grep -v '<command' > $o_file.dep

# now copy the dependencies to the myusb directory
# for each line in the dep file, copy the file to the myusb directory maintaining the directory structure
while read line; do
    # get the directory of the file
    dir=$(dirname $line)
    # make the directory in the myusb directory
    mkdir -p myusb/$dir
    # copy the file to the myusb directory
    cp $line myusb/$dir
done < $o_file.dep

# now remove the .o file and the .o.dep file
rm $o_file
rm $o_file.dep

