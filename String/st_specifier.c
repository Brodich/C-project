

#include "st_string.h"

void choose_length(long double *number, spec *flags, va_list *factor) {
  char int_spec[10] = {flags->specifier, '\0'};
  if (flags->length == 'h' && (st_strspn(int_spec, "idouxX") == 1)) {
    *number = (short)va_arg(*factor, int);
  } else if (flags->length == 'l' && st_strspn(int_spec, "idouxX") == 1) {
    *number = va_arg(*factor, unsigned long);
  } else if (flags->length == 'L' && st_strspn(int_spec, "eEfgG") == 1) {
    *number = va_arg(*factor, long double);
  } else if (st_strspn(int_spec, "id") == 1) {
    *number = va_arg(*factor, int);
  } else if (st_strspn(int_spec, "ouxX") == 1) {
    *number = va_arg(*factor, unsigned int);
  } else if (st_strspn(int_spec, "eEfgG") == 1) {
    *number = va_arg(*factor, double);
  }

  if (st_strspn(int_spec, "xX") == 1) {
    if (*number == 0) {
      flags->lattice = 0;
    }
  }
}

void check_sign_number(long double number, spec *flags) {
  if (signbit(number) != 0) {
    flags->negative++;
    flags->space = 0;
    flags->plus--;
    flags->width--;
  }
}

int ft_check_for_inf(long double number, char *pt_nice, spec *flags) {
  int f_exit = 0;
  if (number == 1.0 / 0.0 || number == -1.0 / 0.0) {
    f_exit = 1;
    if (flags->negative > 0) {
      *pt_nice++ = '-';
    }
    *pt_nice++ = 'i';
    *pt_nice++ = 'n';
    *pt_nice++ = 'f';
    flags->inf = 1;
    flags->accurasy = 0;
    flags->negative = 0;
    flags->width -= 3;
  }
  return (f_exit);
}

long double round_specf(long double number, spec **flags) {
  number = fmodl(number, 1);
  for (int i = 0; i < (*flags)->accurasy; i++) {
    number *= 10;
  }
  long double temp = fmodl(number, 1);
  if (fabsl(temp) > 0.5) {
    number < 0 ? number-- : number++;
  }
  return number;
}

void specifierF(long double number, char *pt_str_number, spec *flags) {
  check_sign_number(number, flags);
  if (ft_check_for_inf(number, pt_str_number, flags) == 0) {
    long double before_dot = 0.0;
    long double after_dot = 0.0;

    long double copy_number = fmodl(number, 1);
    after_dot = round_specf(copy_number, &flags);
    int count_ten_number = 0;
    for (int i = 0; i <= 18; i++) {
      if (fabsl(after_dot) < pow(10, i)) {
        count_ten_number = i;
        i = 18;
      }
    }
    before_dot = number - fmodl(number, 1);

    if (count_ten_number > flags->accurasy) {
      long double temp = after_dot * (pow(10, -count_ten_number + 1));
      before_dot += after_dot * (pow(10, -count_ten_number + 1));

      after_dot -= temp * (pow(10, count_ten_number - 1));
    } else {
    }
    if ((int)before_dot == 0) {
      *(pt_str_number)++ = '0';
    } else {
      if ((flags->specifier == 'e' || flags->specifier == 'E') &&
          before_dot >= 10) {
        before_dot /= 10;
        flags->count_e++;
      }
    }
    from_int_to_str(before_dot, &pt_str_number);
    *(pt_str_number)++ = '.';
    if (count_ten_number < flags->accurasy) {
      for (int i = 0; i < flags->accurasy - count_ten_number; i++) {
        *(pt_str_number)++ = '0';
      }
    } else if ((int)after_dot == 0) {
      for (int i = 0; i < flags->accurasy; i++) {
        *(pt_str_number)++ = '0';
      }
    }
    from_int_to_str(after_dot, &pt_str_number);
  }
  flags->accurasy = 0;
}

void specifierS(char *number, char *pt_str_number, spec *flags) {
  int check = 0;
  if (flags->accurasy != 0) {
    check = flags->accurasy;
  }
  if (number == st_NULL)
    st_strcpy(pt_str_number, "(null)");
  else if (check != 0) {
    for (; (*number) != '\0' && check != 0; check--) {
      *(pt_str_number)++ = *(number)++;
    }
  } else {
    for (; (*number) != '\0';) {
      *(pt_str_number)++ = *(number)++;
    }
  }
}

