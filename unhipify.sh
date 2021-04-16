#!/usr/bin/env bash

# Unhipify all sources
cd src
for f in *.cu; do 
  cp ${f}.prehip $f && rm ${f}.prehip
done

for f in *.c; do
  cp ${f}.prehip $f && rm ${f}.prehip
done

for f in *.h; do
  cp ${f}.prehip $f && rm ${f}.prehip
done
cd ..

cp include/darknet.h.prehip include/darknet.h && rm include/darknet.h.prehip