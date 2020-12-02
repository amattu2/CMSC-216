#include <stdio.h>

int number= 0;
int exponent= 0;
int result= 0;

static int sopd(int num, int n, int i);

int power(int base, int expon) {
  int i, ans;

  ans= 1;

  for (i= 1; i <= expon; i++)
    ans *= base;

  return ans;
}

int sopd(int num, int n, int i) {
  int ans;

  ans= 0;

  if (i <= num) {
    if (num % i == 0)
      ans= power(i, n);

    ans += sopd(num, n, i + 1);
  }

  return ans;
}

int main(void) {
  result= -1;

  scanf("%d %d", &number, &exponent);

  if (number >= 1 && exponent >= 0)
    result= sopd(number, exponent, 1);

  printf("%d\n", result);

  return 0;
}