void specifier_SmallX(int temp, char **pt_reverse) {
  switch (temp) {
    case 10:
      (**pt_reverse) = 'a';
      break;
    case 11:
      (**pt_reverse) = 'b';
      break;
    case 12:
      (**pt_reverse) = 'c';
      break;
    case 13:
      (**pt_reverse) = 'd';
      break;
    case 14:
      (**pt_reverse) = 'e';
      break;
    case 15:
      (**pt_reverse) = 'f';
      break;
    default:
      (**pt_reverse) = temp + '0';

      break;
  }
  ++(*pt_reverse);
}

void specifier_BigX(int temp, char **pt_reverse) {
  switch (temp) {
    case 10:
      (**pt_reverse) = 'A';
      break;
    case 11:
      (**pt_reverse) = 'B';
      break;
    case 12:
      (**pt_reverse) = 'C';
      break;
    case 13:
      (**pt_reverse) = 'D';
      break;
    case 14:
      (**pt_reverse) = 'E';
      break;
    case 15:
      (**pt_reverse) = 'F';
      break;
    default:
      (**pt_reverse) = temp + '0';
      break;
  }
  ++(*pt_reverse);
}
void specifier_SmallX_BigX_and_P(long long int number, char *pt_str_number,
                                 spec *flags) {
  char reverse_str[100] = {0};
  char *pt_reverse = reverse_str;
  unsigned long long int temp_number = number;
  long long int temp;
  int count = 0;
  if (flags->specifier == 'p') {
    count -= 4;
  }
  (*pt_reverse++) = '\0';
  if (temp_number == 0) {
    *pt_str_number++ = '0';
  } else {
    for (; temp_number != 0; temp_number /= 16, count++) {
      temp = temp_number % 16;
      if (flags->specifier == 'x' || flags->specifier == 'p') {
        specifier_SmallX(temp, &pt_reverse);
      } else if (flags->specifier == 'X') {
        specifier_BigX(temp, &pt_reverse);
      }
    }

    for (; (*--pt_reverse) != '\0';) {
      *pt_str_number++ = (*pt_reverse);
    }
  }
}

void specifierD(long long number, char *pt_str_number, spec *flags) {
  if (flags->specifier != 'u') {
    if (number < INT_MIN) {
      number = INT_MIN;
    } else {
      if (number > INT_MAX) {
        number = INT_MAX;
      }
    }
  }
  if (number < 0) {  // перенес в choose_length // нельзя, будет переполнение
    flags->negative++;
    flags->space = 0;
    flags->width--;
    if (flags->plus) {
      flags->plus--;
    }
  }
  if (number == 0) {
    *(pt_str_number)++ = '0';
  }
  from_int_to_str(number, &pt_str_number);
}

void specifierE(long double number, char *pt_str, spec *flags) {
  check_sign_number(number, flags);
  number = fabsl(number);

  if (flags->plus == 0) {
    *(pt_str)++ = '+';
  }
  if (number == 0.0) {
    *(pt_str)++ = '0';
    *(pt_str)++ = '.';
    for (int i = 0; i < flags->accurasy; i++) {
      *(pt_str)++ = '0';
    }
    *(pt_str)++ = flags->specifier;
    *(pt_str)++ = '+';
    *(pt_str)++ = '0';
    *(pt_str)++ = '0';
    flags->accurasy = 0;
  } else {
    if (number > 1) {
      while (number >= 10) {
        number /= 10;
        flags->count_e++;
      }
    } else {
      while (number < 1) {
        number *= 10;
        flags->count_e--;
      }
    }
    int temp_accurasy = flags->accurasy;
    specifierF(number, pt_str, flags);
    pt_str += 2 + temp_accurasy;
    *(pt_str)++ = flags->specifier;
    if (flags->count_e < 0)
      *(pt_str)++ = '-';
    else
      *(pt_str)++ = '+';
    *(pt_str)++ = (abs(flags->count_e) / 10) + '0';
    *(pt_str)++ = (abs(flags->count_e) % 10) + '0';
  }
}

void from_int_to_str(long long number, char **pt_str_number) {
  char reverse_str[100] = {0};
  char *pt_reverse = reverse_str;
  pt_reverse++;
  for (; number != 0; number /= 10, pt_reverse++) {
    long long dif = number % 10;
    (*pt_reverse) = ((dif < 0) ? -1 * dif : dif) + '0';
  }
  for (; (*--pt_reverse) != '\0'; (*pt_str_number)++) {
    **pt_str_number = (*pt_reverse);
  }
}

