#ifndef HEADER
#define HEADER
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MASK_ONE_BIT 0x00000001LL
#define MASK_SIGN_INT 0X80000000
// После операции сравнить с ним на предмет переполнения
#define DECIMAL_MAX 79228162514264337593543950335
#define DECIMAL_MIN 0.0000000000000000000000000001  // 1E-28

typedef struct {
  unsigned int bits[4];
} st_decimal;

/*
  If char will be "char" without "unsigned" sign will be saved and cant fine
  shift bits
//  1000 0000 >> 1 = 1100 0000  -- char
//  1000 0000 >> 1 = 0100 0000  -- unsigned char
*/
// cannot open source file "math.h". Please run the 'Select IntelliSense
// Configuration...' command to locate your system headers.
typedef struct {
  unsigned char digit[60];
  int scale;
  int sign;
} bcd_t;

st_decimal init_dec(void);
int ft_getbit_char(bcd_t var, int idx);
int ft_getbit_dec(st_decimal var, int idx);
void ft_setbit_one_char(bcd_t *var, int idx);
void ft_setbit_zero_char(bcd_t *var, int idx);

void ft_from_dec_to_bcd(st_decimal dec, bcd_t *bcd);
void ft_from_bcd_to_dec(bcd_t *bcd, st_decimal *dec);

void ft_normalization(bcd_t *bcd1, bcd_t *bcd2);
void ft_normalization_equal_scale(bcd_t *bcd1, bcd_t *bcd2);

int ft_get_digit_bcd(bcd_t var, int idx_number);
void ft_set_digit_bcd(bcd_t *var, int idx_number, int number);

void ft_shift_bit_left_bcd(bcd_t *bcd, int shift);
void ft_shift_bit_right_bcd(bcd_t *bcd, int shift);

int ft_checkon_empty_bcd(bcd_t bcd);
int ft_get_elderbit_dec(st_decimal dec);
int ft_get_elderbit_bcd(bcd_t bcd);

void ft_print_bcd(bcd_t var);
void ft_print_binar_bcd(bcd_t var);
void ft_print_dec(st_decimal lab_rat);

void ft_revers(char str[]);

void ft_setbit_one_dec(st_decimal *dec, int index);
void ft_setbit_zero_dec(st_decimal *dec, int index);
void ft_shift_bit_left_dec(st_decimal *dec, int shift);
void ft_shift_bit_right_dec(st_decimal *dec, int shift);
int ft_get_scale_dec(st_decimal dec);
void ft_set_scale_dec(st_decimal *dec, int operand);

void ft_multiply_by_ten(st_decimal *dec);  // ?
void ft_divide_by_ten(st_decimal *dec);    // ?

int senoir_number_bcd(bcd_t bcd1);
// int    ft_normalization(st_decimal *dec1, st_decimal *dec2);
void ft_normalization_equal_scale(bcd_t *bcd1, bcd_t *bcd2);

int st_from_int_to_decimal(int src, st_decimal *dst);
int st_from_float_to_decimal(float src, st_decimal *dst);

int st_from_decimal_to_int(st_decimal src, int *dst);
int st_from_decimal_to_float(st_decimal src, float *dst);

int st_floor(st_decimal value, st_decimal *result);
int st_truncate(st_decimal value, st_decimal *result);
int st_negate(st_decimal value, st_decimal *result);

int st_add(st_decimal value_1, st_decimal value_2, st_decimal *result);
int st_sub(st_decimal value_1, st_decimal value_2, st_decimal *result);
int st_mul(st_decimal value_1, st_decimal value_2, st_decimal *result);
int st_div(st_decimal value_1, st_decimal value_2, st_decimal *result);

int st_is_less(st_decimal value1, st_decimal value2);
int st_is_less_or_equal(st_decimal value1, st_decimal value2);
int st_is_greater(st_decimal value1, st_decimal value2);
int st_is_greater_or_equal(st_decimal value1, st_decimal value2);
int st_is_equal(st_decimal value1, st_decimal value2);
int st_is_not_equal(st_decimal value1, st_decimal value2);

// сравниваем bcd
int st_is_greater_bcd(bcd_t value1, bcd_t value2);
int st_is_less_bcd(bcd_t bcd1, bcd_t bcd2);
int st_is_less_or_equal_bcd(bcd_t value1, bcd_t value2);
int st_is_greater_or_equal_bcd(bcd_t value1, bcd_t value2);
int st_is_equal_bcd(bcd_t bcd1, bcd_t bcd2);
int st_is_not_equal_bcd(bcd_t value1, bcd_t value2);
int st_round(st_decimal value, st_decimal *result);

void ft_copy_bcd(bcd_t src, bcd_t *dest);

int compare_with_min(bcd_t value);
int compare_with_max(bcd_t value);
int ft_count_digit_bcd(bcd_t bcd);

void bank_rounding_bcd(bcd_t *val);
void plus_one(bcd_t *val);
int comparsion_mantis(bcd_t val, bcd_t max, int rounding_moment);

void ft_set_abs_dec(st_decimal *dec);
void ft_copy_dec(st_decimal src, st_decimal *dest);
void ft_adding_bcd(bcd_t bcd1, bcd_t bcd2, bcd_t *bcd_result);

// деление
void sub(bcd_t bcd1, bcd_t bcd2, bcd_t *bcd_result);
void equating(bcd_t *bcd1, bcd_t bcd_result);
void neutral_earthing(bcd_t *bcd);
void bit_offset(bcd_t *bcd1);
void normalization_2(bcd_t *bcd_result, bcd_t *bcd_val_1);
void sum_result(int *flag_remains, int *flag_res, int *count_res,
                bcd_t intermediate_result);
int division_by_zero(bcd_t bcd);
int error_division_by_zero(bcd_t bcd_val_2);

#endif
