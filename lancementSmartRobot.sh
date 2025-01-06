#!/bin/bash

make
make robot
echo temps realise :
time ./algo/bin/mainAlgo $1 | sudo ./elec/bin/mainElec


