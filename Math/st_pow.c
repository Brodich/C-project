#include "st_math.h"

long double st_pow(double base, double exp) {
  long double result;
  long double copy = base;
  int flag = 0;

  if (base == -1 && (exp == st_INF || exp == -st_INF) && flag == 0) {
    result = 1;
    flag = 1;
  }
  if (base == 1 && flag == 0) {
    result = 1;
    flag = 1;
  }
  if (exp == 0 && flag == 0) {
    result = 1;
    flag = 1;
  }
  if ((base < 0 && base != -st_INF) &&
      (exp != st_INF && exp != -st_INF && (exp - (long)exp) != 0) &&
      flag == 0) {
    result = st_NAN;
    flag = 1;
  }
  if (st_fabs(base) < 1 && exp == -st_INF && flag == 0) {
    result = st_INF;
    flag = 1;
  }
  if (st_fabs(base) > 1 && exp == -st_INF && flag == 0) {
    result = 0;
    flag = 1;
  }
  if (st_fabs(base) < 1 && exp == st_INF && flag == 0) {
    result = 0;
    flag = 1;
  }
  if (st_fabs(base) > 1 && exp == st_INF && flag == 0) {
    result = st_INF;
    flag = 1;
  }
  if ((base) == -st_INF &&
      (exp > 0 && (((exp - (long)exp) != 0) || ((long)exp % 2) == 0)) &&
      flag == 0) {
    result = st_INF;
    flag = 1;
  }

  if (flag == 0) {
    if (copy < 0) {
      copy = -copy;
      result = st_exp(exp * st_log(copy));
      if (st_fmod(exp, 2) != 0) {
        result = -result;
      }
    } else {
      result = st_exp(exp * st_log(base));
    }
  }

  return result;
}
