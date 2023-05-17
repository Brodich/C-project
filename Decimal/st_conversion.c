#include "st_decimal.h"

int st_from_int_to_decimal(int src, st_decimal *dst) {
  *dst = init_dec();
  int sign = src >> 31;

  if (src < 0) src *= -1;

  dst->bits[0] = src;
  if (sign != 0) {
    ft_setbit_one_dec(dst, 127);
  }
  return (0);
}

int st_from_decimal_to_int(st_decimal src, int *dst) {
  bcd_t bcd = {0};
  st_decimal true_src = {0};
  int sign = 0;
  int result = 0;
  ft_from_dec_to_bcd(src, &bcd);
  // Скейл должен быть равен 0 - отбросить дробную часть
  while (bcd.scale > 0) {
    ft_shift_bit_right_bcd(&bcd, 8);
    bcd.scale--;
  }
  if (bcd.sign == 1) {
    sign = 1;
    bcd.sign--;
  }
  ft_from_bcd_to_dec(&bcd, &true_src);

  st_decimal maxint = {0};
  maxint.bits[0] = 0xffffffff;
  // сравнение с максимальным интом
  if (st_is_greater(true_src, maxint)) {
    result = 1;
  } else {
    *dst = true_src.bits[0];
    if (sign == 1) {
      *dst = ~(*dst) + 1;
    }
  }
  return (result);
}

/*
Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение, равное 0
Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335) или
равны бесконечности, вернуть ошибку При обработке числа с типом float
преобразовывать все содержащиеся в нём значимые десятичные цифры. Если таких
цифр больше 7, то значение числа округляется к ближайшему, у которого не больше
7 значимых цифр.
*/
// ??
int st_from_float_to_decimal(float src, st_decimal *dst) {
  *dst = init_dec();
  bcd_t bcd = {0};
  int result = 0;
  char farr[30] = {0};
  float norm = src;
  int flag = 1;
  if (isnan(norm) == 1 || norm == INFINITY || norm == -INFINITY ||
      fabs(norm) > 79228162514264337593543950335.0 ||
      ((fabs(norm) < 1E-28) && (fabs(norm) > 0))) {
    result = 1;
  } else {
    if (norm < 0) {
      norm *= -1;
      flag = -1;
    }

    sprintf(farr, "%.6e", norm);

    bcd.digit[6] = farr[0] - '0';
    int i = 5;
    int j = 2;
    while (i >= 0) {
      bcd.digit[i] = farr[j] - '0';
      i--;
      j++;
    }
    bcd.scale = (farr[10] - '0');
    if (farr[11] >= '0' && farr[11] <= '9') {
      bcd.scale += farr[11] - '0' + 10 * bcd.scale - bcd.scale;
    }
    if (farr[9] == '-') {
      bcd.scale *= -1;
    }
    bcd.scale -= 6;
    while (bcd.scale < -28) {
      ft_shift_bit_right_bcd(&bcd, 8);
      bcd.scale++;
    }
    while (bcd.scale > 0) {
      ft_shift_bit_left_bcd(&bcd, 8);
      bcd.scale--;
    }

    if (bcd.scale < 0) {
      bcd.scale *= -1;
    }

    ft_from_bcd_to_dec(&bcd, dst);
    if (flag == -1) {
      ft_setbit_one_dec(dst, 127);
    }
  }
  return (result);
}

int st_from_decimal_to_float(st_decimal src, float *dst) {
  double fl = 0;
  bcd_t bcd1 = {0};
  // int ten_scale = 1;        - не уверен почему так, но на моем маке с ними не
  // запускается (Ваня)
  ft_from_dec_to_bcd(src, &bcd1);
  int count_digit = senoir_number_bcd(bcd1);

  while (count_digit >= 0) {
    fl = fl + bcd1.digit[count_digit] * pow(10, count_digit);
    // ten_scale++; не уверен почему так, но на моем маке с ними не запускается
    // (Ваня)
    count_digit--;
  }

  while (bcd1.scale > 0) {
    fl /= 10;
    bcd1.scale--;
  }
  if (bcd1.sign == 1) {
    fl *= -1;
  }
  *dst = fl;
  return (0);
}
