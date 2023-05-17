CC = gcc

CFLAGS = -Wall -Wextra -Werror 

all: clang st_cat

st_cat: st_cat.c
	$(CC) $(CFLAGS) st_cat.c -o st_cat

tests: st_cat
	cp ./st_cat tests/./st_cat
	bash tests/test_func_cat.sh

clang: st_cat.c
	clang-format -style=Google -i st_cat.c

gitpush: 
	git add Makefile st_cat.c
	git commit -m Makefile st_cat.c
	git push -u origin develop