## Todo
#### Styling, Structure, Etc
- [x] Check 80-Char line length
- [-] Remove excess brackets `{}`

#### Test makefile
- [x] Independent public01.x-public10.x
- [x] Make clean
- [x] Make all
- [x] Make

#### Project 8 Public Tests
- [x] public01.c
- [x] public02.c
- [x] public03.c
- [x] public04.c
- [x] public05.c
- [x] public06.c
- [x] public07.c
- [x] public08.c
- [x] public09.c
- [x] public10.c

#### Project 8 Private Tests
- [x] private01.c
- [x] private02.c
- [x] private03.c
- [x] private04.c
- [x] private05.c
- [x] private06.c
- [x] private07.c
- [x] private08.c
- [x] private09.c
- [x] private10.c

#### Project 9 Public Tests
- [x] public01.c
- [x] public02.c
- [x] public03.c
- [x] public04.c
- [x] public05.c
- [x] public06.c
- [x] public07.c
- [x] public08.c
- [x] public09.c
- [x] public10.c

## Notes
#### To compile with graph-utils.o
Eg. public01
```
gcc -c public01.c
gcc -c wstring-graph.c
gcc wstring-graph.o graph-utils.o public01.o
gcc wstring-graph.o graph-utils.o public01.o -o public01.x
gcc wstring-graph.o graph-utils.o public01.o -o public01.x -no-pie
./public01.x
```

#### Debugging with Valgrind
https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks

Eg. public10
`gcc wstring-graph.h wstring-graph.c graph-utils.h graph-utils.o public10.c -o public10.x -ggdb3 -g -D ENABLE_VALGRIND`

and

`valgrind --track-origins=yes --leak-check=full ./public05.x`
