#include "st_string.h"

int functionC(char* text, char* c, int* i);
int functionInt(char* text, int* d, int* i, int width, int notation);
short int functionShortInt(char* text, short int* hd, int* i, int width,
                           int notation);
long int functionLongInt(char* text, long int* ld, int* i, int width,
                         int notation);

unsigned int functionUnsignedInt(char* text, unsigned int* ud, int* i,
                                 int width, int notation);
unsigned short int functionUnsignedShortInt(char* text, unsigned short int* uhd,
                                            int* i, int width, int notation);
unsigned long int functionUnsignedLongInt(char* text, unsigned long int* uld,
                                          int* i, int width, int notation);
unsigned long long int readUnsignedLongInt(char* text, int* i, int width,
                                           int notation, int flagWidch,
                                           int* count);
unsigned long int functionP(char* text, unsigned long int* uld, int* i,
                            int width, int notation);

float functionFloat(char* text, float* f, int* i, int width);
float readFloat(char* text, int* i, int width, int flagWidth, int* count);

int st_sscanf(char* text, char* fmt, ...) {
  va_list ap;
  int d;
  int* resD;
  short int hd;
  short int* resHD;
  long int ld;
  long int* resLD;
  unsigned int ud;
  unsigned int* resUD;
  unsigned short int uhd;
  unsigned short int* resUHD;
  unsigned long int uld;
  unsigned long int* resULD;
  float* f;
  char c;
  char* resC;
  char* s;
  va_start(ap, fmt);
  int i = 0;
  int j;
  int countArg = 0;
  int intFlag = 1;
  int flagWidth;
  int notation;
  if (fmt == st_NULL) {
    countArg--;
    return countArg;
  }
  while (*fmt) {
    int width = 0;
    char widthStar = 0;
    char longElem = 0;
    int intFlagDub = 0;
    if (*fmt == '%' && *(fmt + 1) != '%') {
      fmt++;
      while (st_strspn(fmt, "0123456789*")) {
        if (*fmt == '*') {
          widthStar = *fmt;
        } else {
          width = width * 10 + (int)(*fmt - '0');
        }
        fmt++;
      }
      if (st_strspn(fmt, "hlL") == 1) {
        longElem = *fmt;
        fmt++;
        if (longElem == *fmt) {
          longElem = *fmt;
          fmt++;
        }
      }
      if (st_strspn(fmt, "cdieEfgGosuxXpn%%") == 0) {
        break;
      }
    } else if (*fmt == '%' && *(fmt + 1) == '%') {
      fmt += 2;
      i++;
    } else {
      while (*fmt == text[i] && *fmt != 'c' && text[i] != ' ') {
        fmt++;
        i++;
      }
    }
    if (intFlag == 0) {
      break;
    }
    while (((text[i] == ' ' || text[i] == '\n' || text[i] == '\t') &&
            *fmt != 'c') ||
           (text[i] == '%' && (text[i + 1] == '%' || *fmt == 'u'))) {
      i++;
    }
    if (text[i] == '\0' && countArg == 0 && *fmt != 'n' && *fmt != '%') {
      countArg--;
      break;
    }
    if (width != 0 && *fmt == 'c') {
      *fmt = 's';
    }
    switch (*fmt) {
      case 'n':
        if (widthStar == 0) {
          resD = va_arg(ap, int*);
        }
        *resD = i;
        break;
      case 's':
        intFlag = 0;
        j = 0;
        s = va_arg(ap, char*);
        flagWidth = 1;
        if (width != 0) {
          flagWidth = 0;
        }
        while (text[i] != ' ' && text[i] != '\0' && text[i] != '\t' &&
               (width > 0 || flagWidth)) {
          if (widthStar == 0) {
            *(s + j) = text[i];
          }
          i++;
          j++;
          intFlag = 1;
          if (width != 0) {
            width--;
          }
        }
        if (text[i] == '\t') {
          i++;
        }
        if (widthStar == 0) {
          *(s + j) = '\0';
          countArg += intFlag;
        }
        break;
      case 'i':
        notation = 10;
        if (text[i] == '0') {
          notation = 8;
          i++;
          if (text[i] == 'x' || text[i] == 'X') {
            notation = 16;
            i++;
          }
        }
        if (text[i] == 43) {
          i++;
        }
        if (longElem == 'h') {
          intFlag = functionShortInt(text, &hd, &i, width, notation);
          if (widthStar == 0) {
            resHD = va_arg(ap, short int*);
            *resHD = hd;
          }
        } else if (longElem == 'l') {
          intFlag = functionLongInt(text, &ld, &i, width, notation);
          if (widthStar == 0) {
            resLD = va_arg(ap, long int*);
            *resLD = ld;
          }
        } else {
          intFlag = functionInt(text, &d, &i, width, notation);
          if (widthStar == 0) {
            resD = va_arg(ap, int*);
            *resD = d;
          }
        }
        if (widthStar == 0) {
          countArg += intFlag;
        }
        break;
      case 'd':
        if (text[i] == 43) {
          i++;
          if (width != 0) {
            width--;
          }
        }
        notation = 10;
        if (longElem == 'h') {
          intFlag = functionShortInt(text, &hd, &i, width, notation);
          if (widthStar == 0) {
            resHD = va_arg(ap, short int*);
            *resHD = hd;
          }
        } else if (longElem == 'l') {
          intFlag = functionLongInt(text, &ld, &i, width, notation);
          if (widthStar == 0) {
            resLD = va_arg(ap, long int*);
            *resLD = ld;
          }
        } else {
          intFlag = functionInt(text, &d, &i, width, notation);
          if (widthStar == 0) {
            resD = va_arg(ap, int*);
            *resD = d;
          }
        }
        if (widthStar == 0) {
          countArg += intFlag;
        }
        if (text[i] == 43) {
          i++;
        }
        break;
      case 'u':
        if (text[i] == 43) {
          i++;
          if (width != 0) {
            width--;
          }
        }
        notation = 10;
        if (longElem == 'h') {
          intFlag = functionUnsignedShortInt(text, &uhd, &i, width, notation);
          if (widthStar == 0) {
            resUHD = va_arg(ap, unsigned short int*);
            *resUHD = uhd;
          }
        } else if (longElem == 'l') {
          intFlag = functionUnsignedLongInt(text, &uld, &i, width, notation);
          if (widthStar == 0) {
            resULD = va_arg(ap, unsigned long int*);
            *resULD = uld;
          }
        } else {
          intFlag = functionUnsignedInt(text, &ud, &i, width, notation);
          if (widthStar == 0) {
            resUD = va_arg(ap, unsigned int*);
            *resUD = ud;
          }
        }
        if (widthStar == 0) {
          countArg += intFlag;
        }
        break;
      case 'c':
        if (widthStar == 0) {
          resC = (char*)va_arg(ap, int*);
        }
        intFlag = functionC(text, &c, &i);
        if (widthStar == 0) {
          *resC = c;
          countArg += intFlag;
        }
        break;
      case 'f':
      case 'g':
      case 'G':
      case 'e':
      case 'E':
        if (widthStar == 0) {
          f = va_arg(ap, float*);
        }
        intFlag = functionFloat(text, f, &i, width);
        if (widthStar == 0) {
          countArg += intFlag;
        }
        break;
      case 'o':
        notation = 8;
        if (longElem == 'h') {
          intFlag = functionUnsignedShortInt(text, &uhd, &i, width, notation);
          if (widthStar == 0) {
            resUHD = va_arg(ap, unsigned short int*);
            if (intFlag != 0) {
              *resUHD = uhd;
            }
          }
        } else if (longElem == 'l') {
          intFlag = functionP(text, &uld, &i, width, notation);
          if (widthStar == 0) {
            resULD = va_arg(ap, unsigned long int*);
            if (intFlag != 0) {
              *resULD = uld;
            }
          }
        } else {
          intFlag = functionUnsignedInt(text, &ud, &i, width, notation);
          if (widthStar == 0) {
            resUD = va_arg(ap, unsigned int*);
            if (intFlag != 0) {
              *resUD = ud;
            }
          }
        }
        if (widthStar == 0 && intFlag != 0) {
          countArg++;
        }
        break;
      case 'p':
        notation = 16;
        if (text[i] == '0' && (text[i + 1] == 'x' || text[i + 1] == 'X')) {
          i += 2;
          intFlagDub = 1;
        }
        intFlag = functionP(text, &uld, &i, width, notation);
        if (widthStar == 0) {
          resULD = va_arg(ap, unsigned long int*);
          if (intFlag != 0 || intFlagDub != 0) {
            *resULD = uld;
          }
        }
        if (widthStar == 0 && (intFlag != 0 || intFlagDub != 0)) {
          countArg++;
        }
        break;
      case 'X':
      case 'x':
        notation = 16;
        if (text[i] == '0' && (text[i + 1] == 'x' || text[i + 1] == 'X')) {
          i += 2;
          intFlagDub = 1;
        }
        if (longElem == 'h') {
          intFlag = functionUnsignedShortInt(text, &uhd, &i, width, notation);
          if (widthStar == 0) {
            resUHD = va_arg(ap, unsigned short int*);
            if (intFlag != 0 || intFlagDub != 0) {
              *resUHD = uhd;
            }
          }
        } else if (longElem == 'l') {
          intFlag = functionUnsignedLongInt(text, &uld, &i, width, notation);
          if (widthStar == 0) {
            resULD = va_arg(ap, unsigned long int*);
            if (intFlag != 0 || intFlagDub != 0) {
              *resULD = uld;
            }
          }
        } else {
          intFlag = functionUnsignedInt(text, &ud, &i, width, notation);
          if (widthStar == 0) {
            resUD = va_arg(ap, unsigned int*);
            if (intFlag != 0 || intFlagDub != 0) {
              *resUD = ud;
            }
          }
        }
        if (widthStar == 0 && (intFlag != 0 || intFlagDub != 0)) {
          countArg++;
        }
        break;
    }
    fmt++;
  }
  va_end(ap);
  return countArg;
}

