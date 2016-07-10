#!/bin/bash

#file reading
./cat ./sample.txt

if [ $? == 0 ]; then
    echo "test case no.1 succeeded."
else
    echo "test case no.1 failed."
fi

#execute program when filename is empty
./cat

if [ $? == 1 ]; then
    echo "test case no.2 succeeded."
else
    echo "test case no.2 failed."
fi