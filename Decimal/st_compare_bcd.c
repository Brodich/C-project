#include "st_decimal.h"

int senoir_number_bcd(bcd_t bcd1) {
  int number_bcd = 0;
  for (int i = 59; i >= 0; i--) {
    if (bcd1.digit[i] != 0) {
      number_bcd = i;
      break;
    }
  }
  return number_bcd;
}

int st_is_less_bcd(bcd_t bcd1, bcd_t bcd2) {  // <

  int result = 0;
  ft_normalization(&bcd1, &bcd2);
  int start_bcd1 = senoir_number_bcd(bcd1);
  int start_bcd2 = senoir_number_bcd(bcd2);

  if (bcd1.sign == 0) {
    if (bcd2.sign == 0) {
      if (start_bcd1 < start_bcd2) {
        result = 1;
      } else if (start_bcd1 == start_bcd2) {
        for (int i = start_bcd1; i >= 0; i--) {
          if (bcd1.digit[i] < bcd2.digit[i]) {
            result = 1;
            break;
          } else if (bcd1.digit[i] > bcd2.digit[i]) {
            result = 0;
            break;
          }
        }
      }
    }
  } else {
    if (bcd2.sign == 1) {
      if (start_bcd1 > start_bcd2) {
        result = 1;
      } else if (start_bcd1 == start_bcd2) {
        for (int i = start_bcd1; i >= 0; i--) {
          if (bcd1.digit[i] > bcd2.digit[i]) {
            result = 1;
            break;
          } else {
            result = 0;
          }
        }
      }
    } else {
      result = 1;
    }
  }
  return result;
}

int st_is_less_or_equal_bcd(bcd_t value1, bcd_t value2) {  // <=
  int result = 0;
  result = st_is_less_bcd(value1, value2);
  if (result == 0) {
    result = st_is_equal_bcd(value1, value2);
  }
  return result;
}

int st_is_greater_bcd(bcd_t value1, bcd_t value2) {  // >
  int result = 0;

  if (st_is_less_or_equal_bcd(value1, value2) == 0) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}

// int st_is_greater_or_equal_bcd(bcd_t value1, bcd_t value2) {  // >=
//   int result = 0;

//   if (st_is_less_bcd(value1, value2) == 0) {
//     result = 1;
//   } else {
//     result = 0;
//   }

//   return result;
// }

int st_is_equal_bcd(bcd_t bcd1, bcd_t bcd2) {  // ==

  int result = 1;

  ft_normalization(&bcd1, &bcd2);
  if (bcd1.sign == bcd2.sign) {
    for (int i = 59; i >= 0; i--) {
      if (bcd1.digit[i] != bcd2.digit[i]) {
        result = 0;
        i = -1;
      }
    }
  } else {
    result = 0;
  }
  return result;
}

// int st_is_not_equal_bcd(bcd_t value1, bcd_t value2) {
//   int result = 0;

//   if (st_is_equal_bcd(value1, value2) == 0) {
//     result = 1;
//   } else {
//     result = 0;
//   }
//   return result;
// }

int compare_with_max(bcd_t value) {
  int result = 0;

  st_decimal max = {0};
  bcd_t max_bcd = {0};
  max.bits[0] = UINT_MAX;
  max.bits[1] = UINT_MAX;
  max.bits[2] = UINT_MAX;

  ft_from_dec_to_bcd(max, &max_bcd);
  max_bcd.sign = value.sign;
  ft_normalization(&max_bcd, &value);

  if (max_bcd.sign == 0) {
    if (st_is_less_bcd(value, max_bcd)) {
      result = 1;
    }
  } else {
    if (st_is_greater_bcd(value, max_bcd)) {
      result = 1;
    }
  }

  return result;
}