void add_flags_minus_False(char *pt_str_number, spec **flags, char ***pt_str) {
  for (; 0 < (*flags)->width && (*flags)->zero == 0;
       (*flags)->width--) {  // обработка флага ' '
    *(**pt_str)++ = ' ';
  }

  if ((*flags)->plus == 1) {
    *(**pt_str)++ = '+';
  }
  if ((*flags)->negative == 1) {
    *(**pt_str)++ = '-';
  }
  for (; 0 < (*flags)->width && (*flags)->zero == 1;
       (*flags)->width--) {  // обработка флага ' '
    *(**pt_str)++ = '0';
  }
  if ((*flags)->specifier == 'p') {
    *(**pt_str)++ = '0';
    *(**pt_str)++ = 'x';
    (*flags)->width -= 2;
  }
  for (int j = 0; j < (*flags)->accurasy; j++) {
    *(**pt_str)++ = '0';
  }
  if ((*flags)->lattice == 1 && (*flags)->specifier == 'o') {
    *(**pt_str)++ = '0';
  }
  if ((*flags)->lattice == 1 && (*flags)->specifier == 'x') {
    *(**pt_str)++ = '0';
    *(**pt_str)++ = 'x';
  }
  if ((*flags)->lattice == 1 && (*flags)->specifier == 'X') {
    *(**pt_str)++ = '0';
    *(**pt_str)++ = 'X';
  }
  for (; *pt_str_number != '\0'; (pt_str_number)++, (**pt_str)++) {
    ***pt_str = *pt_str_number;
  }
}

void add_flags_minus_True(char *pt_str_number, spec **flags, char ***pt_str) {
  if ((*flags)->lattice == 1 && (*flags)->specifier == 'o') {
    *(**pt_str)++ = '0';
  }
  if (((*flags)->lattice == 1 && (*flags)->specifier == 'x') ||
      (*flags)->specifier == 'p') {
    *(**pt_str)++ = '0';
    *(**pt_str)++ = 'x';
  }
  if ((*flags)->lattice == 1 && (*flags)->specifier == 'X') {
    *(**pt_str)++ = '0';
    *(**pt_str)++ = 'X';
    (*flags)->width -= 2;
  }
  if ((*flags)->plus == 1) {
    *(**pt_str)++ = '+';
  }
  if ((*flags)->negative == 1) {
    *(**pt_str)++ = '-';
  }
  for (int j = 0; j < (*flags)->accurasy; j++) {
    *(**pt_str)++ = '0';
  }
  for (; *pt_str_number != '\0'; (pt_str_number)++, (**pt_str)++) {
    ***pt_str = *pt_str_number;
  }

  for (int j = 0; j < (*flags)->width; j++) {  // обработка флага ' '
    *(**pt_str)++ = ' ';
  }
}

void add_flags_float_minus_False(char *pt_str_number, spec **flags,
                                 char ***pt_str) {
  for (int j = 0; j < (*flags)->width; j++) {  // обработка флага ' '
    if ((*flags)->zero) {
      (*flags)->accurasy++;
    }
    if ((*flags)->zero == 1 && (*flags)->inf == 0) {  // !!!!!
      if ((*flags)->negative == 1) {
        *(**pt_str)++ = '-';
        (*flags)->negative = 0;
      } else if ((*flags)->plus == 1) {
        *(**pt_str)++ = '+';
        (*flags)->plus = 0;
      }
      *(**pt_str)++ = '0';
    } else {
      *(**pt_str)++ = ' ';
    }
  }
  if ((*flags)->plus == 1) {
    *(**pt_str)++ = '+';
  }
  if ((*flags)->negative == 1) {
    *(**pt_str)++ = '-';
  }

  for (; *pt_str_number != '\0'; (pt_str_number)++, (**pt_str)++) {
    ***pt_str = *pt_str_number;
  }
}

void add_flags_float_minus_True(char *pt_str_number, spec **flags,
                                char ***pt_str) {
  if ((*flags)->plus == 1) {
    *(**pt_str)++ = '+';
  }
  if ((*flags)->negative == 1) {
    *(**pt_str)++ = '-';
  }
  for (; *pt_str_number != '\0'; (pt_str_number)++, (**pt_str)++) {
    ***pt_str = *pt_str_number;
  }
  if ((*flags)->inf == 0) {
    for (int j = 0; j < (*flags)->accurasy; j++) {
      *(**pt_str)++ = '0';
    }
    for (int j = 0; j < (*flags)->accurasy; j++) {
      *(**pt_str)++ = ' ';
    }
  }

  for (int j = 0; j < (*flags)->width; j++) {  // обработка флага ' '
    *(**pt_str)++ = ' ';
  }
}

