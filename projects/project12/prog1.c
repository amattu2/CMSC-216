#include <stdio.h>

int base= 0;
int exponent= 0;
int i= 0;
int ans= 0;

int main(void) {
  ans= 1;

  scanf("%d %d", &base, &exponent);

  for (i= 1; i <= exponent; i++)
    ans *= base;

  printf("%d\n", ans);

  return 0;
}
