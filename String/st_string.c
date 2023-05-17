#include "st_string.h"

char *st_strrchr(const char *str, int c) {
  int len_str = st_strlen(str);
  for (; len_str > 0; len_str--) {
    if (str[len_str] == c) {
      break;
    }
  }
  return (str[len_str] == c) ? (char *)str + len_str : st_NULL;
}

int st_strncmp(const char *str1, const char *str2, st_size_t n) {
  int res = 0;
  st_size_t i = 0;
  const char *pt_str1 = str1;
  const char *pt_str2 = str2;
  for (; (*pt_str1 != '\0' || *pt_str2 != '\0') && i < n;
       pt_str1++, pt_str2++, i++) {
    if ((*pt_str1) != (*pt_str2)) {
      res = (*pt_str1) - (*pt_str2);
      break;
    }
    if (*pt_str2 == '\0' || *pt_str1 == '\0') {
      res = (*pt_str1) - (*pt_str2);
      break;
    }
  }
  return res;
}

int st_strcmp(const char *str1, const char *str2) {
  int res = 0;
  for (; (*str1) != '\0' || (*str2) != '\0'; str1++, str2++) {
    if ((*str1) != (*str2)) {
      res = (*str1) - (*str2);
      break;
    }
  }
  return res;
}

void *st_memset(void *str, int c, st_size_t n) {
  unsigned char ch = (unsigned char)c;
  unsigned char *pt = str;
  st_size_t i = 0;
  for (; i < n; i++, pt++) {
    (*pt) = ch;
  }
  return str;
}

void *st_memmove(void *dest, const void *src, st_size_t n) {
  unsigned char *pto_str1 = dest;
  const unsigned char *pto_str2 = src;
  if (dest && src) {
    char temp[n];
    st_size_t i, j;
    for (i = 0; i < n; pto_str2++, i++) {
      temp[i] = (*pto_str2);
    }
    for (j = 0; j < n; pto_str1++, j++) {
      (*pto_str1) = temp[j];
    }
  }
  return dest;
}

void *st_memcpy(void *dest, const void *src, st_size_t n) {
  unsigned char *pto_str1 = dest;
  const unsigned char *pto_str2 = src;
  st_size_t i;
  for (i = 0; i < n; pto_str1++, pto_str2++, i++) {
    (*pto_str1) = (*pto_str2);
  }
  return dest;
}

int st_memcmp(const void *str1, const void *str2, st_size_t n) {
  int res = 0;
  const unsigned char *pto_str1 = str1;
  const unsigned char *pto_str2 = str2;

  while (n--) {
    if ((*pto_str1) != (*pto_str2)) {
      res = (*pto_str1) - (*pto_str2);
      break;
    }
    pto_str1++;
    pto_str2++;
  }

  return res;
}

void *st_memchr(const void *str, int c, st_size_t n) {
  unsigned int ch = (unsigned int)c;
  const char *pt = str;
  st_size_t i;
  for (i = 1; i < n && (*pt) != (char)ch; pt++, i++) {
  }
  if ((*pt) != (char)ch || n == 0) {
    pt = st_NULL;
  }
  return (char *)pt;
}

char *st_strchr(const char *str, int c) {
  const char *cursor_src = str;
  for (; (*cursor_src) != c && (*cursor_src) != '\0'; cursor_src++) {
  }
  if ((*cursor_src) != c) {
    cursor_src = st_NULL;
  }
  return (char *)cursor_src;
}

st_size_t st_strlen(const char *str) {
  st_size_t count = 0;
  const char *cursor = str;
  for (; (*cursor) != '\0'; cursor++) {
    count++;
  }
  return count;
}

char *st_strncat(char *dest, const char *src, st_size_t n) {
  int len = st_strlen(dest);
  const char *cursor_src = src;
  for (; (*cursor_src) != '\0' && n != 0; cursor_src++, n--) {
    *(dest + len) = (*cursor_src);
    len++;
  }
  return dest;
}

char *st_strcat(char *dest, const char *src) {
  int i;

  i = 0;
  while (*(dest + i) != 0) ++i;
  while (*src != 0) {
    *(dest + i) = *src;
    ++i;
    ++src;
  }
  *(dest + i) = 0;
  return (dest);
}

