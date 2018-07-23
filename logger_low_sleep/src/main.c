/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_LEVEL LOG_LEVEL_DBG
#define LOG_MODULE_NAME foundries_io_sleep
#include <logging/log.h>
LOG_MODULE_REGISTER();

void main(void)
{
	printk("main() started\n");
	LOG_DBG("verbose debug %d", 3);
	LOG_INF("everything is fine, mask=0x%x", 0xa1);
	LOG_WRN("warning: %s was seen", "something bad");
	LOG_ERR("error %d", 3);
}
