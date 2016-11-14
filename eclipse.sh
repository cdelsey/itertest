#!/bin/bash

CURR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SRC_DIR=${CURR_DIR}
BUILD_DIR=${CURR_DIR}/..

set -e
cd $BUILD_DIR
export CC=clang
export CXX=clang++
cmake -DCMAKE_BUILD_TYPE=Debug $SRC_DIR