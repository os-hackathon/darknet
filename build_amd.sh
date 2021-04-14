#!/usr/bin/env bash

# Hipify all sources
cd src
for f in *.cu; do 
  hipify-perl -inplace $f; 
done

for f in *.c; do
  hipify-perl -inplace $f;
done

for f in *.h; do
  hipify-perl -inplace $f;
done
cd ..

hipify-perl -inplace include/darknet.h
