#include <stdio.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 9 (secret09.c)
 *
 * Tests whether a rule with no dependencies is printed correctly by
 * print_forkfile().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret09.forkfile");

  print_forkfile(forkfile);

  return 0;
}
