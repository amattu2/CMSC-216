#include <stdio.h>

int number= 0;
int exponent= 0;
int result= 0;

static int power(int base, int expon);
static int sopd(int num, int n);

int power(int base, int expon) {
  int i, ans;

  ans= 1;

  for (i= 1; i <= expon; i++)
    ans *= base;

  return ans;
}

int sopd(int num, int n) {
  int i, ans;

  ans= -1;

  if (num >= 1 && n >= 0) {
    ans= 0;

    for (i= 1; i <= num; i++)
      if (num % i == 0)  /* i is a divisor */
        ans += power(i, n);
  }

  return ans;
}

int main(void) {
  scanf("%d %d", &number, &exponent);

  result= sopd(number, exponent);

  printf("%d\n", result);

  return 0;
}
