/**
 * Sunrise
 * Copyright (C) 2015 Simon Cooksey, Jonathan Poole, and the University of Kent
 */

#ifndef __colours_h_
#define __colours_h_

typedef struct{
    int r, g, b;
} color_t;

class Colours {
public:
    /**
     * Convert the current time into an RGB colour to display.
     */
    color_t get_colour(time_t current_time, time_t sunrise, time_t sunset);
private:
	int interpolate_int(int first_int, int second_int, double interpolation_fraction);

	color_t interpolate_color(color_t first_color, color_t second_color, double interpolation_fraction);

	color_t getColorForNormalisedTime(double normalised_time);

	double normalise_time(time_t current_time, time_t sunrise, time_t sunset);

};

#endif // __colours_h_
