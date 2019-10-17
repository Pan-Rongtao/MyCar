#!/bin/bash
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../dist/x11 ..
make
make install
