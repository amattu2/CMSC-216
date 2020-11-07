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
