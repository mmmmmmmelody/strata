#! /bin/bash

PATH=$PATH:.
export LD_LIBRARY_PATH=/home/JWQ/strata-master/libfs/lib/nvml/src/nondebug/:/home/JWQ/strata-master/libfs/build

LD_PRELOAD=../../libfs/lib/syscall_intercept/build/libsyscall_intercept.so.0.1.0:../../libfs/lib/jemalloc-4.5.0/lib/libjemalloc.so.2 ${@}
#LD_PRELOAD=../../shim/libshim/libshim.so:../lib/jemalloc-4.5.0/lib/libjemalloc.so.2 MLFS_PROFILE=1 ${@}
