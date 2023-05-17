#include "st_decimal.h"

int st_mul(st_decimal value_1, st_decimal value_2, st_decimal *result) {
  *result = init_dec();
  int return_number = 0;
  bcd_t bcd_val_1 = {0};
  bcd_t bcd_val_2 = {0};
  bcd_t bcd_result = {0};

  st_decimal max = {0};
  max.bits[0] = UINT_MAX;
  max.bits[1] = UINT_MAX;
  max.bits[2] = UINT_MAX;
  bcd_t bcd_max = {0};
  ft_from_dec_to_bcd(max, &bcd_max);
  ft_from_dec_to_bcd(value_1, &bcd_val_1);
  ft_from_dec_to_bcd(value_2, &bcd_val_2);

  if ((bcd_val_1.sign == 0 && bcd_val_2.sign == 0) ||
      (bcd_val_1.sign == 1 && bcd_val_2.sign == 1)) {
    bcd_result.sign = 0;
  } else {
    bcd_result.sign = 1;
  }

  bcd_result.scale = bcd_val_1.scale + bcd_val_2.scale;

  int temp_result = 0;
  int i = 0;
  int j = 0;
  for (; i < 30; i++) {
    for (; j < 30; j++) {
      temp_result =
          (bcd_val_1.digit[j] * bcd_val_2.digit[i]) + bcd_result.digit[i + j];
      bcd_result.digit[i + j] = temp_result % 10;
      bcd_result.digit[i + j + 1] += temp_result / 10;
    }
    j = 0;
  }

  bank_rounding_bcd(&bcd_result);

  if (bcd_result.sign == 0) {
    if (st_is_greater_bcd(bcd_result, bcd_max)) {
      for (int i = 0; i < 60; i++) {
        bcd_result.digit[i] = 0;
      }
      bcd_result.scale = 1;
      return_number = 1;
    }
  } else {
    bcd_result.sign = 0;
    if (st_is_greater_bcd(bcd_result, bcd_max)) {
      for (int i = 0; i < 60; i++) {
        bcd_result.digit[i] = 0;
      }
      bcd_result.scale = 1;
      return_number = 2;
    } else {
      bcd_result.sign = 1;
    }
  }

  ft_from_bcd_to_dec(&bcd_result, result);
  return return_number;
}

void bank_rounding_bcd(bcd_t *val) {
  st_decimal max = {0};
  max.bits[0] = UINT_MAX;
  max.bits[1] = UINT_MAX;
  max.bits[2] = UINT_MAX;
  bcd_t bcd_max = {0};
  ft_from_dec_to_bcd(max, &bcd_max);

  bcd_t bcd_val_2 = {0};
  int rounding_moment = 0;
  int count_mantis = senoir_number_bcd(*val) + 1;
  int whole_part = count_mantis - val->scale;
  if (whole_part > 0) {
    rounding_moment = count_mantis - 29;
    if (comparsion_mantis(*val, bcd_max, rounding_moment)) {
      rounding_moment += 1;
    }
  } else {
    rounding_moment = val->scale - 28;
  }
  if (rounding_moment > 0) {
    if (rounding_moment > val->scale) {
      rounding_moment = val->scale;
    }
    for (int i = 0; i <= 59 - rounding_moment; i++) {
      bcd_val_2.digit[i] = val->digit[i + rounding_moment];
    }
    bcd_val_2.scale = val->scale - rounding_moment;

    if (rounding_moment == 0) {  // dange, make for valgrind
      rounding_moment = 1;
    }
    if (val->digit[rounding_moment - 1] > 5) {
      plus_one(&bcd_val_2);
    } else if (val->digit[rounding_moment - 1] == 5) {
      int flag_scale = 0;
      int p = rounding_moment - 1;
      while (p > 0) {
        p--;
        if (val->digit[p] != 0) {
          flag_scale = 1;
        }
      }
      if (bcd_val_2.digit[0] % 2 == 1 && flag_scale == 1) {
        plus_one(&bcd_val_2);
      }
    }

    for (int i = 0; i <= 59; i++) {
      val->digit[i] = bcd_val_2.digit[i];
    }
    val->scale = bcd_val_2.scale;
  }
}

void plus_one(bcd_t *val) {
  int j = 0;
  while (val->digit[j] == 9) {
    val->digit[j] = 0;
    j++;
  }
  val->digit[j] += 1;
}

int comparsion_mantis(bcd_t val, bcd_t max, int rounding_moment) {
  int result = 0;
  for (int i = 28; i >= 0; i--) {
    if (val.digit[i + rounding_moment] > max.digit[i]) {
      result = 1;
      break;
    } else if (val.digit[i + rounding_moment] < max.digit[i]) {
      result = 0;
      break;
    }
  }
  return result;
}