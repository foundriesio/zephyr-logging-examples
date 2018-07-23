/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Filter out any messages more verbose than the WARNING level. */
#define SYS_LOG_LEVEL SYS_LOG_LEVEL_WARNING
#define SYS_LOG_DOMAIN "foundries.io/filtered"
#include <logging/sys_log.h>

void main(void)
{
	SYS_LOG_DBG("this message will not appear; DBG is too verbose");
	SYS_LOG_WRN("this warning appears (WRN is the minimum verbosity)");
	SYS_LOG_ERR("this error appears too (ERR is less verbose than WRN)");
}
