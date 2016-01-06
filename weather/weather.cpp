#include "mbed.h"
#include "weather.h"

DigitalOut rain_on(PTC11);
DigitalOut rain_off(PTC10);

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
    // Set the mister
}
