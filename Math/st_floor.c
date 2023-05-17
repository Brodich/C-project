#include "st_math.h"

long double st_floor(double x) {
  long double floor_x = (long long int)x;
  if (x == st_INF || x == -st_INF) {
    floor_x = st_INF;
  } else if (x != x) {
    floor_x = st_NAN;
  } else {
    if (st_fabs(x - floor_x) > 0. && st_fabs(x) > 0.) {
      if (x < 0.) {
        floor_x -= 1;
      }
    }
  }
  return floor_x;
}