void add_flags_number(char *pt_str_number, spec *flags, char **pt_str) {
  if (flags->negative) {
    flags->plus--;
  }
#ifdef __linux__
  if (flags->specifier == '%') {
    *(*pt_str)++ = '%';
  }
#endif
#ifdef __APPLE__
  if (flags->specifier == '%' && flags->minus == 1) {
    *(*pt_str)++ = '%';
  }
#endif

  if (flags->specifier == 's' || flags->specifier == 'c') {
    flags->accurasy = 0;
  }
  if (flags->specifier != 'f') {  // maybe problem with %e and %g
    flags->accurasy -= st_strlen(pt_str_number);
  }
  if (flags->accurasy < 0) {
    flags->accurasy = 0;
  }

  if (flags->inf == 0) {
    flags->width -= flags->accurasy;

    flags->width -= st_strlen(pt_str_number);
  }
  if (flags->plus == 1) {
    flags->space = 0;
    flags->width--;
  }

  if (flags->space == 1) {
    *(*pt_str)++ = ' ';
    flags->width--;
  }

  if (flags->specifier == 'f') {
    if (flags->minus == 0) {
      add_flags_float_minus_False(pt_str_number, &flags, &pt_str);
    } else {
      add_flags_float_minus_True(pt_str_number, &flags, &pt_str);
    }
    flags->minus = 2;
  }
  if (flags->minus == 0) {
    add_flags_minus_False(pt_str_number, &flags, &pt_str);
  } else if (flags->minus == 1) {
    add_flags_minus_True(pt_str_number, &flags, &pt_str);
  }
#ifdef __APPLE__
  if (flags->specifier == '%' && flags->minus == 0) {
    *(*pt_str)++ = '%';
  }

#endif
}

int specifierO(unsigned long number, char *pt_str_number, spec *flags) {
  char reverse_str[100] = {0};
  char *pt_reverse = &reverse_str[0];
  pt_reverse++;
  int count = 0;  // скок символов записываем
  if (flags->length == 'h') {
    count = 6;
  } else if (flags->length == 'l') {
    count = 22;
  } else {
    count = 11;
  }
  if (number == 0.0) {
    *pt_reverse = '0';
    flags->lattice = 0;
  } else {
    for (; number != 0; number /= 8, pt_reverse++) {
      *pt_reverse = number % 8 + '0';
    }
    pt_reverse--;
  }

  for (; *pt_reverse != '\0' && count != 0;
       pt_reverse--, pt_str_number++, count--) {
    *pt_str_number = *pt_reverse;
  }
  return 0;
}

void parse_spec(spec **flags, char ***pt_format) {
  switch (***pt_format) {
    case 'c':
      (*flags)->specifier = 'c';
      break;
    case 'd':
      (*flags)->specifier = 'd';
      break;
    case 'i':
      (*flags)->specifier = 'i';
      break;
    case 'e':
      (*flags)->specifier = 'e';
      break;
    case 'f':
      (*flags)->specifier = 'f';
      break;
    case 'g':
      (*flags)->specifier = 'g';
      break;
    case 'G':
      (*flags)->specifier = 'G';
      break;
    case 's':
      (*flags)->specifier = 's';
      break;
    case 'o':
      (*flags)->specifier = 'o';
      break;
    case 'u':
      (*flags)->specifier = 'u';
      break;
    case 'x':
      (*flags)->specifier = 'x';
      break;
    case 'X':
      (*flags)->specifier = 'X';
      break;
    case 'p':
      (*flags)->specifier = 'p';
      break;
    case 'n':
      (*flags)->specifier = 'n';
      break;
    case 'E':
      (*flags)->specifier = 'E';
      break;
    case '%':
      (*flags)->specifier = '%';
    default:
      break;
  }
}

void parse_flags(spec **flags, char **pt_format) {
  for (int j = st_strspn((const char *)(*pt_format), " +-#0"); j > 0; j--) {
    if ((**pt_format) == '+') {
      (*flags)->plus += 1;
      (*pt_format)++;
    } else if ((**pt_format) == ' ') {
      (*flags)->space = 1;
      (*pt_format)++;
    }
    if ((**pt_format) == '-') {
      (*flags)->minus = 1;
      (*pt_format)++;
    } else if ((**pt_format) == '0') {
      (*flags)->zero = 1;
      (*pt_format)++;
    }
    if ((**pt_format) == '#') {
      (*flags)->lattice = 1;
      (*pt_format)++;
    }
  }
}

