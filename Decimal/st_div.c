#include "st_decimal.h"

int st_div(st_decimal value_1, st_decimal value_2, st_decimal* result) {
  *result = init_dec();
  int error_code = 0;
  bcd_t bcd_val_1 = {0};
  bcd_t bcd_val_1_1 = {0};
  bcd_t bcd_val_2 = {0};
  bcd_t intermediate_result = {0};
  bcd_t bcd_result = {0};

  ft_from_dec_to_bcd(value_1, &bcd_val_1);
  ft_from_dec_to_bcd(value_2, &bcd_val_2);

  error_code = error_division_by_zero(bcd_val_2);

  if (error_code == 0) {
    if ((bcd_val_1.sign == 0 && bcd_val_2.sign == 0) ||
        (bcd_val_1.sign == 1 && bcd_val_2.sign == 1)) {
      bcd_result.sign = 0;
    } else {
      bcd_result.sign = 1;
    }

    bcd_result.scale = bcd_val_1.scale - bcd_val_2.scale;
    if (bcd_result.scale < 0) {
      normalization_2(&bcd_result, &bcd_val_1);
    }
    bcd_val_2.scale = 0;

    int count_mantis_val_1 = senoir_number_bcd(bcd_val_1);

    int count_res = 0;
    int count_class = 0;
    int flag_res = 1;
    int flag_remains = 0;
    bcd_val_1_1.digit[0] = bcd_val_1.digit[count_mantis_val_1];
    while (count_class < 59) {
      bit_offset(&bcd_result);
      count_res = 0;
      flag_res = 1;
      flag_remains = 0;
      while (flag_res) {
        neutral_earthing(&intermediate_result);
        intermediate_result.sign = 0;
        sub(bcd_val_1_1, bcd_val_2, &intermediate_result);
        sum_result(&flag_remains, &flag_res, &count_res, intermediate_result);
        if (flag_res) {
          equating(&bcd_val_1_1, intermediate_result);
        }
      }

      count_class += 1;
      bcd_result.digit[0] = count_res;
      if (flag_remains || count_mantis_val_1 - count_class >= 0) {
        if (flag_remains) {
          bit_offset(&bcd_val_1_1);
        }
        if (count_mantis_val_1 - count_class >= 0) {
          bcd_val_1_1.digit[0] =
              bcd_val_1.digit[count_mantis_val_1 - count_class];
        } else {
          bcd_val_1_1.digit[0] = 0;
          if (count_class < 59) {
            bcd_result.scale += 1;
          }
        }
      } else {
        break;
      }
    }
  }

  bank_rounding_bcd(&bcd_result);

  st_decimal max = {0};
  max.bits[0] = UINT_MAX;
  max.bits[1] = UINT_MAX;
  max.bits[2] = UINT_MAX;
  bcd_t bcd_max = {0};
  ft_from_dec_to_bcd(max, &bcd_max);

  if (bcd_result.sign == 0) {
    if (st_is_greater_bcd(bcd_result, bcd_max)) {
      for (int i = 0; i < 60; i++) {
        bcd_result.digit[i] = 0;
      }
      bcd_result.scale = 1;
      error_code = 1;
    }
  } else {
    bcd_result.sign = 0;
    if (st_is_greater_bcd(bcd_result, bcd_max)) {
      for (int i = 0; i < 60; i++) {
        bcd_result.digit[i] = 0;
      }
      bcd_result.scale = 1;
      error_code = 2;
    } else {
      bcd_result.sign = 1;
    }
  }

  ft_from_bcd_to_dec(&bcd_result, result);

  return error_code;
}

void sub(bcd_t bcd1, bcd_t bcd2, bcd_t* bcd_result) {  // сложение, но вычитание
  bcd2.sign = 1;
  ft_adding_bcd(bcd1, bcd2, bcd_result);
}

void equating(bcd_t* bcd1,
              bcd_t bcd_result) {  // приравнивание первого ко второму
  for (int i = 0; i < 59; i++) {
    bcd1->digit[i] = bcd_result.digit[i];
  }
}

void neutral_earthing(bcd_t* bcd) {  // зануление
  for (int i = 0; i < 59; i++) {
    bcd->digit[i] = 0;
  }
}

void bit_offset(bcd_t* bcd1) {  // смещение всех чаров на 1 вверх
  for (int i = 58; i >= 0; i--) {
    bcd1->digit[i + 1] = bcd1->digit[i];
  }
  bcd1->digit[0] = 0;
}
int error_division_by_zero(bcd_t bcd_val_2) {  // проверка деления на  0
  int flag_zero = 0;
  if (division_by_zero(bcd_val_2)) {
    flag_zero = 3;
  }
  return flag_zero;
}

int division_by_zero(bcd_t bcd) {  // если все 0 то возвращает 1
  int flag = 1;
  for (int i = 0; i < 59; i++) {
    if (bcd.digit[i] != 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}

void sum_result(int* flag_remains, int* flag_res, int* count_res,
                bcd_t intermediate_result) {
  if (division_by_zero(intermediate_result)) {
    *count_res += 1;
    *flag_res = 0;
  } else if (intermediate_result.sign == 1) {
    *flag_res = 0;
    *flag_remains = 1;
  } else {
    *count_res += 1;
  }
}

void normalization_2(bcd_t* bcd_result, bcd_t* bcd_val_1) {
  while (bcd_result->scale < 0) {
    bit_offset(bcd_val_1);
    bcd_result->scale += 1;
  }
}