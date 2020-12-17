#include <stdio.h>

/* This is used by the sixth public test.; */

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  int i= 216, j= -216;

  printf("%d\n", 123 / (i + j));  /* this will not end well */

  printf("Sadly, this is never going to be printed.\n");

  return 0;
}
