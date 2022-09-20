#!/bin/bash

if [ $# -ne 2 ] ; then
    echo "Need exactly 2 arguments (file and directory)"
    exit 1
fi
if [ ! -f $1 ] ; then
    echo "First argument should be a file"
    exit 1
fi
if [ ! -d $2 ] ; then
    echo "Second argument should be a directory"
    exit 1
fi

if [ -n "$(ls -A $2 2>/dev/null)" ] ; then 
    for file in $2/* ;
        do if diff -q -w -i -B $1 $file &>/dev/null ; then
            echo "Plagiarism detected, files are the same"
            exit 1
        fi
    done
fi

mv $1 $2/
