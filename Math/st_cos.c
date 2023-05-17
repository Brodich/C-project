#include "st_math.h"

long double st_cos(double x) {
  long double result = 0.0;
  if (x == 0) {
    result = 1;
  } else {
    if (x == x && x != st_INF && x != -st_INF) {
      while (x < -2 * st_PI || x > 2 * st_PI) {
        if (x > 2 * st_PI) {
          x -= 2 * st_PI;
        } else {
          x += 2 * st_PI;
        }
      }
      for (int i = 0; i <= 20; i++) {
        result =
            result + (st_pow(-1, i) * st_pow(x, 2 * i)) / st_factorial(2 * i);
      }
    } else {
      result = st_NAN;
    }
  }
  return result;
}