int functionC(char* text, char* c, int* i) {
  int count = 0;
  *c = text[*i];
  (*i)++;
  count = 1;
  return count;
}

int functionInt(char* text, int* d, int* i, int width, int notation) {
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *d = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    if (flagWidth == 0) {
      width--;
    }
    (*i)++;
  }
  (*d) = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (flagMinusStat == 1 && count == 1) {
    (*d) *= -1;
  }
  return count;
}

short int functionShortInt(char* text, short int* hd, int* i, int width,
                           int notation) {
  unsigned long long int num = 0;
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *hd = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    if (flagWidth == 0) {
      width--;
    }
    (*i)++;
  }
  num = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (num > SHRT_MAX) {
    num = SHRT_MAX;
  }
  (*hd) = num;
  if (flagMinusStat == 1 && count == 1) {
    (*hd) *= -1;
  }
  return count;
}

long int functionLongInt(char* text, long int* ld, int* i, int width,
                         int notation) {
  unsigned long long int num = 0;
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *ld = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    if (flagWidth == 0) {
      width--;
    }
    (*i)++;
  }
  num = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (num > LONG_MAX) {
    num = LONG_MAX;
  }
  (*ld) = num;
  if (flagMinusStat == 1 && count == 1) {
    if (num == LONG_MAX) {
      (*ld) *= -1;
      (*ld) -= 1;
    } else {
      (*ld) *= -1;
    }
  }
  return count;
}

