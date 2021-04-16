#!/usr/bin/env bash

# Hipify all sources
cd src
for f in *.cu; do 
  hipify-perl -inplace $f;
  sed -i 's/<< </<<</g' $f
  sed -i 's/>> >/>>>/g' $f
done

for f in *.c; do
  hipify-perl -inplace $f;
done

for f in *.h; do
  hipify-perl -inplace $f;
done
cd ..

hipify-perl -inplace include/darknet.h

# Build for AMD GPUs
HIP_PLATFORM=amd make          # For ROCM 4.1
# HIP_PLATFORM=hcc make        # For ROCM 4.0