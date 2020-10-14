#
# Define make variables
#
GC = gcc
FLAGS = -ansi -pedantic-errors -Wall -Werror -Wshadow -fstack-protector-all

#
# Define an "all" option
#
all: main.x program1.x tester.x

#
# Define a "clean" option
#
clean: rm -f *.x *.o

#
# Define main.x operations
#
main.x: main.o fill-array.o compare-arrays.o
	$(GC) main.o fill-array.o compare-arrays.o -o main.x

main.o: main.c fill-array.h compare-arrays.h
	$(GC) -c main.c

fill-array.o: fill-array.c fill-array.h
	$(GC) -c fill-array.c

compare-arrays.o: compare-arrays.c compare-arrays.h
	$(GC) -c compare-arrays.c
