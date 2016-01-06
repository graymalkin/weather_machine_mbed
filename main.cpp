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

// DigitalIn dummy(PTD2,PullDown);
// wsDrive ledDriver(PTD2,PTD3,PTD1);
DigitalOut neo_pin(PTD2);
NeoPixel neo(neo_pin);
pixelInfo pixelData[WS2812_LENGTH];
Sunrise sunrise;
Colours colours(sunrise);

DigitalOut neopin(D9);
DigitalOut green_led(LED_GREEN);

int main()
{
	memset(&pixelData, 0, sizeof(pixelData));

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
	neo_colour_t colour;
	neo.send_pixel(colour);
	while(1)
		m_client.yield(1000);


}
