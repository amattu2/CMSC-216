#include <stdio.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 1 (public01.c)
 *
 * Tests the basic operation of read_forkfile() and print_forkfile() with a
 * single-rule forkfile.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public01.forkfile");

  print_forkfile(forkfile);

  return 0;
}
