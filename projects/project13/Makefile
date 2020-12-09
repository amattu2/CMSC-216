# Project #13 public tests makefile

# (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
# not to provide it to anyone else.

CC = gcc
CFLAGS= -g -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -Wshadow

# create all public tests

all: public1.x public2.x public3.x public4.x public5.x

# compile the public tests (note they are standalone executables comprising
# only one source file); but we force the sum-files programs to be compiled
# as well

public1.x: public1.c sum-files.x sum-files-threaded.x
	$(CC) public1.c -o public1.x

public2.x: public2.c sum-files.x sum-files-threaded.x
	$(CC) public2.c -o public2.x

public3.x: public3.c sum-files.x sum-files-threaded.x
	$(CC) public3.c -o public3.x

public4.x: public4.c sum-files.x sum-files-threaded.x
	$(CC) public4.c -o public4.x

public5.x: public5.c sum-files.x sum-files-threaded.x
	$(CC) public5.c -o public5.x

# create the sequential and threaded programs, which are also both
# standalone executables comprising only one source file); we just use the
# gcc -lpthread option here as opposed to adding it in CFLAGS because the
# public tests themselves (compiled above) do not require it

sum-files.x: sum-files.c
	$(CC) $(CFLAGS) -lpthread sum-files.c -o sum-files.x

sum-files-threaded.x: sum-files-threaded.c
	$(CC) $(CFLAGS) -lpthread sum-files-threaded.c -o sum-files-threaded.x

# remove data files that mnay have been retained using -DKEEP, as part of
# the clean target

clean:
	rm -f public*.o public*.x sum-files.x sum-files-threaded.x \
              public*.inputdata
