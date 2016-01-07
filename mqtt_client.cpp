/*
 * (C) The University of Kent and Simon Cooksey 2015.
 */

#include "mbed.h"

#include "C12832.h"
#include "mqtt_client.h"
#include "mqtt_event_handlers.h"

extern Serial host;

int mqtt_connect(MQTTEthernet& ipstack, MQTT::Client<MQTTEthernet, Countdown>& m_client)
{
    char hostname[] = MQTT_HOST;
    int port = MQTT_PORT;

    int result = ipstack.connect(hostname, port);

    return m_client.connect();
}

int mqtt_subscriptions(MQTT::Client<MQTTEthernet, Countdown>& m_client)
{
	int rc = 0;

    if((rc = m_client.subscribe("weather_sim/location", MQTT::QOS1, set_location)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/location'\r\n", rc);

	if((rc = m_client.subscribe("weather_sim/set_time", MQTT::QOS1, set_time)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/set_time'\r\n", rc);

    if((rc = m_client.subscribe("weather_sim/longitude", MQTT::QOS1, set_longitude)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/longitude'\r\n", rc);

    if((rc = m_client.subscribe("weather_sim/latitude", MQTT::QOS1, set_latitude)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/latitude'\r\n", rc);

    if((rc = m_client.subscribe("weather_sim/rain", MQTT::QOS1, set_rain)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/rain'\r\n", rc);
    if((rc = m_client.subscribe("weather_sim/mist", MQTT::QOS1, set_mist)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/mist'\r\n", rc);
    if((rc = m_client.subscribe("weather_sim/light", MQTT::QOS1, set_light)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/light'\r\n", rc);

    if((rc = m_client.subscribe("weather_sim/lightning_strike", MQTT::QOS1, do_lightning_strike)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/lightning_strike'\r\n", rc);

    if((rc = m_client.subscribe("weather_sim/test", MQTT::QOS1, do_test)) != 0)
		host.printf("MQTT Error: (%d)\r\n  Failed to subscribe to `weather_sim/test'\r\n", rc);

    return 0;
}

void mqtt_error()
{
    wait_ms(5000);
    // If something goes wrong, just reboot. Nasty nasty hack.
    NVIC_SystemReset();
}
