CC = gcc -std=c11 -Wall -Wextra -Werror -g
OS = $(shell uname)
GCOVFLAGS = -L. --coverage

FILESo = st_decimal.o st_compare_bcd.o st_conversion.o st_output.o st_round.o st_ftbcd.o  st_compare.o  st_sub.o st_add.o st_div.o st_mul.o

ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	FLAGS = -lcheck -lm
endif

all: clean clang st_decimal.a create_tests test clean
	
gcov_report: create_tests st_decimal.a test
	rm -f *.g*
	$(CC) -w st*.c tests_st_decimal.c st_decimal.a $(FLAGS) $(GCOVFLAGS) st_decimal.a -o test
	./test
	lcov -t test -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info


create_tests:
	rm -rf asd.check
	@cat tests_files/headers.check >> asd.check				#headers
	@cat tests_files/compare/*.check >> asd.check 		    #compare
	@cat tests_files/*.check >> asd.check
	
	checkmk clean_mode=1 asd.check > tests_st_decimal.c
	rm -rf asd.check

test: st_decimal.a tests_st_decimal.o clang
	$(CC) tests_st_decimal.o st_decimal.a $(FLAGS) -o test
	./test

tests_st_decimal.o:
	$(CC) -w -c tests_st_decimal.c

st_decimal.a: $(FILESo)
	ar -rc st_decimal.a $(FILESo)
	ranlib st_decimal.a
	rm -f *.o


st_decimal.o:
	$(CC) -c st_decimal.c

st_conversion.o:
	$(CC) -c st_conversion.c

st_output.o:
	$(CC) -c st_output.c

st_round.o:
	$(CC) -c st_round.c

st_ftbcd.o:
	$(CC) -c st_ftbcd.c

st_sub.o:
	$(CC) -c st_sub.c

st_add.o:
	$(CC) -c st_add.c

st_compare.o:
	$(CC) -c st_compare.c

st_compare_bcd.o:
	$(CC) -c st_compare_bcd.c

st_div.o:
	$(CC) -c st_div.c

st_mul.o:
	$(CC) -c st_mul.c

clang:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h

git: clean
	git add . && git commit -m "add" && git push

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno test tests_st_decimal.c
	rm -rf .vscode/ a.out.dSYM/ report/ test.dSYM/ ../.vscode/ ../.DS_Store
