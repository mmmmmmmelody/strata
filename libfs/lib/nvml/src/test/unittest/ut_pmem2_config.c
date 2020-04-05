// SPDX-License-Identifier: BSD-3-Clause
/* Copyright 2019-2020, Intel Corporation */

/*
 * ut_pmem2_config.h -- utility helper functions for libpmem2 config tests
 */

#include <libpmem2.h>
#include "unittest.h"
#include "ut_pmem2_config.h"
#include "ut_pmem2_utils.h"

/*
 * ut_pmem2_config_new -- allocates cfg (cannot fail)
 */
void
ut_pmem2_config_new(const char *file, int line, const char *func,
	struct pmem2_config **cfg)
{
	int ret = pmem2_config_new(cfg);
	ut_pmem2_expect_return(file, line, func, ret, 0);

	UT_ASSERTne(*cfg, NULL);
}

/*
 * pmem2_config_set_required_store_granularity -- sets granularity
 */
void
ut_pmem2_config_set_required_store_granularity(const char *file, int line,
	const char *func, struct pmem2_config *cfg, enum pmem2_granularity g)
{
	int ret = pmem2_config_set_required_store_granularity(cfg, g);
	ut_pmem2_expect_return(file, line, func, ret, 0);
}

/*
 * ut_pmem2_config_delete -- deallocates cfg (cannot fail)
 */
void
ut_pmem2_config_delete(const char *file, int line, const char *func,
	struct pmem2_config **cfg)
{
	int ret = pmem2_config_delete(cfg);
	ut_pmem2_expect_return(file, line, func, ret, 0);

	UT_ASSERTeq(*cfg, NULL);
}

/*
 * ut_pmem2_source_from_fd -- sets fd (cannot fail)
 */
void
ut_pmem2_source_from_fd(const char *file, int line, const char *func,
	struct pmem2_source **src, int fd)
{
	int ret = pmem2_source_from_fd(src, fd);
	ut_pmem2_expect_return(file, line, func, ret, 0);
}

void
ut_pmem2_source_from_fh(const char *file, int line, const char *func,
	struct pmem2_source **src, struct FHandle *f)
{
	enum file_handle_type type = ut_fh_get_handle_type(f);
	int ret;
	if (type == FH_FD) {
		int fd = ut_fh_get_fd(file, line, func, f);
#ifdef _WIN32
		ret = pmem2_source_from_handle(src, (HANDLE)_get_osfhandle(fd));
#else
		ret = pmem2_source_from_fd(src, fd);
#endif
	} else if (type == FH_HANDLE) {
#ifdef _WIN32
		HANDLE h = ut_fh_get_handle(file, line, func, f);
		ret = pmem2_source_from_handle(src, h);
#else
		ut_fatal(file, line, func,
				"FH_HANDLE not supported on !Windows");
#endif
	} else {
		ut_fatal(file, line, func,
				"unknown file handle type");
	}
	ut_pmem2_expect_return(file, line, func, ret, 0);
}

void
ut_pmem2_source_delete(const char *file, int line, const char *func,
	struct pmem2_source **src)
{
	int ret = pmem2_source_delete(src);
	ut_pmem2_expect_return(file, line, func, ret, 0);

	UT_ASSERTeq(*src, NULL);
}