unsigned int functionUnsignedInt(char* text, unsigned int* ud, int* i,
                                 int width, int notation) {
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *ud = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    (*i)++;
  }
  (*ud) = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (flagMinusStat == 1 && count == 1) {
    (*ud) *= -1;
  }
  return count;
}

unsigned short int functionUnsignedShortInt(char* text, unsigned short int* uhd,
                                            int* i, int width, int notation) {
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *uhd = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    if (flagWidth == 0) {
      width--;
    }
    (*i)++;
  }
  (*uhd) = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (flagMinusStat == 1 && count == 1) {
    (*uhd) *= -1;
  }
  return count;
}

unsigned long int functionUnsignedLongInt(char* text, unsigned long int* uld,
                                          int* i, int width, int notation) {
  unsigned long long int num = 0;
  int count = 0;
  int flagWidth = 1;

  *uld = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    if (flagWidth == 0) {
      width--;
    }
    (*i)++;
  }
  num = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (num > ULONG_MAX) {
    num = ULONG_MAX;
  }
  (*uld) = num;
  return count;
}

unsigned long long int readUnsignedLongInt(char* text, int* i, int width,
                                           int notation, int flagWidth,
                                           int* count) {
  unsigned long long int num = 0;
  int j = 0;
  int n = 0;
  int flagRead;
  char notInt[100] = {0};
  while (width > 0 || flagWidth) {
    flagRead = 0;
    if (notation == 10) {
      if (text[*i] > 47 && text[*i] < 58) {
        flagRead = 1;
      }
    }
    if (notation == 8) {
      if (text[*i] > 47 && text[*i] < 56) {
        flagRead = 1;
      }
    }
    if (notation == 16) {
      if ((text[*i] > 47 && text[*i] < 58) ||
          (text[*i] > 64 && text[*i] < 71) ||
          (text[*i] > 96 && text[*i] < 103)) {
        { flagRead = 1; }
      }
    }
    if (flagRead == 1) {
      notInt[j] = text[*i];
      (*i)++;
      j++;
      (*count) = 1;
      if (width != 0) {
        width--;
      }
    } else {
      break;
    }
  }
  while (j > 0) {
    if (notation == 10) {
      if ((ULLONG_MAX - (int)(notInt[n] - '0')) / 10 > num) {
        num = num * 10 + (int)(notInt[n] - '0');
      } else {
        num = ULLONG_MAX;
      }
    }
    if (notation == 8) {
      if ((ULLONG_MAX - (int)(notInt[n] - '0')) / 8 > num) {
        num = num * 8 + (int)(notInt[n] - '0');
      } else {
        num = ULLONG_MAX;
      }
    }
    if (notation == 16) {
      if (notInt[n] > 47 && notInt[n] < 58) {
        if ((ULLONG_MAX - (int)(notInt[n] - '0')) / 16 > num) {
          num = num * 16 + (int)(notInt[n] - '0');
        } else {
          num = ULLONG_MAX;
        }
      } else if (notInt[n] > 64 && notInt[n] < 71) {
        if ((ULLONG_MAX - (int)(notInt[n] - '7')) / 16 > num) {
          num = num * 16 + (int)(notInt[n] - '7');
        } else {
          num = ULLONG_MAX;
        }
      } else if (notInt[n] > 96 && notInt[n] < 103) {
        if ((ULLONG_MAX - (int)(notInt[n] - 'W')) / 16 > num) {
          num = num * 16 + (int)(notInt[n] - 'W');
        } else {
          num = ULLONG_MAX;
        }
      }
    }
    n++;
    j--;
  }
  return num;
}

