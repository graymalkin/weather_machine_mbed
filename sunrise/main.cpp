#include <stdio.h>
#include <time.h>
#include <math.h>

#include "colours.h"
#include "sunrise.h"

int main(int argc, char * argv[])
{
  Sunrise sr;
  Colours cls(sr);

  // sr.set_lat_long(51.275, -1.087);       // Canterbury
  // sr.set_lat_long(-33.865, -151.2094);   // Sydney
  sr.set_lat_long(40.7127, 74.0059);     // New York
  printf("====== %0.5fN, %0.5fW ======\n", sr.getLatitude(), sr.getLongitude());

  printf("UTC Sunrise: "); sr.print_time(sr.get_sunrise());
  printf("UTC Sunset: "); sr.print_time(sr.get_sunset());

  return 0;
}
