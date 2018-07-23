/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define SYS_LOG_LEVEL SYS_LOG_LEVEL_DEBUG
#define SYS_LOG_DOMAIN "foundries.io/color"

#include <logging/sys_log.h>

void main(void)
{
	SYS_LOG_DBG("verbose debug %d", 3);
	SYS_LOG_INF("everything is fine, mask=0x%x", 0xa1);
	SYS_LOG_WRN("warning: %s was seen", "something bad");
	SYS_LOG_ERR("error %d", 3);
}