float functionFloat(char* text, float* f, int* i, int width) {
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *f = 0.00000000;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    (*i)++;
  }
  (*f) = readFloat(text, i, width, flagWidth, &count);
  if (flagMinusStat == 1) {
    (*f) *= -1;
  }
  return count;
}

float readFloat(char* text, int* i, int width, int flagWidth, int* count) {
  float num = 0.00000000000;
  float factor = 0.1000000000;
  char notInt[100] = {0};
  int flagPoint = 1;
  int j = 0;
  while (((text[*i] > 47 && text[*i] < 58) || (text[*i] == 46 && flagPoint)) &&
         (width > 0 || flagWidth)) {
    if (text[*i] == 46) {
      flagPoint = 0;
    }
    notInt[j] = text[*i];
    (*i)++;
    j++;
    (*count) = 1;
    if (width != 0) {
      width--;
    }
  }
  j = 0;
  while (notInt[j] > 47 && notInt[j] < 58) {
    num = num * 10 + (int)(notInt[j] - '0');
    j++;
  }
  if (notInt[j] == 46) {
    j++;
    while (notInt[j] > 47 && notInt[j] < 58) {
      num = num + factor * (int)(notInt[j] - '0');
      factor *= 0.1000000000;
      j++;
    }
  }
  return num;
}

unsigned long int functionP(char* text, unsigned long int* uld, int* i,
                            int width, int notation) {
  unsigned long long int num = 0;
  int count = 0;
  int flagWidth = 1;
  int flagMinusStat = 0;
  *uld = 0;
  if (width != 0) {
    flagWidth = 0;
  }
  if (text[*i] == 45) {
    flagMinusStat = 1;
    if (flagWidth == 0) {
      width--;
    }
    (*i)++;
  }
  num = readUnsignedLongInt(text, i, width, notation, flagWidth, &count);
  if (num > ULONG_MAX) {
    num = ULONG_MAX;
  }
  (*uld) = num;
  if (flagMinusStat == 1 && count == 1) {
    (*uld) *= -1;
  }
  return count;
}
