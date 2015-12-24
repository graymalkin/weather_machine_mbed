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
| `weather_sim/condition`        | The current condition (enum)                  | Unsigned Char Value (0..255)  |
| `weather_sim/test`             | Run through a test cycle                      | No data required              |
| `weather_sim/disable`          | Disable actuators                             | Unsigned Char Value (0..255)  |
| `weather_sim/enable`           | Enable actuators                              | Unsigned Char Value (0..255)  |
| `weather_sim/lightning_strike` | Perform a lightning strike                    | No data required              |

## Conditions supported

We can represent the "current condition" as a bit field.

|   **Bit**   |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
|:------------|-------|-------|-------|-------|-------|-------|-------|-------|
|    Use      | Rain  | Mist  | Light | Light | Light | `XXX` | `XXX` | Fan   |

Making stormy weather something like `0b11011001` (Rain, Cloud, Dim light,
Windy).

Moon phase and sunrise/sunset will be calculated from the latitude of the
currently set location.
