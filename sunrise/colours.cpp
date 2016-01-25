#define INTERP_POINT_COUNT 5

#define COLOR_BLACK {0, 0, 0}
#define COLOR_ORANGE {254, 91, 53}
#define COLOR_BLUE {59, 185, 255}

#include <Math.h>
#include <time.h>
#include "colours.h"

color_t colors[INTERP_POINT_COUNT] = {COLOR_BLACK, COLOR_ORANGE, COLOR_BLUE, COLOR_ORANGE, COLOR_BLACK};
double times[INTERP_POINT_COUNT] = {0, 0.1, 0.5, 0.9, 1}; 

int Colours::interpolate_int(int first_int, int second_int, double interpolation_fraction){
    double range = second_int - first_int;
    return first_int + (int)round(range*interpolation_fraction);
}

color_t Colours::interpolate_color(color_t first_color, color_t second_color, double interpolation_fraction){
    int r, g, b;

    r = interpolate_int(first_color.r, second_color.r, interpolation_fraction);
    g = interpolate_int(first_color.g, second_color.g, interpolation_fraction);
    b = interpolate_int(first_color.b, second_color.b, interpolation_fraction);

    return (color_t) {r, g, b};
}

color_t Colours::getColorForNormalisedTime(double normalised_time){
    for(int i = 0; i < INTERP_POINT_COUNT-1; i++){
        if (normalised_time >= times[i] && normalised_time <= times[i+1]){
            double range = times[i+1] - times[i];
            double value = normalised_time - times[i];
            double interpolation_fraction = value/range;

            return interpolate_color(colors[i], colors[i+1], interpolation_fraction);
        }
    }

    return (color_t) COLOR_BLACK;
}

double Colours::normalise_time(time_t current_time, time_t sunrise, time_t sunset){
    double range = (sunset - sunrise);
    double value = current_time - sunrise;

    return value/range;
}

color_t Colours::get_colour(time_t current_time, time_t sunrise, time_t sunset){
    double normalised_time = normalise_time(current_time, sunrise, sunset);
    return getColorForNormalisedTime(normalised_time);
}
