CC = gcc

CFLAGS = -Wall -Wextra -Werror 

all: clang s21_cat

s21_cat: s21_cat.c
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test: s21_cat
	cp ./s21_cat tests/./s21_cat
	bash tests/test_func_cat.sh

clang: s21_cat.c
	clang-format -style=Google -i s21_cat.c

gitpush: 
	git add Makefile s21_cat.c
	git commit -m Makefile s21_cat.c
	git push -u origin develop