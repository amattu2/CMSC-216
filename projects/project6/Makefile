#
# * CMSC 216 (Fall 2020)
# * Section: 0303 (M/W 8am)
# * University ID: -
# * Directory ID: amattu
# *
# * Author: Alec M.
# * Date: Sept 14th, 2020
# *
# * I pledge on my honor that I have not given or received
# * any unauthorized assistance on this assignment.
#

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
# Define target operations
#
main.x: main.o fill-array.o compare-arrays.o
	$(GC) main.o fill-array.o compare-arrays.o -o main.x

program1.x: program1.o compare-arrays.o
	$(GC) program1.o compare-arrays.o -o program1.x

tester.x: tester.o fill-array.o incr-array.o sum-array.o
	$(GC) tester.o fill-array.o incr-array.o sum-array.o -o tester.x

#
# Define *.o operations
#
main.o: main.c fill-array.h compare-arrays.h
	$(GC) $(FLAGS) -c main.c

program1.o: program1.c compare-arrays.h
	$(GC) $(FLAGS) -c program1.c

tester.o: tester.c fill-array.h incr-array.h sum-array.h
	$(GC) $(FLAGS) -c tester.c

fill-array.o: fill-array.c fill-array.h
	$(GC) $(FLAGS) -c fill-array.c

compare-arrays.o: compare-arrays.c compare-arrays.h
	$(GC) $(FLAGS) -c compare-arrays.c

incr-array.o: incr-array.c incr-array.h
	$(GC) $(FLAGS) -c incr-array.c

sum-array.o: sum-array.c sum-array.h
	$(GC) $(FLAGS) -c sum-array.c

#
# Define a "clean" option
#
clean:
	rm -f *.x *.o
