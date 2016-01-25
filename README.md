# weather_machine_mbed
The mbed code for Jonathan Poole and my CO657 weather simulator project


## Actuators

|     Name     |                     Effects on simulation                     |
|:------------:|:--------------------------------------------------------------|
| LCD Display  | Show the current location                                     |
| Pump         | Rain                                                          |
| WS2812 LEDs  | Sunrise, Sunset, lightning, possibly for overcast conditions  |
| Mister       | Fog, low cloud, etc.                                          |
| Fan          | We could have vortices of mist in cyclonic weather            |


## MQTT

Topics to subscribe to, and their purpose

|              Name              |             Effects on simulation             |          Data Format          |
|:------------------------------:|:----------------------------------------------|:------------------------------|
| `weather_sim/location`         | The name of the currently selected condition  | String (max len: 255 bytes)   |
| `weather_sim/set_time`         | Set the local time for the location under sim | Long Int (unix time)          |
| `weather_sim/longitude`        | Set the longitude of the current location     | Long Int                      |
| `weather_sim/latitude`         | Set the latitude of the current location      | Long Int                      |
| `weather_sim/rain`             | Set rain state                                | ('0' or '1')                  |
| `weather_sim/mist`             | Set mist state                                | ('0' or '1')                  |
| `weather_sim/light_level`      | Set mist state                                | Set some light level (0..100) |
| `weather_sim/lightning_strike` | Perform a lightning strike                    | No data required              |
| `weather_sim/test`             | Run through a test cycle                      | No data required              |
| `weather_sim/set_sunrise`      | Changes the time of sunrise                   | UNIX time of sunrise          |
| `weather_sim/set_sunset`       | Changes the time of sunset                    | UNIX time of sunset           |