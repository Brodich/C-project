#include "st_decimal.h"

int null_check(st_decimal value1, st_decimal value2) {
  int result = 0;
  if (value1.bits[0] == 0 && value1.bits[1] == 0 && value1.bits[2] == 0 &&
      value2.bits[0] == 0 && value2.bits[1] == 0 && value1.bits[2] == 0) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

int st_is_less(st_decimal value1, st_decimal value2) {  // <
  bcd_t bcd1 = {0};
  bcd_t bcd2 = {0};
  int result = 0;

  ft_from_dec_to_bcd(value1, &bcd1);
  ft_from_dec_to_bcd(value2, &bcd2);
  result = st_is_less_bcd(bcd1, bcd2);

  return result;
}

int st_is_less_or_equal(st_decimal value1, st_decimal value2) {  // <=
  int result = 0;
  result = st_is_less(value1, value2);
  if (result == 0) {
    result = st_is_equal(value1, value2);
  }
  return result;
}

int st_is_greater(st_decimal value1, st_decimal value2) {  // >
  int result = 0;

  if (st_is_less_or_equal(value1, value2) == 0) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}

int st_is_greater_or_equal(st_decimal value1, st_decimal value2) {  // >=
  int result = 0;

  if (st_is_less(value1, value2) == 0) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}

int st_is_equal(st_decimal value1, st_decimal value2) {  // ==
  bcd_t bcd1 = {0};
  bcd_t bcd2 = {0};
  int result = 1;

  ft_from_dec_to_bcd(value1, &bcd1);
  ft_from_dec_to_bcd(value2, &bcd2);

  ft_normalization(&bcd1, &bcd2);
  if (bcd1.sign == bcd2.sign) {
    for (int i = 29; i >= 0; i--) {
      if (bcd1.digit[i] != bcd2.digit[i]) {
        result = 0;
        break;
      }
    }
  } else {
    if (null_check(value1, value2)) {
      result = 1;
    } else {
      result = 0;
    }
  }

  return result;
}

int st_is_not_equal(st_decimal value1, st_decimal value2) {
  int result = 0;

  if (st_is_equal(value1, value2) == 0) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}
