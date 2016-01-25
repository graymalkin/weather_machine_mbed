#include "stdlib.h"
#include "string.h"
#include "mbed.h"

#include "mqtt_event_handlers.h"
#include "sunrise.h"
#include "weather.h"

extern Serial host;
extern Sunrise sunrise;

time_t sunrise_utc = 0;
time_t sunset_utc = 0;

#define MAX_BUFFER_LEN 20
#define LOCATION_BUFFER_LEN 50

void mqtt_set_location(MQTT::MessageData& m_data)
{
	char buffer[LOCATION_BUFFER_LEN];
	int length = m_data.message.payloadlen < LOCATION_BUFFER_LEN ? m_data.message.payloadlen : LOCATION_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	host.printf("MQTT:\r\n  mqtt_set_location: %s\r\n", buffer);
}

void mqtt_set_time(MQTT::MessageData& m_data)
{
	char buffer[MAX_BUFFER_LEN];
	int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	time_t new_time = atoi(buffer);
	struct tm tm = *localtime(&new_time);

	host.printf("MQTT:\r\n  mqtt_set_time: %02d/%02d/%02d %02d:%02d:%02d\r\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+MAX_BUFFER_LEN - 100, tm.tm_hour, tm.tm_min, tm.tm_sec);

	set_time(new_time);
}

void mqtt_set_longitude(MQTT::MessageData& m_data)
{
	char buffer[MAX_BUFFER_LEN];
	int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	host.printf("MQTT:\r\n  mqtt_set_longitude: %s\r\n", buffer);

	sunrise.set_longitude(atof(buffer));
}

void mqtt_set_latitude(MQTT::MessageData& m_data)
{
	char buffer[MAX_BUFFER_LEN];
	int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	host.printf("MQTT:\r\n  mqtt_set_latitude: %s\r\n", buffer);

	sunrise.set_latitude(atof(buffer));
}

void mqtt_set_rain(MQTT::MessageData& m_data)
{
	char buffer[MAX_BUFFER_LEN];
	int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	host.printf("MQTT:\r\n  set_rain: %s\r\n", buffer[0] == '1' ? "ON" : "OFF");

	set_rain(buffer[0] == '1' ? ON : OFF);
}

void mqtt_set_mist(MQTT::MessageData& m_data)
{
	char buffer[MAX_BUFFER_LEN];
	int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	host.printf("MQTT:\r\n  set_mist: %s\r\n", buffer[0] == '1' ? "ON" : "OFF");

	set_mist(buffer[0] == '1' ? ON : OFF);
}

void mqtt_set_light(MQTT::MessageData& m_data)
{
	char buffer[MAX_BUFFER_LEN];
	int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

	memcpy(buffer, m_data.message.payload, length);
	buffer[length] = '\0';

	host.printf("MQTT:\r\n  set_light: %s\r\n", buffer);

	set_light(atoi(buffer));
}

void mqtt_set_sunrise_utc(MQTT::MessageData& m_data)
{
    char buffer[MAX_BUFFER_LEN];
    int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

    memcpy(buffer, m_data.message.payload, length);
    buffer[length] = '\0';

    host.printf("MQTT:\r\n  set_sunrise: %s\r\n", buffer);

    sunrise_utc = atol(buffer);
}

void mqtt_set_sunset_utc(MQTT::MessageData& m_data)
{
    char buffer[MAX_BUFFER_LEN];
    int length = m_data.message.payloadlen < MAX_BUFFER_LEN ? m_data.message.payloadlen : MAX_BUFFER_LEN - 1;

    memcpy(buffer, m_data.message.payload, length);
    buffer[length] = '\0';

    host.printf("MQTT:\r\n  set_sunset: %s\r\n", buffer);

    sunset_utc = atol(buffer);
}

void mqtt_do_test(MQTT::MessageData& m_data)
{

}

void mqtt_do_lightning_strike(MQTT::MessageData& m_data)
{

}
