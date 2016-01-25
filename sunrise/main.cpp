#include <stdio.h>
#include <time.h>
#include <math.h>

#include "colours.h"
#include "sunrise.h"

int main(int argc, char * argv[])
{
  Sunrise sr;
  Colours cls;

  sr.set_lat_long(51.275, -1.087);       // Canterbury
  // sr.set_lat_long(-33.865, -151.2094);   // Sydney
  // sr.set_lat_long(40.7127, 74.0059);     // New York
  printf("====== %0.5fN, %0.5fW ======\n", sr.getLatitude(), sr.getLongitude());


  time_t current_time = time(NULL);
  struct tm tm = *localtime(&current_time);
  time_t offset = ((tm.tm_year - 70) * 365 * 24 * 60 * 60) + ((tm.tm_yday + 1) * 24*60*60);


  printf("UTC Sunrise: "); sr.print_time(sr.get_sunrise()+offset);
  printf("UTC Sunset: "); sr.print_time(sr.get_sunset()+offset);
  printf("UTC current time: "); sr.print_time(time(NULL) % 24 * 60 * 60);

  printf("time_t sr  = %ld\n", (int)sr.get_sunrise());
  printf("time_t ss  = %ld\n", (int)sr.get_sunset());
  printf("time_t now = %d\n", (int)time(NULL) %  24 * 60 * 60);


  color_t sky_colour = cls.get_colour(time(NULL) % 24 * 60 * 60, sr.get_sunrise(), sr.get_sunset());

  printf("r: %d, g: %d, b: %d\n", sky_colour.r, sky_colour.g, sky_colour.b);

  return 0;
}
