#include "st_decimal.h"

st_decimal init_dec(void) {
  st_decimal dec;
  dec.bits[0] = 0;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  return (dec);
}

void ft_copy_dec(st_decimal src, st_decimal *dest) {
  dest->bits[0] = src.bits[0];
  dest->bits[1] = src.bits[1];
  dest->bits[2] = src.bits[2];
  dest->bits[3] = src.bits[3];
}

// Нахождение самого старшего бита для bcd
int ft_get_elderbit_dec(st_decimal dec) {
  int i = 95;
  while (i >= 0 && ft_getbit_dec(dec, i) == 0) {
    i--;
  }
  return (i);
}

int ft_getbit_dec(st_decimal var, int idx) {
  int res = !!((var.bits[idx / 32]) & (MASK_ONE_BIT << idx % 32));

  return res;
}

void ft_set_scale_dec(st_decimal *dec, int operand) {
  int sign = 0;
  if (ft_getbit_dec(*dec, 127) == 1) sign = 1;

  dec->bits[3] = operand;
  dec->bits[3] <<= 16;

  ft_setbit_zero_dec(dec, 127);
  if (sign == 1) ft_setbit_one_dec(dec, 127);
}

// /*
//     Counts scale from 16bit to 23bit
//     255 max
// */
int ft_get_scale_dec(st_decimal dec) {
  int scale = 0;
  int index = 16;
  int power = 0;

  while (index <= 23) {
    if (ft_getbit_dec(dec, index + 32 * 3) == 1) {
      scale += pow(2, power);
    }
    index++;
    power++;
  }

  return (scale);
}

void ft_shift_bit_right_dec(st_decimal *dec, int shift) {
  st_decimal temp_int = {0};
  int copy_shift = shift;
  int byte = 2;

  while (byte >= 0) {
    while (copy_shift > 0) {
      if (byte == 2) temp_int.bits[1] = temp_int.bits[1] >> 1;
      if (byte == 1) temp_int.bits[0] = temp_int.bits[0] >> 1;
      if ((ft_getbit_dec(*dec, byte * 32) == 1) &&
          (byte == 2 || byte == 1))  // смотрим есть младший бит у инта
      {
        temp_int.bits[byte - 1] |= (unsigned int)pow(2, 31);
      }
      dec->bits[byte] = dec->bits[byte] >> 1;

      copy_shift--;
    }
    copy_shift = shift;
    byte--;
  }

  byte = 0;
  while (byte <= 2) {
    dec->bits[byte] = dec->bits[byte] | temp_int.bits[byte];
    byte++;
  }
}

// /*
//     0101 --- before
//	   1010 --- after
// */
// void ft_shift_bit_left_dec(st_decimal *dec, int shift) {
//   st_decimal temp_int = {0};
//   int copy_shift = shift;
//   int byte = 0;

//   while (byte < 3) {
//     while (copy_shift > 0) {
//       temp_int.bits[byte + 1] = temp_int.bits[byte + 1] << 1;
//       if ((ft_getbit_dec(*dec, 31 + byte * 32) ==
//            1))  // смотрим есть ли самый старший бит у инта
//       {
//         temp_int.bits[byte + 1] |= 0b1;
//       }
//       dec->bits[byte] = dec->bits[byte] << 1;
//       copy_shift--;
//     }
//     copy_shift = shift;
//     byte++;
//   }
//   byte = 1;
//   while (byte < 3) {
//     dec->bits[byte] = dec->bits[byte] | temp_int.bits[byte];
//     byte++;
//   }
// }

void ft_setbit_zero_dec(st_decimal *dec, int index) {
  dec->bits[index / 32] &= ~(MASK_ONE_BIT << index % 32);
}

void ft_setbit_one_dec(st_decimal *dec, int idx) {
  (dec)->bits[idx / 32] |= (MASK_ONE_BIT << (idx % 32));
}
