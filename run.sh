#!/bin/bash

make FILE=$1 &>/dev/null \
&& ./main \
&& make clean &>/dev/null