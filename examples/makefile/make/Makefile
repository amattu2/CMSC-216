main.x: main.o fns.o
	gcc main.o fns.o -o main.x

fns.o: fns.c fns.h
	gcc -c fns.c

main.o: main.c fns.h
	gcc -c main.c
