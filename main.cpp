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



int main()
{
    MQTTEthernet ipstack = MQTTEthernet();
    float version = 0.5;
    char* topic = (char*)"mbed-sample";
    int arrivedcount = 0;

    printf("HelloMQTT: version is %f\n", version);

    MQTT::Client<MQTTEthernet, Countdown> client = MQTT::Client<MQTTEthernet, Countdown>(ipstack);

    char* hostname = (char*)"m2m.eclipse.org";
    int port = 1883;
    printf("Connecting to %s:%d\n", hostname, port);
    int rc = ipstack.connect(hostname, port);
    if (rc != 0)
        printf("rc from TCP connect is %d\n", rc);

    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.MQTTVersion = 3;
    data.clientID.cstring = (char*)"mbed-sample";
    data.username.cstring = (char*)"testuser";
    data.password.cstring = (char*)"testpassword";
    if ((rc = client.connect(data)) != 0)
        printf("rc from MQTT connect is %d\n", rc);

        MQTT::Message message;

    // QoS 0
    char buf[100];
    sprintf(buf, "Hello World!  QoS 0 message from app version %f\n", version);
    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;
    message.payload = (void*)buf;
    message.payloadlen = strlen(buf)+1;
    rc = client.publish(topic, message);
    while (arrivedcount < 1)
        client.yield(100);
}
