#!/bin/bash

make FILE=$1 \
&& ./main \
&& make clean &>/dev/null