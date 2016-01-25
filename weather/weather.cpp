#include "mbed.h"
#include "weather.h"

DigitalOut rain_on(PTC11);
DigitalOut rain_off(PTC10);
DigitalOut mist(PTC3);

void set_rain(actuator_state_t state)
{
	switch(state)
	{
		case ON:
			rain_on = 0;
			rain_off = 1;
			break;
		default:
			rain_on = 1;
			rain_off = 0;
			break;
	}
	wait_ms(250);
	rain_off = 0;
	rain_on = 0;
}

void set_mist(actuator_state_t state)
{
	switch(state)
	{
		case ON:
			mist = 1;
			break;
		default:
			mist = 0;
			break;
	}
}

void set_light(int light_level)
{
	// Set the light level
}
