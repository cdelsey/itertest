#!/bin/bash

CURR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SRC_DIR=${CURR_DIR}
BUILD_DIR=${CURR_DIR}/output/debug
NUMJOBS=$(expr `nproc` \* 2)

set -e
mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake -DCMAKE_BUILD_TYPE=Debug $SRC_DIR
make -j${NUMJOBS} $1