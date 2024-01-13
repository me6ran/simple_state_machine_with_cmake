#!/bin/bash
BUILD_DIR=build
mkdir -p $BUILD_DIR
# cd build/
cmake -DCMAKE_BUILD_TYPE=Debug -B$BUILD_DIR -H.
cmake --build $BUILD_DIR -- VERBOSE=2
