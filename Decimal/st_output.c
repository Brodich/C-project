#include "st_decimal.h"

void ft_print_binar_bcd(bcd_t var) {
  int idx = 86;  // самый старший бит с которого начинается вывод
  int idx_char = idx / 8;
  while (idx >= 0) {
    printf("%d", ft_getbit_char(var, idx));
    if (idx % 8 == 0 && idx != 0) {
      printf("   ");
    }
    if (idx % 8 == 0) {
      idx_char--;
    }
    idx--;
  }
  printf(" ---- bit value in bcd\n");
}

void ft_print_bcd(bcd_t var) {
  int idx_char = 59;
  while (idx_char >= 0) {
    printf("|%2.1i|", idx_char);
    idx_char--;
  }
  printf(" -----  This global index of digit");
  printf("\n");
  idx_char = 59;
  while (idx_char >= 0) {
    // printf("| %i|", ft_get_digit_bcd(var, idx_char)); // для полубайтов
    printf("| %i|", var.digit[idx_char]);
    idx_char--;
  }
  printf(" -----  Digit in BCD\n");
}

void ft_print_dec(st_decimal lab_rat) {
  char sym;
  int j = 0;
  int i = 3;
  int g = 0;
  char str[35];
  while (i != -1) {
    while (j != 32) {
      (sym) = (lab_rat.bits[i] % 2) + '0';
      str[j] = sym;
      lab_rat.bits[i] /= 2;
      j++;
    }
    ft_revers(&str[0]);

    while (g != 32) {
      printf("%c", str[g]);
      g++;
      if (g % 8 == 0) {
        printf(" ");
      }
    }
    printf("   ");
    g = 0;
    j = 0;
    i--;
  }
  printf(" ---  bits in decimal");
  printf("\n");
}

void ft_revers(char *str) {
  char temp;
  int j = 0;
  char *pt = str;
  while (j != 16) {
    temp = *(pt + j);
    *(pt + j) = (*(pt + 31 - j));
    (*(pt + 31 - j)) = temp;
    j++;
  }
  j = 0;
}
