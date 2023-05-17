#include "st_math.h"

long double st_asin(double x) {
  long double result = 0.0;
  if (x == 1 || x == -1) {
    result = (st_PI / 2) * x;
  } else if ((x > -1.0) && (x < 1.0)) {
    result = st_atan((x) / (st_sqrt((1 - x) * (1 + x))));
  } else {
    result = st_NAN;
  }
  return result;
}