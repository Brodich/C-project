#ifndef _st_MATH_H
#define _st_MATH_H

#define st_PI 3.14159265358979324
#define st_EPS 1e-17
#define st_MAX_DOUBLE 1.7976931348623158e308
#define st_INF (__builtin_inff())
#define st_NAN (__builtin_nanf(""))
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define is_negative(x) __builtin_signbit(x)

#define st_EXP 2.71828182845904523536028747135266249775724709369995

#include <stdio.h>
#include <stdlib.h>

int st_abs(int x);
long double st_acos(double x);
long double st_asin(double x);
long double st_atan(double x);
long double st_ceil(double x);
long double st_cos(double x);
long double st_exp(double x);
long double st_fabs(double x);
long double st_floor(double x);
long double st_fmod(double x, double y);
long double st_log(double x);
long double st_pow(double base, double exp);
long double st_sin(double x);
long double st_sqrt(double x);
long double st_tan(double x);
long double st_factorial(int x);

#endif
