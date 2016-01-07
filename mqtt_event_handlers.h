#ifndef __mqtt_event_handlers_h_
#define __mqtt_event_handlers_h_

#include "MQTTClient.h"

void set_location(MQTT::MessageData& m_data);
void set_time(MQTT::MessageData& m_data);
void set_longitude(MQTT::MessageData& m_data);
void set_latitude(MQTT::MessageData& m_data);
void set_rain(MQTT::MessageData& m_data);
void set_mist(MQTT::MessageData& m_data);
void set_light(MQTT::MessageData& m_data);
void do_lightning_strike(MQTT::MessageData& m_data);
void do_test(MQTT::MessageData& m_data);

#endif // __mqtt_event_handlers_h_
