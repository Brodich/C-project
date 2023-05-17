#include "st_decimal.h"

int st_sub(st_decimal value_1, st_decimal value_2, st_decimal *result) {
  *result = init_dec();
  int code_error = 0;

  if (ft_getbit_dec(value_2, 127) == 0) {
    ft_setbit_one_dec(&value_2, 127);
  } else {
    ft_setbit_zero_dec(&value_2, 127);
  }
  code_error = st_add(value_1, value_2, result);

  return code_error;
}