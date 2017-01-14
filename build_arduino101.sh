#!/bin/sh

PATH=$PATH:./tools-builder/ctags/5.8-arduino11/

./arduino-builder -build-path $1 -hardware ./hardware -hardware ./packages/Intel/hardware -tools ./packages -tools ./tools-builder -libraries ./packages/Intel/hardware/intel/arc32/libraries -fqbn intel:arc32:arduino_101 $2
