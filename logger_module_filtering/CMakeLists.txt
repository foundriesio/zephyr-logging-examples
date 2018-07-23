# Set up our own Kconfig options with a custom KCONFIG_ROOT.
#
# IMPORTANT: this must come before including boilerplate.cmake.
set(KCONFIG_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Kconfig)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(NONE)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/module_main_file.c)
target_sources(app PRIVATE src/module_helper_file.c)
