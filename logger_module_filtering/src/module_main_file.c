#include "module.h"

#define LOG_LEVEL CONFIG_FOUNDRIES_IO_MOD_LOG_LEVEL
#define LOG_MODULE_NAME foundries_io_mod
#include <logging/log.h>
LOG_MODULE_REGISTER();

void module_init(void)
{
	LOG_INF("initialized; getting help.");
	module_get_help();
}
