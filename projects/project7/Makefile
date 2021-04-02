#
# * CMSC 216 (Fall 2020)
# * Section: 0303 (M/W 8am)
# * University ID: -
# * Directory ID: amattu
# *
# * Author: Alec M.
# * Date: Oct 20th, 2020
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
# Define main target options
#
all: public01.x public02.x public03.x public04.x public05.x public06.x public07.x public08.x public09.x public10.x
student: student01.x student02.x student03.x student04.x student05.x student06.x student07.x

#
# Define target operations
#
two-sided-queue.x: two-sided-queue.o
	$(GC) two-sided-queue.o -o two-sided-queue.x

public01.x: two-sided-queue.o public01.o
	$(GC) two-sided-queue.o public01.o -o public01.x

public02.x: two-sided-queue.o public02.o
	$(GC) two-sided-queue.o public02.o -o public02.x

public03.x: two-sided-queue.o public03.o
	$(GC) two-sided-queue.o public03.o -o public03.x

public04.x: two-sided-queue.o public04.o
	$(GC) two-sided-queue.o public04.o -o public04.x

public05.x: two-sided-queue.o public05.o
	$(GC) two-sided-queue.o public05.o -o public05.x

public06.x: two-sided-queue.o public06.o
	$(GC) two-sided-queue.o public06.o -o public06.x

public07.x: two-sided-queue.o public07.o
	$(GC) two-sided-queue.o public07.o -o public07.x

public08.x: two-sided-queue.o public08.o
	$(GC) two-sided-queue.o public08.o -o public08.x

public09.x: two-sided-queue.o public09.o
	$(GC) two-sided-queue.o public09.o -o public09.x

public10.x: two-sided-queue.o public10.o
	$(GC) two-sided-queue.o public10.o -o public10.x

student01.x: two-sided-queue.o student01.o
	$(GC) two-sided-queue.o student01.o -o student01.x

student02.x: two-sided-queue.o student02.o
	$(GC) two-sided-queue.o student02.o -o student02.x

student03.x: two-sided-queue.o student03.o
	$(GC) two-sided-queue.o student03.o -o student03.x

student04.x: two-sided-queue.o student04.o
	$(GC) two-sided-queue.o student04.o -o student04.x

student05.x: two-sided-queue.o student05.o
	$(GC) two-sided-queue.o student05.o -o student05.x

student06.x: two-sided-queue.o student06.o
	$(GC) two-sided-queue.o student06.o -o student06.x

student07.x: two-sided-queue.o student07.o
	$(GC) two-sided-queue.o student07.o -o student07.x

#
# Define object operations
#
two-sided-queue.o: two-sided-queue.c two-sided-queue.h
	$(GC) $(FLAGS) -c two-sided-queue.c

public01.o: two-sided-queue.c two-sided-queue.h public01.c
	$(GC) $(FLAGS) -c public01.c

public02.o: two-sided-queue.c two-sided-queue.h public02.c
	$(GC) $(FLAGS) -c public02.c

public03.o: two-sided-queue.c two-sided-queue.h public03.c
	$(GC) $(FLAGS) -c public03.c

public04.o: two-sided-queue.c two-sided-queue.h public04.c
	$(GC) $(FLAGS) -c public04.c

public05.o: two-sided-queue.c two-sided-queue.h public05.c
	$(GC) $(FLAGS) -c public05.c

public06.o: two-sided-queue.c two-sided-queue.h public06.c
	$(GC) $(FLAGS) -c public06.c

public07.o: two-sided-queue.c two-sided-queue.h public07.c
	$(GC) $(FLAGS) -c public07.c

public08.o: two-sided-queue.c two-sided-queue.h public08.c
	$(GC) $(FLAGS) -c public08.c

public09.o: two-sided-queue.c two-sided-queue.h public09.c
	$(GC) $(FLAGS) -c public09.c

public10.o: two-sided-queue.c two-sided-queue.h public10.c
	$(GC) $(FLAGS) -c public10.c

student01.o: two-sided-queue.c two-sided-queue.h student01.c
	$(GC) $(FLAGS) -c student01.c

student02.o: two-sided-queue.c two-sided-queue.h student02.c
	$(GC) $(FLAGS) -c student02.c

student03.o: two-sided-queue.c two-sided-queue.h student03.c
	$(GC) $(FLAGS) -c student03.c

student04.o: two-sided-queue.c two-sided-queue.h student04.c
	$(GC) $(FLAGS) -c student04.c

student05.o: two-sided-queue.c two-sided-queue.h student05.c
	$(GC) $(FLAGS) -c student05.c

student06.o: two-sided-queue.c two-sided-queue.h student06.c
	$(GC) $(FLAGS) -c student06.c

student07.o: two-sided-queue.c two-sided-queue.h student07.c
	$(GC) $(FLAGS) -c student07.c

#
# Define a "clean" option
#
clean:
	rm -f *.x *.o
