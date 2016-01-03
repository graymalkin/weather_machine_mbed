/*
 * (C) The University of Kent and Simon Cooksey 2015.
 */

#include "C12832.h"
#include "mqtt_client.h"
#include "mqtt_event_handlers.h"

int mqtt_connect(MQTTEthernet& ipstack, MQTT::Client<MQTTEthernet, Countdown>& m_client)
{
    char hostname[] = MQTT_HOST;
    int port = MQTT_PORT;

    int result = ipstack.connect(hostname, port);

    return m_client.connect();
}

int mqtt_subscriptions(MQTT::Client<MQTTEthernet, Countdown>& m_client)
{
    m_client.subscribe("weather_sim/location", MQTT::QOS1, set_location);
    m_client.subscribe("weather_sim/set_time", MQTT::QOS1, set_time);
    m_client.subscribe("weather_sim/longitude", MQTT::QOS1, set_longitude);
    m_client.subscribe("weather_sim/latitude", MQTT::QOS1, set_latitude);
    m_client.subscribe("weather_sim/condition", MQTT::QOS1, set_condition);

    m_client.subscribe("weather_sim/disable", MQTT::QOS1, disable_actuator);
    m_client.subscribe("weather_sim/enable", MQTT::QOS1, enable_actuator);

    m_client.subscribe("weather_sim/lightning_strike", MQTT::QOS1, do_lightning_strike);

    m_client.subscribe("weather_sim/test", MQTT::QOS1, do_test);

    return 0;
}

void mqtt_error()
{
    wait_ms(5000);
    // If something goes wrong, just reboot. Nasty nasty hack.
    NVIC_SystemReset();
}
