#!/bin/bash
# Author: yousni

writefile="$1"
writestr="$2"

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "Missing argument !!"
    echo "Usage: $0 <arg1> <arg2>"
    echo "<arg1> is  is a full path to a file"
    echo "<arg2> is a text string which will be written within this file"
    exit 1
fi

mkdir -p "$(dirname "$writefile")"

if ! echo "$writestr" > "$writefile"; then 
    echo "File does not exist"
    exit 1
fi