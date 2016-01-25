#ifndef __weather_h_
#define __weather_h_

typedef enum actuators_t {
    RAIN,
    MIST,
    LIGHTNING
} actuators_t;

typedef enum actuator_state_t {
    ON,
    OFF
} actuator_state_t;

void set_rain(actuator_state_t state);
void set_mist(actuator_state_t state);
void set_light(int light_level);
void set_lightning(int distance);
void lightning_strike();

#endif // __weather_h_
