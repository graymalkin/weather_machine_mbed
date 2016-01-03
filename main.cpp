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

#include "mqtt_client.h"


int main()
{
    // Mostly pinched from the HelloMQTT demo here
    // https://developer.mbed.org/teams/mqtt/code/HelloMQTT
    MQTTEthernet ipstack;
    MQTT::Client<MQTTEthernet, Countdown> m_client(ipstack);
    if(mqtt_connect(ipstack, m_client) != MQTT::SUCCESS) {
        mqtt_error();
    }
    mqtt_subscriptions(m_client);

}
