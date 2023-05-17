#ifndef _st_STRING_H
#define _st_STRING_H
#define st_NULL (void *)0
typedef unsigned long st_size_t;

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct spec1 {
  int minus;
  int plus;
  int space;
  int lattice;  // #
  int zero;

  int width;
  int width_star;  // *

  int accurasy;  // .
  int accurasy_star;
  char specifier;
  char length;
  int negative;
  int dot;
  int round_float;
  int count_e;

  int inf;  // check for 1.0/0.0
} spec;

void *st_memchr(const void *str, int c, st_size_t n);
int st_memcmp(const void *str1, const void *str2, st_size_t n);
void *st_memcpy(void *dest, const void *src, st_size_t n);
void *st_memmove(void *dest, const void *src, st_size_t n);
void *st_memset(void *str, int c, st_size_t n);
char *st_strcat(char *dest, const char *src);
char *st_strncat(char *dest, const char *src, st_size_t n);
char *st_strchr(const char *str, int c);
int st_strcmp(const char *str1, const char *str2);
int st_strncmp(const char *str1, const char *str2, st_size_t n);
char *st_strrchr(const char *str, int c);
st_size_t st_strlen(const char *str);
char *st_strcpy(char *dest, const char *src);
char *st_strncpy(char *dest, const char *src, st_size_t n);
st_size_t st_strcspn(const char *str1, const char *str2);
char *st_strpbrk(const char *str1, const char *str2);
st_size_t st_strspn(const char *str1, const char *str2);
char *st_strstr(const char *haystack, const char *needle);
char *st_strtok(char *str, const char *delim);
char *st_strerror(int errnum);

void *st_to_upper(const char *str);
void *st_to_lower(const char *str);
void *st_insert(const char *src, const char *str, st_size_t start_index);
void *st_trim(const char *src, const char *trim_chars);

int st_sprintf(char *str, const char *format, ...);
int st_sscanf(char *text, char *fmt, ...);

void parse_all(spec *flags, char **pt_format, va_list *factor);
void parse_flags(spec **flags, char **pt_format);
void parse_width(spec **flags, char **pt_format, va_list *factor);
void parse_accur(spec **flags, char **pt_format, va_list *factor);
void parse_length(spec **flags, char **pt_format);
void parse_spec(spec **flags, char ***pt_format);
void parse_priority(spec **flags);
void choose_length(long double *number, spec *flags, va_list *factor);

long double round_specf(long double number, spec **flags);
void specifierF(long double number, char *pt_str_number, spec *flags);
int ft_check_for_inf(long double number, char *pt_nice, spec *flags);
int ft_get_accur_irrel(long double *after_dot_number, long *number_accur,
                       long *number_irrelevant, long long *fin_accur,
                       spec *flags);
void ft_put_whole_part(char *reverse_whole_part, char **pt_nice, spec *flags);
void specifierD(long long number, char *pt_str_number, spec *flags);
void from_int_to_str(long long number, char **pt_str_number);
void specifierS(char *number, char *pt_str_number, spec *flags);  // +
void specifier_SmallX_BigX_and_P(long long int number, char *pt_str_number,
                                 spec *flags);       // +
void specifier_SmallX(int temp, char **pt_reverse);  // +
void specifier_BigX(int temp, char **pt_reverse);    // +
void add_flags_minus_False(char *pt_str_number, spec **flags, char ***pt_str);
void add_flags_minus_True(char *pt_str_number, spec **flags, char ***pt_str);

int specifierO(unsigned long number, char *pt_str_number, spec *flags);
void add_flags_number(char *pt_str_number, spec *flags, char **pt_str);

void specifierE(long double number, char *pt_str, spec *flags);
#endif
