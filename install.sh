#!/bin/bash

module load gcc/10.2.0

make clean
#sed -i 's/GPU=0/GPU=1/g' Makefile
#sed -i 's/OPENCV=0/OPENCV=1/g' Makefile
export GPU_PLATFORM=nvcc
export HIP_PLATFORM=nvcc
export HIP_RUNTIME=NVCC
#export HCC_AMDGPU_TARGET=gfx906
#export HIP_GPU=sm_70

make

