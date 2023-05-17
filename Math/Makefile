CC = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage
OS = $(shell uname)

ifeq ($(OS), Linux)
	FLAGS = -lcheck -pthread -lrt -lm -lsubunit 
else
	FLAGS = -lcheck
endif


all: create_tests clang test clean

test: st_math.a tests_st_math.a 
	$(CC) tests_st_math.c st_math.a -o test $(FLAGS)
	./test

gcov_report: st_math.a test
	rm -f *.g*
	$(CC) st*.c tests_st_math.c st_math.a $(FLAGS) $(GCOVFLAGS) st_math.a -o test
	./test
	lcov -t test -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

st_math.a: st_pow.o st_log.o st_abs.o st_fabs.o st_ceil.o st_floor.o st_sqrt.o st_exp.o st_acos.o st_asin.o st_atan.o st_sin.o st_cos.o st_tan.o st_factorial.o st_fmod.o 
	ar -rc st_math.a st_pow.o st_log.o st_abs.o st_fabs.o st_ceil.o st_floor.o st_sqrt.o st_exp.o st_acos.o st_asin.o st_atan.o st_sin.o st_cos.o st_tan.o st_factorial.o st_fmod.o 
	ranlib st_math.a
	rm -f *.o

st_pow.o:
	$(CC) -c st_pow.c

st_log.o:
	$(CC) -c st_log.c

st_factorial.o:
	$(CC) -c st_factorial.c 

st_tan.o:
	$(CC) -c st_tan.c 

st_cos.o:
	$(CC) -c st_cos.c 

st_sin.o:
	$(CC) -c st_sin.c 

st_atan.o:
	$(CC) -c st_atan.c 

st_asin.o:
	$(CC) -c st_asin.c 

st_acos.o:
	$(CC) -c st_acos.c 

st_fmod.o:
	$(CC) -c st_fmod.c 

st_exp.o:
	$(CC) -c st_exp.c

st_sqrt.o:
	$(CC) -c st_sqrt.c

st_floor.o:
	$(CC) -c st_floor.c

st_ceil.o:
	$(CC) -c st_ceil.c

st_fabs.o:
	$(CC) -c st_fabs.c

st_abs.o:
	$(CC) -c st_abs.c


tests_st_math.a: tests_st_math.o 
	ar -rc tests_st_math.a tests_st_math.o
	ranlib tests_st_math.a 
	rm -f *.o 

tests_st_math.o:
	$(CC) -c tests_st_math.c 


create_tests:
	checkmk clean_mode=1 asd.check > tests_st_math.c 

clean:
	rm -rf *.o *.a test report *.gcno *.gcda *.info

clang:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h
