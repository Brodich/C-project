#include "st_math.h"

long double st_fabs(double x) {
  long double result = 0;
  if (x == st_INF) {
    result = st_INF;
  } else if (x != x) {
    result = st_NAN;
  } else {
    result = x < 0 ? -x : x;
  }
  return result;
}
