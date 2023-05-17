CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: clang st_grep

st_grep: st_grep.c
	$(CC) $(CFLAGS) st_grep.c -o st_grep

tests: st_grep
	cp ./st_grep tests/./st_grep
	bash tests/test_func_grep.sh

clang: st_grep.c
	clang-format -style=Google -i st_grep.c
	
gitpush: 
	git add Makefile st_grep.c
	git commit -m Makefile st_grep.c
	git push -u origin develop