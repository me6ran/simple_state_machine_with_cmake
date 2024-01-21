#!/bin/bash
BUILD_DIR=build
mkdir -p $BUILD_DIR
TARGET=""
while getopts "t:" opt; do
  case $opt in
    t) TARGET="--target $OPTARG" ;;
    \?) echo "Invalid option -$OPTARG" >&2
        exit 1 ;;
  esac
done

# cd build/
cmake -DCMAKE_BUILD_TYPE=Debug -B$BUILD_DIR -H.
cmake --build $BUILD_DIR $TARGET -- VERBOSE=2
