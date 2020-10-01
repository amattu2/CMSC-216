#include <stdio.h>

int y = 2;
int z = 1;

void g(int n);

void g(int n) {
	extern int x;
	x += n;
	printf("%d %d %d\n", x, y, z);
}
