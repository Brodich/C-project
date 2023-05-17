#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 4096
struct Type_flags {
  int l;
  int n;
  int h;
  int c;
  int s;
  int e;
  int f;
  int i;
  int o;
  int v;
  int file_name;
  int error;
};

enum Bool { false, true };
//
// valgrind --leak-check=full
// v c l n h o
int main(int argc, char *argv[]) {
  int regflag = 0;
  int compare = 0;
  int caseRed = 0;
  int dot = false;
  regex_t regex;
  size_t caselen = 0;
  char *lineF = NULL;
  struct Type_flags flags = {false, false, false, false, false, false,
                             false, false, false, false, false, false};
  int rez = -1;
  int template = 0;
  char search_string[BUFFSIZE] = {0};

  while ((rez = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (rez) {
      case 'e': {
        if (optarg[0] == '.') {
          dot = true;
        }
        strcat(search_string, optarg);
        strcat(search_string, "|");
        flags.e = true;
        template = 1;
        break;
      };
      case 'n': {
        flags.n = true;
        break;
      };
      case 'i': {
        regflag = REG_ICASE;
        flags.i = true;
        break;
      };
      case 'l': {
        flags.l = true;
        // flags.c = false;
        break;
      };
      case 'h': {
        flags.h = true;
        break;
      };
      case 'c': {
        flags.c = true;
        break;
      };
      case 'o': {
        flags.o = true;
        break;
      };
      case 'f': {
        FILE *caseF;
        caseF = fopen(optarg, "r");
        while ((caseRed = getline(&lineF, &caselen, caseF)) != EOF) {
          if (lineF[(strlen(lineF) - 1)] == '\n') {
            lineF[(strlen(lineF) - 1)] = '\0';
          }
          if (lineF[1] != '\n') {
            strcat(search_string, lineF);
            strcat(search_string, "|");
          }
        }
        free(lineF);
        fclose(caseF);
        flags.f = true;
        template = 1;
        break;
      };
      case 'v': {
        flags.v = true;
        compare = REG_NOMATCH;
        break;
      };
    };
  };

  if (template == 1) {
    search_string[strlen(search_string) - 1] = 0;
  } else if (template == 0 && argc > 1) {
    strcat(search_string, argv[optind]);
    ++optind;
  }

  if (flags.v == true) {  // for Mac
    flags.o = false;
  }

  if ((argc - optind) > 1) {
    flags.file_name = true;
  }

  if (flags.h == true) {
    flags.file_name = false;
  }
  if (flags.l == true) {
    flags.h = false;
  }

  // printf("search str '%s'\n", search_string);

  FILE *fp = NULL;
  size_t len = 0;
  int str_count = 0;
  int success = -1;
  int over = 0;
  char *tmp_line = NULL;
  int rc = -1;
  int red = 0;
  int find_success = 0;
  size_t nmatch = 10;
  regmatch_t pmatch[10];

  if (flags.error == false) {
    if ((rc = regcomp(&regex, search_string, REG_EXTENDED | regflag)) != 0) {
      flags.error = true;
    }
    for (; optind < argc; optind++) {
      if ((fp = fopen(argv[optind], "r")) == NULL) {
        flags.error = true;

      } else {
        if (flags.c == true && flags.file_name == true) {
          printf("%s:", argv[optind]);
        }
        while (((red = getline(&tmp_line, &len, fp)) != EOF) && over == 0) {
          ++str_count;
          int one_str_count = true;
          char *cursor = tmp_line;
          int one_find_suc = false;
          if (flags.o == true) {
            while (
                ((success = regexec(&regex, cursor, nmatch, pmatch, 0)) == 0) &&
                cursor != NULL && over != 1) {
              if ((success == compare)) {
                if (one_find_suc == false) {
                  ++find_success;
                }
                if (flags.l == true) {
                  // printf("%s\n", argv[optind]);
                  over = 1;
                }
                if (flags.c == false && flags.l == false) {
                  if (flags.file_name == true && one_find_suc == false) {
                    printf("%s:", argv[optind]);
                    fflush(stdout);
                  }
                  if (flags.n == true && one_str_count == true) {
                    if ((flags.n == true) && (flags.l == false) &&
                        (flags.c == false)) {
                      printf("%d:", str_count);
                      fflush(stdout);
                    }
                  }
                  for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
                    printf("%c", cursor[i]);
                    fflush(stdout);
                  }
                  printf("\n");
                }
                one_find_suc++;
              }
              cursor += pmatch[0].rm_eo;
              one_str_count = false;
            }
            one_find_suc = false;
          } else {
            success = regexec(&regex, tmp_line, 0, NULL,
                              0);  // возвращает 0 в случае нахождения
          }
          if ((success == compare) && flags.o == false && over == 0) {
            ++find_success;
            if (flags.l == true) {
              over = 1;
            }
            if (flags.file_name == true && flags.l == false &&
                flags.c == false && flags.h == false) {
              printf("%s:", argv[optind]);
              fflush(stdout);
            }

            if ((flags.n == true) && (flags.l == false) && (flags.c == false)) {
              printf("%d:", str_count);
              fflush(stdout);
            }
            if (flags.l == false && flags.c == false) {
              if ((tmp_line[strlen(tmp_line) - 1]) == '\n') {
                tmp_line[strlen(tmp_line) - 1] = 0;
              }
              if (dot == true && tmp_line[1] == '\0') {
              } else {
                printf("%s", tmp_line);

                printf("\n");
              }
            }
          }
        }
        if (flags.c == true) {
          printf("%d\n", find_success);
        }
        if (flags.o == true && flags.l == true && find_success != 0) {
          printf("%s\n", argv[optind]);
        }
        if (((flags.l == true)) && (flags.h == false) && (success == compare) &&
            (find_success != 0) && flags.o == false) {
          printf("%s\n", argv[optind]);
        }

        str_count = 0;
        over = false;
        fclose(fp);
      }
      find_success = 0;
    }
  }
  if (tmp_line != NULL) {
    free(tmp_line);
  }
  regfree(&regex);
  return 0;
}
