#include "st_math.h"

long double st_atan(double x) {
  long double result = 0.0;
  if (x == st_INF) {
    result = st_PI / 2;
  } else if (x == -st_INF) {
    result = -st_PI / 2;
  } else if (x != x) {
    result = st_NAN;
  } else {
    double tmp;
    if (-1. < x && x < 1.)
      for (int i = 0; i < 10000; i++) {
        tmp = (((st_pow(-1, i)) * (st_pow(x, 1 + (2 * i)))) / (1 + 2 * i));
        if (st_fabs(tmp) < st_EPS) {
          break;
        }
        result += tmp;
      }
    else {
      for (int i = 0; i < 10000; i++) {
        tmp = st_pow(-1, i) * st_pow(x, -1 - (2 * i)) / (1 + (2 * i));
        if (st_fabs(tmp) < st_EPS) {
          break;
        }
        result += tmp;
      }
      result = st_PI * st_sqrt(x * x) / (2 * x) - result;
    }
  }
  return result;
}