#include "st_math.h"

long double st_exp(double x) {
  long double result = 1;
  long double tmpExp = 1;
  long double i = 1;
  int flag = 0;
  if (x == -st_INF) {
    tmpExp = 0;
  } else if (x != x) {
    tmpExp = st_NAN;
  } else {
    if (x < 0) {
      x *= -1;
      flag = 1;
    }
    while (st_fabs(result) > st_EPS) {
      result *= x / i;
      i += 1;
      tmpExp += result;
      if (tmpExp > st_MAX_DOUBLE) {
        tmpExp = st_INF;
        break;
      }
    }
    if (flag == 1) {
      if (tmpExp > st_MAX_DOUBLE) {
        tmpExp = 0;
      } else {
        tmpExp = 1. / tmpExp;
      }
    }
    if (tmpExp > st_MAX_DOUBLE) {
      tmpExp = st_INF;
    }
  }
  return tmpExp;
}