char *st_strcpy(char *dest, const char *src) {
  int i = 0;
  int len = st_strlen(src);
  for (i = 0; i < len; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

char *st_strncpy(char *dest, const char *src, st_size_t n) {
  st_size_t i = 0;
  while (*(src + i) != 0 && n != 0) {
    *(dest + i) = *(src + i);
    ++i;
    --n;
  }
  while (0 < n) {
    *(dest + i) = 0;
    ++i;
    --n;
  }
  return (dest);
}

st_size_t st_strcspn(const char *str1, const char *str2) {
  st_size_t count = 0;
  int flag = 1;
  for (int i = 0; str1[i]; i++) {
    for (int j = 0; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) {
      break;
    }
    count++;
  }
  return count;
}

char *st_strpbrk(const char *str1, const char *str2) {
  int flag = 0;
  const char *dest = str1;
  for (int i = 0; str1[i]; i++) {
    for (int j = 0; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        dest = dest + i;
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return (flag == 1) ? (char *)dest : st_NULL;
}

st_size_t st_strspn(const char *str1, const char *str2) {
  int count = 0, flag = 0;
  for (int i = 0; str1[i]; i++) {
    for (int j = 0; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        flag = 0;
        count++;
        break;
      }
      flag = 1;
    }
    if (flag == 1) {
      break;
    }
  }
  return count;
}

char *st_strstr(const char *haystack, const char *needle) {
  const char *dest;
  int temp = 0, j = 0, count = 0;
  int len = st_strlen(needle);
  for (int i = 0; haystack[i] != '\0'; i++) {
    if (haystack[i] != needle[j]) {
      continue;
    } else {
      count++;
      if (count == 1) {
        temp = i;
      }
      j++;
      continue;
    }
  }
  dest = haystack + temp;
  return (count == len) ? (char *)dest : st_NULL;
}

char *st_strtok(char *str, const char *delim) {
  static int next_null, tok, ind;
  static char *max_ptr, *addr;
  if (str) {
    tok = 1;
    ind = 0, next_null = 0;
    addr = str + st_strspn(str, delim);
    max_ptr = str + st_strlen(str);
  }
  char *res = st_NULL;
  if (!(addr >= max_ptr || next_null)) {
    int no_delim = 1;
    for (int i = 0; addr[i]; i++) {
      int step = st_strspn(addr + i, delim);
      if (step) {
        no_delim = 0;
        for (int j = i; j < i + step; j++) {
          addr[j] = '\0';
        }
        ind = step + i;
        break;
      }
    }
    if (tok && no_delim) {
      next_null = 1;
    }
    res = addr;
    addr += ind;
  }
  return res;
}

void *st_to_upper(const char *str) {
  char *dest = st_NULL;
  if (str) {
    dest = (char *)malloc((st_strlen(str) + 1) * sizeof(char));
    if (dest) {
      st_strcpy(dest, str);
      char *pt = dest;
      for (; *pt; pt++) {
        if (*pt >= 'a' && *pt <= 'z') {
          *pt -= 32;
        }
      }
    }
  }
  return dest;
}

void *st_to_lower(const char *str) {
  char *dest = st_NULL;
  if (str) {
    dest = (char *)malloc((st_strlen(str) + 1) * sizeof(char));
    st_strcpy(dest, str);
    char *pt = dest;
    for (; *pt; pt++) {
      if (*pt >= 'A' && *pt <= 'Z') {
        *pt += 32;
      }
    }
  }
  return dest;
}

void *st_insert(const char *src, const char *str, st_size_t start_index) {
  char *dest = st_NULL;
  if (src && str && st_strlen(src) >= start_index) {
    dest = calloc((st_strlen(src) + st_strlen(str) + 1) * sizeof(char),
                  sizeof(char));
    if (dest != st_NULL) {
      st_strncpy(dest, src, start_index);
      st_strcat(dest, str);
      st_strcat(dest, src + start_index);
      // *(dest + st_strlen(src) + st_strlen(str) + 1) = '\0';
    }
  }
  return dest;
}

void *st_trim(const char *src, const char *trim_chars) {
  char *new_str = st_NULL;
  if (src && trim_chars) {
    char *start = (char *)src;
    char *end = (char *)src + st_strlen(src);
    for (; *start && st_strchr(trim_chars, *start); start++) {
    }
    for (; end != start && st_strchr(trim_chars, *(end - 1)); end--) {
    }
    new_str = (char *)malloc((end - start + 1) * sizeof(char));
    if (new_str) {
      st_strncpy(new_str, start, end - start);
      *(new_str + (end - start)) = '\0';
    }
  }
  return (void *)new_str;
}
