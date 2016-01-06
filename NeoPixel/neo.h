/**
 * MQTT Weather Machine
 * Copyright (C) 2015 Simon Cooksey, Jonathan Poole, and the University of Kent
 */

#include "mbed.h"
#include <inttypes.h>

#ifndef __neo_h_
#define __neo_h_

typedef union neo_colour_t {
	uint32_t grba;
	struct {
		uint8_t g;
		uint8_t r;
		uint8_t b;
		uint8_t a;
	} channels;
} neo_colour_t;


extern "C" void delay_ns(int ns);
class NeoPixel {
public:
	NeoPixel(DigitalOut pin) : _neo_pin(pin) {
		init();
	}

	void send_pixel(neo_colour_t colour);
	void init();

private:
	DigitalOut _neo_pin;
};

#endif // __neo_h_
