#!/bin/bash

make
make robot
echo temps realise :
time ./mainAlgo $1 | sudo./mainElec
