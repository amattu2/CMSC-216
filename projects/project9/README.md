## Public Tests
- [x] public01.c
- [x] public02.c
- [x] public03.c
- [x] public04.c
- [ ] public05.c
- [ ] public06.c
- [ ] public07.c
- [ ] public08.c
- [ ] public09.c
- [ ] public10.c

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

`valgrind public10.x --leak-check=full --show-leak-kinds=all --track-origins=yes`
