#include "st_math.h"

long double st_sqrt(double x) {
  long double res = 0;

  if (is_negative(x)) {
    res = -st_NAN;
  }

  else if (is_inf(x)) {
    res = st_INF;
  }

  else if (is_nan(x)) {
    res = st_NAN;
  }

  else {
    long double res_new = x;
    for (int i = 0; i < 10000; ++i) {
      if (st_fabs(res - res_new) < st_EPS) {
        break;
      }
      res = res_new;
      res_new = 0.5 * (res + x / res);
    }
    res = res_new;
  }

  return res;
}
