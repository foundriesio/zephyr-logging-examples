/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_LEVEL LOG_LEVEL_DBG
#define LOG_MODULE_NAME foundries_io_mod_runtime
#include <logging/log.h>
#include <logging/log_ctrl.h>
LOG_MODULE_REGISTER();

#include <zephyr.h>

static void set_my_log_level(u32_t level);
static void wait_for_log_processing(void);

void func()
{
	/* Log a couple of messages. */
	LOG_INF("for your information");
	LOG_DBG("no bugs here!");

	/* Wait for them to get processed. */
	wait_for_log_processing();
}

void main(void)
{
	printk("All logs disabled:\n");
	set_my_log_level(LOG_LEVEL_NONE);
	func();

	printk("INF and up enabled:\n");
	set_my_log_level(LOG_LEVEL_INF);
	func();

	printk("All logs enabled:\n");
	set_my_log_level(LOG_LEVEL_DBG);
	func();
}

/*
 * Helper routine for updating this module's log level which hides
 * away some obscure Logger details.
 */
static void set_my_log_level(u32_t level)
{
	/*
	 * "Domains" don't mean anything right now, but Logger was
	 * designed to require them to allow for future expansion into
	 * multiprocessor systems.
	 */
	u32_t my_domain_id = CONFIG_LOG_DOMAIN_ID;
	/*
	 * Passing NULL as log_filter_set()'s first argument means it
	 * applies to all "backends". Right now, there's only one
	 * backend, which prints to the console UART, so that's fine.
	 */
	struct log_backend *all_backends = NULL;
	/*
	 * We need to convert our log module name to a "source ID".
	 */
	int my_source_id = -1;
	int i;

	for (i = 0; i < log_src_cnt_get(my_domain_id); i++) {
		if (!strcmp(log_source_name_get(my_domain_id, i),
			    STRINGIFY(LOG_MODULE_NAME))) {
			my_source_id = i;
			break;
		}
	}

	if (my_source_id == -1) {
		printk("this module has no source ID; halting.\n");
		while (true)
			;
	}

	log_filter_set(all_backends, my_domain_id, my_source_id, level);
}

/*
 * Gotcha! We need to wait until all messages are flushed at
 * the current filtering setting.
 *
 * Otherwise, we'll race with the processing thread.
 */
static void wait_for_log_processing(void)
{
	while (log_buffered_cnt() > 0) {
		k_sleep(K_SECONDS(1));
	}
}
