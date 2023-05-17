#include "st_math.h"

long double st_sin(double x) {
  long double result = 0;
  if (x == x && x != st_INF && x != -st_INF) {
    while (x < -2 * st_PI || x > 2 * st_PI) {
      if (x > 2 * st_PI) {
        x -= 2 * st_PI;
      } else {
        x += 2 * st_PI;
      }
    }
    for (int i = 0; i < 500; i++) {
      result += st_pow(-1, i) * st_pow(x, 2 * i + 1) / st_factorial(2 * i + 1);
    }
  } else {
    result = st_NAN;
  }
  return result;
}