#!/bin/bash

cat $1 >> $1.cpp
g++ $1.cpp
./a.out
rm $1.cpp a.out