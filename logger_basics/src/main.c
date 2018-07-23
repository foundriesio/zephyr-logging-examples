/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Display all messages, including debugging ones: */
#define LOG_LEVEL LOG_LEVEL_DBG

/* Set the "module" for these log messages: */
#define LOG_MODULE_NAME foundries_io_basics

#include <logging/log.h>

/* Initialize module-specific magic state: */
LOG_MODULE_REGISTER();

void main(void)
{
	LOG_DBG("verbose debug %d", 3);
	LOG_INF("everything is fine, mask=0x%x", 0xa1);
	LOG_WRN("warning: %s was seen", "something bad");
	LOG_ERR("error %d", 3);
}
