#include "st_decimal.h"

int st_round(st_decimal value, st_decimal *result) {
  *result = init_dec();
  bcd_t bcd = {0};
  bcd_t five = {0};  // 0.5
  bcd_t res = {0};
  five.digit[0] = 5;
  five.scale = 1;
  if (ft_getbit_dec(value, 127) == 1) {
    five.sign = 1;
  }
  ft_from_dec_to_bcd(value, &bcd);
  if (compare_with_max(bcd) == 1) {
    ft_adding_bcd(bcd, five, &res);
    ft_from_bcd_to_dec(&res, result);
  } else {
    ft_copy_dec(value, result);
  }

  st_truncate(*result, result);
  return (0);
}

int st_floor(st_decimal value, st_decimal *result) {
  *result = init_dec();
  bcd_t temp = {0};
  st_decimal addone = {0};  // add one if sign == 1
  addone.bits[0] = 1;
  if (ft_getbit_dec(value, 127) == 1) {
    ft_setbit_one_dec(&addone, 127);
  }
  int one = 0;

  ft_from_dec_to_bcd(value, &temp);

  while (temp.scale > 0) {
    one |= !!(temp.digit[0]);
    ft_shift_bit_right_bcd(&temp, 8);
    temp.scale--;
  }
  ft_from_bcd_to_dec(&temp, result);

  if (temp.sign == 1 && one == 1) {
    st_add(*result, addone, result);
  }
  bcd_t pr = {0};
  ft_from_dec_to_bcd(*result, &pr);
  return (0);
}

int st_truncate(st_decimal value, st_decimal *result) {
  *result = init_dec();
  bcd_t bcd = {0};

  ft_from_dec_to_bcd(value, &bcd);
  while (bcd.scale > 0) {
    ft_shift_bit_right_bcd(&bcd, 8);
    bcd.scale--;
  }
  ft_from_bcd_to_dec(&bcd, result);
  return (0);
}

int st_negate(st_decimal value, st_decimal *result) {
  int i = 0;

  while (i <= 3) {
    result->bits[i] = value.bits[i];
    i++;
  }
  int sign = 0;
  sign = (ft_getbit_dec(*result, 127));
  if (sign == 0) {
    result->bits[3] |= MASK_ONE_BIT << 31;
  } else {
    result->bits[3] &= ~(MASK_ONE_BIT << 31);
  }
  return (0);
}
