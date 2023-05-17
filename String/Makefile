CC = gcc -std=c11 -g -Wall -Werror -Wextra
GCOVFLAGS = -L. --coverage
OS = $(shell uname)

ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit 
else
	FLAGS = -lcheck
endif


all: clean create_tests clang test clean

mytest: 
	gcc -Wall -Wextra st_sscanf.c st_string.c myTest.c


create_tests:
	rm -rf asd.check
	@cat asd_functions.check >> asd.check
	@cat asd_sprintf.check >> asd.check
	@cat asd_sscanf.check >> asd.check
	checkmk clean_mode=1 asd.check > tests_st_string.c
	rm -rf asd.check

gcov_report: st_string.a test
	rm -f *.g*
	$(CC) -w st*.c tests_st_string.c st_string.a $(FLAGS) $(GCOVFLAGS) st_string.a -o test
	./test
	lcov -t test -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info


test: st_string.a tests_st_string.o clang
	$(CC) tests_st_string.o st_string.a $(FLAGS) -o test
	./test

st_string.a: st_string.o st_strerror.o st_sprintf.o st_specifier.o st_sscanf.o
	ar -rc st_string.a st_string.o st_strerror.o st_sprintf.o st_specifier.o st_sscanf.o
	ranlib st_string.a
	rm -f *.o

st_string.o:
	$(CC) -c st_string.c

st_strerror.o:
	$(CC) -c st_strerror.c

st_specifier.o:
	$(CC) -c st_specifier.c

st_sprintf.o:
	$(CC) -c st_sprintf.c

st_sscanf.o:
	$(CC) -c st_sscanf.c
 
tests_st_string.o:
	$(CC) -w -c tests_st_string.c

clean:
	rm -rf test *.o *.a *.gcno *.gcda report *.info st_test

clang:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h

git : clean
	git add . && git commit -m "add" && git push

