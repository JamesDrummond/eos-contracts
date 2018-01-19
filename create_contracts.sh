#!/bin/bash
cd /eos
cmake -H. -B"/tmp/build" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_LLVM_CONFIG=/opt/wasm/bin/llvm-config -DCMAKE_CXX_COMPILER=clang++ \
      -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/mnt/eos  -DSecp256k1_ROOT_DIR=/usr/local
cmake --build /tmp/build --target install