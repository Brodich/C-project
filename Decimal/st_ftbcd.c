#include "st_decimal.h"

void ft_normalization_equal_scale(bcd_t* bcd1, bcd_t* bcd2) {
  // before
  // src1 =    -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  // after
  // src1 =    -12345677.987654345678987654346;
  // src2 = -87654323456.987654567898765300000;
  while (bcd1->scale > bcd2->scale) {
    ft_shift_bit_left_bcd(bcd2, 8);
    bcd2->scale++;
  }

  while (bcd2->scale > bcd1->scale) {
    ft_shift_bit_left_bcd(bcd1, 8);
    bcd1->scale++;
  }
}

void ft_normalization(bcd_t* bcd1, bcd_t* bcd2) {
  bcd_t copy_bcd1 = {0};
  bcd_t copy_bcd2 = {0};

  ft_copy_bcd(*bcd1, &copy_bcd1);
  ft_copy_bcd(*bcd2, &copy_bcd2);

  ft_normalization_equal_scale(&copy_bcd1, &copy_bcd2);

  ft_copy_bcd(copy_bcd1, bcd1);
  ft_copy_bcd(copy_bcd2, bcd2);

  int count_digit_1 = senoir_number_bcd(*bcd1);
  int count_digit_2 = senoir_number_bcd(*bcd2);

  while (count_digit_1 > 28 || count_digit_2 > 28) {
    ft_shift_bit_right_bcd(bcd1, 8);
    ft_shift_bit_right_bcd(bcd2, 8);
    count_digit_1--;
    count_digit_2--;
  }
}

/*
    Для полубайтов
*/
int ft_get_digit_bcd(bcd_t var, int idx_number) {
  int res = 0;
  int idx = 0 + idx_number * 4;
  int degree = 0;

  while (idx <= 3 + idx_number * 4) {
    if (ft_getbit_char(var, idx)) {
      res += pow(2, degree);
    }
    degree++;
    idx++;
  }
  return (res);
}

/*
    number = От 0 до 9
    Для полубайтов
*/
void ft_set_digit_bcd(bcd_t* var, int idx_number, int number) {
  int idx = 0 + idx_number * 4;  // Начальный индекс бита у числа
  int i = 0;

  // Зануляю биты числа
  while (i <= 3) {
    ft_setbit_zero_char(var, idx + i);
    i++;
  }
  idx = 0 + idx_number * 4;

  // Если число в бсд не четное нужно сдвинуть биты чтобы включить нужные биты
  if (idx_number % 2 != 0) {
    number <<= 4;
  }
  var->digit[idx_number / 2] |= number;
}

int ft_count_digit_bcd(bcd_t bcd) {
  int i = 58;

  while ((bcd.digit[i] < 1 || bcd.digit[i] > 9) && i >= 0) {
    i--;
  }
  return (i);
}

void ft_from_dec_to_bcd(st_decimal dec, bcd_t* bcd) {
  bcd_t compress_bcd = {0};
  int count_iteration = ft_get_elderbit_dec(
      dec);  // Первый самый старший бит у децимала по индексу
  int number_bcd = 0;
  int i = 0;
  if (ft_getbit_dec(dec, 127) == 1) {
    ft_setbit_one_dec(&dec, 127);
    bcd->sign = 1;
  }
  while (count_iteration >= 0) {
    while (i <= 31) {
      number_bcd = ft_get_digit_bcd(compress_bcd, i);
      if (number_bcd >= 5) {
        ft_set_digit_bcd(&compress_bcd, i, number_bcd + 3);
      }
      i++;
    }
    ft_shift_bit_left_bcd(&compress_bcd, 1);
    if (ft_getbit_dec(dec, count_iteration) == 1) {
      ft_setbit_one_char(&compress_bcd, 0);
    }
    count_iteration--;
    i = 0;
  }
  for (int j = 0; j <= 31; j++)
    bcd->digit[j] = (j % 2 == 0) ? compress_bcd.digit[j / 2] & 0x0f
                                 : compress_bcd.digit[(j / 2)] >> 4 & 0x0f;

  bcd->scale = ft_get_scale_dec(dec);
}

void ft_from_bcd_to_dec(bcd_t* bcd, st_decimal* dec) {
  *dec = init_dec();
  bcd_t compress_bcd = {0};  // из неё будет перевод в децимал
  int j = 0;

  while (j <= 29) {
    if (j % 2 == 0) {
      compress_bcd.digit[j / 2] |= bcd->digit[j];
    } else {
      compress_bcd.digit[j / 2] |= bcd->digit[j] << 4;
    }
    j++;
  }

  int i = 0;
  j = 0;
  int number_bcd = 0;
  while (i <= 95) {
    ft_shift_bit_right_dec(dec, 1);
    if (ft_getbit_char(compress_bcd, 0) == 1) {
      ft_setbit_one_dec(dec, 95);
    }
    ft_shift_bit_right_bcd(&compress_bcd, 1);

    while (j <= 31) {
      number_bcd = ft_get_digit_bcd(compress_bcd, j);
      if (number_bcd >= 8) {
        ft_set_digit_bcd(&compress_bcd, j, number_bcd - 3);
      }
      j++;
    }
    i++;
    j = 0;
  }

  ft_set_scale_dec(dec, bcd->scale);
  if (bcd->sign != 0) {
    ft_setbit_one_dec(dec, 127);
  }
}

void ft_shift_bit_left_bcd(bcd_t* bcd, int shift) {
  bcd_t temp_bcd = {0};
  int i = 59;

  while (shift > 0) {
    i = 58;
    while (i >= 0) {
      temp_bcd.digit[i + 1] = bcd->digit[i] >> 7;
      i--;
    }
    i = 59;
    while (i >= 0) {
      bcd->digit[i] <<= 1;
      bcd->digit[i] |= temp_bcd.digit[i];
      i--;
    }
    shift--;
  }
}

// AWESOME
void ft_shift_bit_right_bcd(bcd_t* bcd, int shift) {
  bcd_t temp_bcd = {0};
  int i = 59;

  while (shift > 0) {
    i = 59;
    while (i >= 1) {
      temp_bcd.digit[i - 1] = bcd->digit[i] << 7;
      i--;
    }
    i = 59;
    while (i >= 0) {
      bcd->digit[i] >>= 1;
      bcd->digit[i] |= temp_bcd.digit[i];
      i--;
    }
    shift--;
  }
}

void ft_setbit_one_char(bcd_t* var, int idx) {
  var->digit[idx / 8] |= MASK_ONE_BIT << (idx % 8);
}

/*
    Инвертируем маску бита
    Было   00000001
    Стало  11111110
*/
void ft_setbit_zero_char(bcd_t* var, int idx) {
  (var)->digit[idx / 8] &= ~(MASK_ONE_BIT << (idx % 8));
}

int ft_getbit_char(bcd_t var, int idx) {
  int res = !!((var.digit[idx / 8]) & (MASK_ONE_BIT << idx % 8));

  return res;
}

void ft_copy_bcd(bcd_t src, bcd_t* dest) {
  int i = 0;
  while (i <= 59) {
    dest->digit[i] = src.digit[i];
    i++;
  }
  dest->scale = src.scale;
  dest->sign = src.sign;
}
