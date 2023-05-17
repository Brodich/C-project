#include "st_math.h"

long double st_acos(double x) {
  long double result = 0.0;
  if (x == 0) {
    result = st_PI / 2;
  } else if (x == -1) {
    result = st_PI;
  } else if (x > -1 && x <= 1) {
    result = st_atan((st_sqrt(1.0 - (st_pow(x, 2.0)))) / x);
  } else {
    result = st_NAN;
  }
  return result;
}