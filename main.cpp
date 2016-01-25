/**
 * MQTT Weather Machine
 * Copyright (C) 2015 Simon Cooksey, Jonathan Poole, and the University of Kent
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */


#define MQTTCLIENT_QOS2 1
#include "mbed.h"
#include "math.h"
#include "MQTTEthernet.h"
#include "MQTTClient.h"

#include "colours.h"
#include "mqtt_client.h"
#include "neo.h"
#include "sunrise.h"
#include "weather.h"
#include "wsDrive.h"

#define WS2812_LENGTH 30

Serial host(USBTX, USBRX);
Serial arduino(D1, D0);

// DigitalIn dummy(PTD2,PullDown);
// wsDrive ledDriver(PTD2,PTD3,PTD1);
DigitalOut neo_pin(PTD2);
NeoPixel neo(neo_pin);
pixelInfo pixelData[WS2812_LENGTH];

extern time_t sunrise_utc;
extern time_t sunset_utc;
Sunrise sunrise;
Colours cls;

DigitalOut neopin(D9);
DigitalOut green_led(LED_GREEN);

int main()
{
	memset(&pixelData, 0, sizeof(pixelData));
	set_rain(ON);
	wait_ms(1000);
	set_rain(OFF);
	wait_ms(1000);

	set_mist(ON);
	wait_ms(1000);
	set_mist(OFF);
	wait_ms(1000);

    // Mostly pinched from the HelloMQTT demo here
    // https://developer.mbed.org/teams/mqtt/code/HelloMQTT
    MQTTEthernet ipstack;
    MQTT::Client<MQTTEthernet, Countdown> m_client(ipstack);
    if(mqtt_connect(ipstack, m_client) != MQTT::SUCCESS) {
		host.printf("MQTT: Error.\r\n  Failed to connect.\r\n");
        mqtt_error();
    }
	host.printf("MQTT: Information.\r\n  Connected.\r\n");

    mqtt_subscriptions(m_client);
	green_led = 1;

	colour_t colour;
	while(1){
		m_client.yield(2000);
        time_t current_time = time(NULL);

        color_t colour = cls.get_colour(current_time, sunrise_utc, sunset_utc);
		arduino.printf("C%c%c%c", colour.r,  colour.g, colour.b);
	}
}
