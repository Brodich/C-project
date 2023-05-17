#include "st_decimal.h"

int compare_without_sign_bcd(bcd_t x, bcd_t y) {
  int result = 0;
  int i = 59;
  while (i >= 0) {
    if (x.digit[i] != y.digit[i]) {
      break;
    }
    i -= 1;
  }
  if (i >= 0) {  // check
    if (x.digit[i] > y.digit[i]) {
      result = 1;
    } else if (x.digit[i] == y.digit[i]) {
      result = 2;
    }
  }
  return result;
}

void ft_adding_bcd(bcd_t bcd1, bcd_t bcd2, bcd_t* bcd_result) {
  ft_normalization_equal_scale(&bcd1, &bcd2);
  bcd_result->scale = bcd1.scale;
  if (bcd1.sign == bcd2.sign) {
    for (int i = 0; i < 59; i++) {
      bcd_result->digit[i] += bcd1.digit[i] + bcd2.digit[i];

      if (bcd_result->digit[i] > 10) {
        char temp = bcd_result->digit[i] / 10;
        bcd_result->digit[i] %= 10;
        bcd_result->digit[i + 1] += temp;
      } else if (bcd_result->digit[i] == 10) {
        bcd_result->digit[i] = 0;
        bcd_result->digit[i + 1] += 1;
      }
    }
    bcd_result->sign = bcd1.sign;

  } else {
    bcd_t minuend = {0};
    bcd_t subtrahend = {0};
    if (compare_without_sign_bcd(bcd1, bcd2)) {
      minuend = bcd1;
      subtrahend = bcd2;
      bcd_result->sign = bcd1.sign;
    } else {
      minuend = bcd2;
      subtrahend = bcd1;
      bcd_result->sign = bcd2.sign;
    }
    for (int i = 0; i < 59; i++) {
      if (minuend.digit[i] < subtrahend.digit[i]) {
        bcd_result->digit[i] = (minuend.digit[i] + 10) - subtrahend.digit[i];
        int j = i + 1;
        if (minuend.digit[j] == 0) {
          while (minuend.digit[j] == 0 || j == 59) {
            minuend.digit[j] = 9;
            j += 1;
          }
          minuend.digit[j] -= 1;
        } else {
          minuend.digit[i + 1] -= 1;
        }
      } else {
        bcd_result->digit[i] = minuend.digit[i] - subtrahend.digit[i];
      }
    }
  }
}

int st_add(st_decimal value_1, st_decimal value_2, st_decimal* result) {
  *result = init_dec();
  bcd_t bcd_val_1 = {0};
  bcd_t bcd_val_2 = {0};
  bcd_t bcd_result = {0};

  ft_from_dec_to_bcd(value_1, &bcd_val_1);
  ft_from_dec_to_bcd(value_2, &bcd_val_2);

  ft_adding_bcd(bcd_val_1, bcd_val_2, &bcd_result);

  int code_error = 0;

  bank_rounding_bcd(&bcd_result);

  if (compare_with_max(bcd_result) == 0) {
    for (int i = 0; i <= 59; i++) {
      bcd_result.digit[i] = 0;
    }
    if (bcd_result.sign == 0) {
      code_error = 1;
    } else {
      code_error = 2;
    }
    bcd_result.sign = 0;
  }
  ft_from_bcd_to_dec(&bcd_result, result);
  return code_error;
}
