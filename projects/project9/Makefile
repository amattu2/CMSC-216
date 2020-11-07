#
# * CMSC 216 (Fall 2020)
# * Section: 0303 (M/W 8am)
# * University ID: 117568813
# * Directory ID: amattu
# *
# * Author: Alec M.
# * Date: Nov 7th, 2020
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
all: public01.x public02.x public03.x public04.x public05.x public06.x \
	public07.x public08.x public09.x public10.x

#
# Define target operations
#
wstring-graph.x: wstring-graph.o
	$(GC) wstring-graph.o -o wstring-graph.x

public01.x: graph-utils.o wstring-graph.o public01.o
	$(GC) graph-utils.o wstring-graph.o public01.o -o public01.x

public02.x: wstring-graph.o public02.o
	$(GC) wstring-graph.o public02.o -o public02.x

public03.x: graph-utils.o wstring-graph.o public03.o
	$(GC) graph-utils.o wstring-graph.o public03.o -o public03.x

public04.x: wstring-graph.o graph-utils.o public04.o
	$(GC) graph-utils.o wstring-graph.o public04.o -o public04.x

public05.x: graph-utils.o wstring-graph.o public05.o
	$(GC) graph-utils.o wstring-graph.o public05.o -o public05.x

public06.x: graph-utils.o wstring-graph.o public06.o
	$(GC) graph-utils.o wstring-graph.o public06.o -o public06.x

public07.x: graph-utils.o wstring-graph.o public07.o
	$(GC) graph-utils.o wstring-graph.o public07.o -o public07.x

public08.x: graph-utils.o wstring-graph.o public08.o
	$(GC) graph-utils.o wstring-graph.o public08.o -o public08.x

public09.x: graph-utils.o wstring-graph.o public09.o
	$(GC) graph-utils.o wstring-graph.o public09.o -o public09.x

public10.x: graph-utils.o wstring-graph.o public10.o
	$(GC) graph-utils.o wstring-graph.o public10.o -o public10.x

#
# Define object operations
#
wstring-graph.o: wstring-graph.c wstring-graph.h
	$(GC) $(FLAGS) -c wstring-graph.c

public01.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public01.c
	$(GC) $(FLAGS) -c public01.c

public02.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h public02.c
	$(GC) $(FLAGS) -c public02.c

public03.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public03.c
	$(GC) $(FLAGS) -c public03.c

public04.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public04.c
	$(GC) $(FLAGS) -c public04.c

public05.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public05.c
	$(GC) $(FLAGS) -c public05.c

public06.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public06.c
	$(GC) $(FLAGS) -c public06.c

public07.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public07.c
	$(GC) $(FLAGS) -c public07.c

public08.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public08.c
	$(GC) $(FLAGS) -c public08.c

public09.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public09.c
	$(GC) $(FLAGS) -c public09.c

public10.o: wstring-graph.c wstring-graph.h \
		wstring-graph-datastructure.h graph-utils.h graph-utils.o public10.c
	$(GC) $(FLAGS) -c public10.c

#
# Define a "clean" option
#
clean:
	rm -f *.x public**.o wstring-graph.o
