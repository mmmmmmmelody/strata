// SPDX-License-Identifier: BSD-3-Clause
/* Copyright 2017-2020, Intel Corporation */

#define flush64b noflush64b
#define flush noflush
#define EXPORTED_SYMBOL memset_mov_avx_noflush
#include "memset_t_avx.h"
