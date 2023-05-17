#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// for linux
struct Type_flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int error;
};

void mygetopt(int *argc, char **argv[], struct Type_flags *flags) {
  for (int count = 1; count < (*argc); count++) {
    if ((*argv)[count][0] == '-') {
      if ((*argv)[count][1] == '-') {
        if (strcmp((*argv)[count], "--number-nonblank") == 0) {
          flags->b = 1;
        } else if (strcmp((*argv)[count], "--number") == 0) {
          flags->n = 1;
        } else if (strcmp((*argv)[count], "--squeeze-blank") == 0) {
          flags->s = 1;
        } else {
          flags->error = 1;
        }
      } else if ((*argv)[count][1] == 'e') {
        flags->e = 1;
      } else if ((*argv)[count][1] == 's') {
        flags->s = 1;
      } else if ((*argv)[count][1] == 't') {
        flags->t = 1;
      } else if ((*argv)[count][1] == 'n') {
        if (flags->b != 1) {
          flags->n = 1;
        } else {
          flags->n = 0;
        }
      } else if ((*argv)[count][1] == 'b') {
        flags->b = 1;
        flags->n = 0;
      } else if ((*argv)[count][1] == 'v') {
        flags->v = 1;
      } else {
        flags->error = 1;
      }
      memset((*argv)[count], '\0', strlen((*argv)[count]));
    }
  }
}

int main(int argc, char *argv[]) {
  struct Type_flags flags = {0, 0, 0, 0, 0, 0, 0};
  mygetopt(&argc, &argv, &flags);

  FILE *fp;
  int CrutchS = 0, CrutchTE = 0;
  int CrutchB = 0;
  int NumberLine = 1;
  char PrintChar, FutChar;
  for (int count = 1; count < argc; count++) {
    if (argv[count][0] != '\0' && flags.error == 0) {
      if ((fp = fopen(argv[count], "r")) == NULL) {
        flags.error = 1;
      }
      if (flags.error == 0) {
        PrintChar = fgetc(fp);
        FutChar = '\0';
      }
      if (PrintChar != EOF && flags.error == 0) {
        if ((flags.n) && (!flags.b)) {
          printf("%6d\t", NumberLine);
          ++NumberLine;
        }
        if (flags.b && (PrintChar != '\n')) {
          printf("%6d\t", NumberLine);
          ++NumberLine;
        }

        while ((FutChar = getc(fp)) != EOF) {
          if (flags.s) {
            if ((PrintChar == '\n') && ((FutChar) == '\n')) {
              while (FutChar == '\n') {
                FutChar = getc(fp);
              }
              if (CrutchS != 0) {
                if (flags.e) {
                  printf("$");
                }
                printf("\n");

                if ((flags.n) && (!flags.b) && (PrintChar == '\n')) {
                  printf("%6d\t", NumberLine);
                  ++NumberLine;
                }
              }
            }
          }

          CrutchTE = 0;
          if (flags.e || flags.t || flags.v) {
            if ((PrintChar <= 31 && PrintChar >= 0) || (PrintChar >= 127)) {
              if (PrintChar >= 127) {
                printf("^%c", PrintChar - 64);
                CrutchTE = 2;
              } else if (PrintChar != '\n' && PrintChar != '\t') {
                printf("^%c", PrintChar + 64);
                CrutchTE = 2;
              }
            }
          }
          if (flags.t && PrintChar == '\t') {
            printf("^%c", PrintChar + 64);
            CrutchTE = 2;
          }
          if (flags.e && PrintChar == '\n') {
            printf("$");
          }
          if (CrutchTE != 2) {
            printf("%c", PrintChar);
          }

          if (flags.b && FutChar != '\n' && FutChar != EOF &&
              PrintChar == '\n') {
            printf("%6d\t", NumberLine);
            ++NumberLine;
            --CrutchB;
          }
          if (flags.n && PrintChar == '\n' && FutChar != EOF) {
            printf("%6d\t", NumberLine);
            ++NumberLine;
          }

          CrutchS = 1;
          PrintChar = FutChar;
        }
        if (PrintChar != EOF) {
          CrutchTE = 0;
          if (flags.e || flags.t || flags.v) {
            if ((PrintChar <= 31 && PrintChar >= 0) || (PrintChar >= 127)) {
              if (PrintChar >= 127) {
                printf("^%c", PrintChar - 64);
                CrutchTE = 2;
              } else if (PrintChar != '\n' && PrintChar != '\t') {
                printf("^%c", PrintChar + 64);
                CrutchTE = 2;
              }
            }
          }
          if (flags.t && PrintChar == '\t') {
            printf("^%c", PrintChar + 64);
            CrutchTE = 2;
          }
          if (flags.e && PrintChar == '\n') {
            printf("$");
          }
          if (CrutchTE != 2) {
            printf("%c", PrintChar);
          }
        }
      }
      if (flags.error == 0) {
        fclose(fp);
      }
      NumberLine = 1;
    }
  }

  if (flags.error == 1) {
    printf("Error 404: banana not defined\n");
  }
  return 0;
}