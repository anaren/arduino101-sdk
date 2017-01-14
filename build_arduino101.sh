#!/bin/bash

PATH=$PATH:./tools-builder/ctags/5.8-arduino11/:/opt/arduino101-sdk/packages/Intel/tools/arc-elf32/1.6.9+1.0.1/bin

./arduino-builder -build-path $1 -hardware ./hardware -hardware ./packages/Intel/hardware -tools ./packages -tools ./tools-builder -libraries ./packages/Intel/hardware/intel/arc32/libraries -fqbn intel:arc32:arduino_101 $2

pushd $1
pushd ../
arc-elf32-objcopy -O binary arduino101_sketch.debug.elf firmware.bin
popd
popd