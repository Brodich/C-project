#include "st_math.h"

long double st_factorial(int x) {
  long double result = 1;
  if (x == 0) {
    result = 1;
  } else {
    for (; x >= 1; x--) {
      result *= x;
    }
  }
  return result;
}