#include "st_math.h"

long double st_log(double x) {
  long double count_pow = 0;
  long double result = 0;
  double compare = 0;
  int flag = 0;

  if (x == st_INF && flag == 0) {
    result = st_INF;
    flag = 1;
  }
  if (x < 0 && flag == 0) {
    result = st_NAN;
    flag = 1;
  }
  if (x == 0 && flag == 0) {
    result = -st_INF;
    flag = 1;
  }
  if (x == 1 && flag == 0) {
    result = 0;
    flag = 1;
  }
  for (; x >= st_EXP && flag == 0; x /= st_EXP, count_pow++) {
    continue;
  }
  for (int i = 0; i < 100 && flag == 0; i++) {
    compare = result;
    double a = x - st_exp(compare);
    double b = x + st_exp(compare);
    result = compare + 2 * (a) / (b);
  }
  return (result + count_pow);
}
