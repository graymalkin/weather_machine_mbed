/**
 * MQTT Weather Machine
 * Copyright (C) 2015 Simon Cooksey, Jonathan Poole, and the University of Kent
 */

#include "neo.h"

#define PIN_MASK (1<<4)

void NeoPixel::init()
{
}

void NeoPixel::send_pixel(neo_colour_t colour) {
	// delay_ns(100);
	_neo_pin = 1;
	// delay_ns(100);
	// _neo_pin = 0;
}
