#include "st_math.h"

long double st_ceil(double x) {
  long double ceil_x = (long long int)x;
  if (x != x) {
    ceil_x = st_NAN;
  } else if (x == st_INF || x == -st_INF) {
    ceil_x = st_INF;
  } else {
    if (st_fabs(x) > 0. && x != ceil_x) {
      if (x > 0.) {
        ceil_x += 1;
      }
    }
  }
  return ceil_x;
}