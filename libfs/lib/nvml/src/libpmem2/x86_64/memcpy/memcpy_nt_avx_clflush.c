// SPDX-License-Identifier: BSD-3-Clause
/* Copyright 2017-2018, Intel Corporation */

#define flush flush_clflush_nolog
#define EXPORTED_SYMBOL memmove_movnt_avx_clflush
#define maybe_barrier barrier_after_ntstores
#include "memcpy_nt_avx.h"
