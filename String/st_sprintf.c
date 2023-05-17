#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>  // !!!!!!!

#include "st_string.h"

// int main() {
//   int d = 12;
//   char orig[100] = {0};
//   char my[100] = {0};
//   sprintf(orig, "%s", NULL);
//   printf("orig |%s|\n", orig);
//   st_sprintf(my, "%s", NULL);
//   printf("my |%s|", my);
//   return 0;
// }

int st_sprintf(char *str, const char *format, ...) {
  va_list factor;
  va_start(factor, format);
  char *pt_str = (char *)str;
  char *pt_format = (char *)format;
  int count_symbols = 0;
  char str_number[100] = {'\0'};
  for (int i = 0; (*pt_format) != '\0'; i++, pt_format++, pt_str++) {
    ++count_symbols;
    if ((*pt_format) != '%') {  // запись простого символа
      (*pt_str) = (*pt_format);
      continue;
    } else if ((*pt_format) == '%' &&
               *(pt_format + 1) == '%') {  // обработка %%
      pt_format++;
      (*pt_str) = '%';
      continue;
    }
    if ((*pt_format) != '%') {
      *(pt_str++) = *(pt_format++);
    }
    spec flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    parse_all(&flags, &pt_format, &factor);

    char *pt_pt_str = pt_str;
    char *pt_str_number = &str_number[0];
    long double number = 0;
    choose_length(&number, &flags, &factor);
    switch (flags.specifier) {
      case 'c': {
        str_number[0] = va_arg(factor, int);
      } break;
      case 'u':
      case 'i':
      case 'd': {
        specifierD(number, pt_str_number, &flags);
      } break;
      case 'X':
      case 'x': {
        specifier_SmallX_BigX_and_P(number, pt_str_number, &flags);
      } break;
      case 's': {
        char *number = va_arg(factor, char *);
        specifierS(number, pt_str_number, &flags);
      } break;
      case 'o': {
        specifierO(number, pt_str_number, &flags);
      } break;
      case 'f': {
        specifierF(number, pt_str_number, &flags);
        // printf("|%s|\n", str_number);
      } break;
      case 'E': {
        specifierE(number, pt_str_number, &flags);
      } break;
      case 'e': {
        specifierE(number, pt_str_number, &flags);
      } break;
      case 'p': {
        unsigned long long int number =
            (unsigned long long int)va_arg(factor, char *);
        specifier_SmallX_BigX_and_P(number, pt_str_number, &flags);
      } break;
      case 'n': {
        int *pt_number = va_arg(factor, int *);
        *pt_number = count_symbols - 1;
      } break;
      default:
        break;
    }
    add_flags_number(pt_str_number, &flags, &pt_str);
    count_symbols += (pt_str) - (pt_pt_str);
    st_memset(str_number, '\0', 100);
    if ((*--pt_str) == '\0') {
    }  // убрать терминирующий ноль
  }

  (*pt_str) = '\0';  // так надо
  pt_str++;
  (*pt_str) = '\n';
  va_end(factor);

  return count_symbols - 1;  // спецификатор р возвращает неправильную длину
}

// orig == "8987652.000000",
// our ==  "8987652.0000000"
