/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_LEVEL LOG_LEVEL_DBG
#define LOG_MODULE_NAME foundries_io_dumping
#include <logging/log.h>
LOG_MODULE_REGISTER();

void main(void)
{
	unsigned char data[] = {0xde, 0xad, 0xbe, 0xef,
				'd', 'e', 'a', 'd',
				'b', 'e', 'e', 'f',
				0xde, 0xad, 0xbe, 0xef};

	LOG_HEXDUMP_INF(data, sizeof(data));
}