void parse_width(spec **flags, char **pt_format, va_list *factor) {
  int numberW = 0;

  if ((**pt_format) == '*') {
    (*flags)->width += va_arg(*factor, int);
    (*pt_format)++;
  } else {
    for (int i = st_strspn((const char *)(*pt_format), "0123456789"); i > 0;
         i--, (*pt_format)++) {
      numberW += (**pt_format) - '0';
      numberW *= 10;
    }
    numberW /= 10;
    (*flags)->width += numberW;
  }
}

void parse_accur(spec **flags, char **pt_format, va_list *factor) {
  int numberA = 0;
  (*flags)->dot = -1;
  if ((**pt_format) == '.') {
    (*flags)->dot = 1;
    (*pt_format)++;
    if ((**pt_format) == '*') {
      (*flags)->accurasy += va_arg(*factor, int);
      (*pt_format)++;
    } else {
      for (int i = st_strspn((const char *)(*pt_format), "0123456789"); i > 0;
           i--, (*pt_format)++) {
        numberA += (**pt_format) - '0';
        numberA *= 10;
      }
      numberA /= 10;
      (*flags)->accurasy += numberA;
    }
  }
}
void parse_all(spec *flags, char **pt_format, va_list *factor) {
  (*pt_format)++;

  // get flags
  parse_flags(&flags, pt_format);

  // get width
  parse_width(&flags, pt_format, factor);

  // get accur
  parse_accur(&flags, pt_format, factor);

  parse_length(&flags, pt_format);

  parse_spec(&flags, &pt_format);

  // handle priority flags
  parse_priority(&flags);
}

void parse_length(spec **flags, char **pt_format) {
  if ((**pt_format) == 'h') {
    (*flags)->length = 'h';
    (*pt_format)++;
  }
  if ((**pt_format) == 'l') {
    (*flags)->length = 'l';
    (*pt_format)++;
  }
  if ((**pt_format) == 'L') {
    (*flags)->length = 'L';
    (*pt_format)++;
  }
}

// handle priority flags
void parse_priority(spec **flags) {
  if ((*flags)->plus) {
    (*flags)->space = 0;
  }
  if ((*flags)->minus) {
    (*flags)->zero = 0;
  }
  char be[] = {((*flags)->specifier), '\0'};
  if (st_strspn(be, "ouxX") == 1) {
    (*flags)->space = 0;
  }
  if (st_strspn(be, "dioxX") == 1 && ((*flags)->accurasy > 0)) {
    (*flags)->zero = 0;
  }
  if (st_strspn(be, "difp") != 1) {  // ?
    (*flags)->plus--;
  }
  if ((*flags)->lattice && (*flags)->specifier == 'o') {
    (*flags)->width--;
    (*flags)->accurasy--;
  }

  if (((*flags))->specifier == 'p') {
    ((*flags))->width -= 2;
  }
  if ((*flags)->dot == -1 && (*flags)->specifier == 'f') {
    (*flags)->accurasy = 6;
  }
  if ((*flags)->dot == -1 &&
      ((*flags)->specifier == 'e' || (*flags)->specifier == 'E')) {
    (*flags)->accurasy = 6;
  }
#ifdef __linux__
  if ((*flags)->specifier == 'c' || (*flags)->specifier == 'p' ||
      (*flags)->specifier == 's') {
    (*flags)->zero = 0;
  }
#endif

  if ((*flags)->specifier == 'c') {
    (*flags)->space = 0;
#ifdef __APPLE__
    (*flags)->plus = 0;
#endif
  }
  if ((*flags)->specifier == 'p') {
    (*flags)->zero = 0;
#ifdef __APPLE__
    (*flags)->space = 0;
    (*flags)->plus = 0;
#endif
  }

  if ((*flags)->specifier == 'c' || (*flags)->specifier == 's') {
    (*flags)->space = 0;
  }
  if ((*flags)->specifier == '%') {
    (*flags)->space = 0;
    (*flags)->accurasy = 0;
    (*flags)->width--;
  }
#ifdef __linux__
  if ((*flags)->specifier == '%') {
    (*flags)->width = 0;
  }
#endif
}
