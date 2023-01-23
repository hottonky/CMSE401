#!/bin/bash

start=`date +%s`
g++ simulation.cpp
./a.out
end=`date +%s`

runtime_cpp=$((end-start))


start=`date +%s`
python make_frames.py
end=`date +%s`
runtime_py=$((end-start))

ffmpeg -y -framerate 30 -i Frames/frame_%06d.png wave!.mp4

echo C++ runtime:
echo $runtime_cpp

echo Python runtim:
echo $runtime_py