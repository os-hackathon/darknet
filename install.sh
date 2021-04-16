#!/bin/bash

module load gcc/10.2.0

make clean
#sed -i 's/GPU=0/GPU=1/g' Makefile
#sed -i 's/OPENCV=0/OPENCV=1/g' Makefile
export HIP_RUNTIME=NVCC
export HIP_PLATFORM=nvcc

make

