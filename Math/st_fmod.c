#include "st_math.h"

long double st_fmod(double x, double y) {
  long double res = 0;

  if (x == 0. && (y != 0. && y == y)) {
    res = 0;
  } else if ((x == st_INF || x == -st_INF) && y != y) {
    res = st_NAN;
  } else if (y == 0. && x != st_NAN) {
    res = st_NAN;
  } else if ((y == st_INF || y == -st_INF) && x == x) {
    res = x;
  } else if (x != x || y != y) {
    res = st_NAN;
  } else {
    long long int mod = x / y;
    res = (long double)x - mod * (long double)y;
  }

  return res;
}
