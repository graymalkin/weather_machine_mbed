#include "stdlib.h"
#include "mbed.h"
#include "mqtt_event_handlers.h"
#include "weather.h"

extern Serial host;

void set_location(MQTT::MessageData& m_data)
{

}

void set_time(MQTT::MessageData& m_data)
{

}

void set_longitude(MQTT::MessageData& m_data)
{

}

void set_latitude(MQTT::MessageData& m_data)
{

}

void set_condition(MQTT::MessageData& m_data)
{
	char buffer[20];

	memcpy(buffer, m_data.message.payload, m_data.message.payloadlen);
	buffer[m_data.message.payloadlen] = '\0';

	host.printf("MQTT:\r\n  set_condition: %s\r\n", buffer);
	int condition = atoi((char*)m_data.message.payload);

	set_rain((condition & 0x80) ? ON : OFF);
}

void do_test(MQTT::MessageData& m_data)
{

}


void enable_actuator(MQTT::MessageData& m_data)
{

}

void disable_actuator(MQTT::MessageData& m_data)
{

}


void do_lightning_strike(MQTT::MessageData& m_data)
{

}
