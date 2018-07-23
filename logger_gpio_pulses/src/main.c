/*
 * Copyright (c) 2018 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_LEVEL LOG_LEVEL_DBG
#define LOG_MODULE_NAME M
#include <logging/log.h>
LOG_MODULE_REGISTER();

#include <gpio.h>
#include <soc.h>

/*
 * These settings work for the nRF52840 DK. Your mileage may vary.
 */
#define DEV "GPIO_0"
#define PIN 5

__attribute__((noinline))
static void config_gpio(void)
{
	struct device *dev = device_get_binding(DEV);

	/* Bring the pin down. */
	gpio_pin_configure(dev, PIN, GPIO_DIR_OUT);
	gpio_pin_write(dev, PIN, 0);
}

__attribute__((noinline))
static void pulse(void)
{
	NRF_P0->OUTSET = 1U << PIN;
	__NOP();
	__NOP();
	__NOP();
	NRF_P0->OUTCLR = 1U << PIN;
}

__attribute__((noinline))
static void pulse_log(void)
{
	NRF_P0->OUTSET = 1U << PIN;
	LOG_DBG("");
	NRF_P0->OUTCLR = 1U << PIN;
}

void main(void)
{
	config_gpio();
	pulse();
	pulse_log();
	pulse_log();
}
