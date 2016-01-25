#ifndef __mqtt_event_handlers_h_
#define __mqtt_event_handlers_h_

#include "MQTTClient.h"

void mqtt_set_location(MQTT::MessageData& m_data);
void mqtt_set_time(MQTT::MessageData& m_data);
void mqtt_set_longitude(MQTT::MessageData& m_data);
void mqtt_set_latitude(MQTT::MessageData& m_data);
void mqtt_set_rain(MQTT::MessageData& m_data);
void mqtt_set_mist(MQTT::MessageData& m_data);
void mqtt_set_light(MQTT::MessageData& m_data);
void mqtt_do_lightning_strike(MQTT::MessageData& m_data);
void mqtt_do_test(MQTT::MessageData& m_data);
void mqtt_set_sunrise_utc(MQTT::MessageData& m_data);
void mqtt_set_sunset_utc(MQTT::MessageData& m_data);

#endif // __mqtt_event_handlers_h_
