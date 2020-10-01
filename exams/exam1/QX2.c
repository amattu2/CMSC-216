#include <stdio.h>

int x = 1;
static int y = 2;

static void f(int n);
void g(int n);

int main()
{
    int x = 3;
    extern int z;

    f(x);
    g(x);

    f(x);
    g(x);

    printf("%d %d %d\n", x, y, z);

    return 0;
}

void f(int n) {
    static int z = 4;
    x += n;
    y += n;
    z += n;

    printf("%d %d %d\n", x, y, z);
}
