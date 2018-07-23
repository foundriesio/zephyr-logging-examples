#define LOG_LEVEL CONFIG_FOUNDRIES_IO_MOD_LOG_LEVEL
#define LOG_MODULE_NAME foundries_io_mod
#include <logging/log.h>

/*
 * Note LOG_MODULE_DECLARE() is used instead of LOG_MODULE_REGISTER().
 * Exactly one file registers the module. The other files in the
 * module still need to declare module-specific state before using
 * logger APIs.
 */
LOG_MODULE_DECLARE();

void module_get_help()
{
	LOG_DBG("i'm trying to help!");
}
