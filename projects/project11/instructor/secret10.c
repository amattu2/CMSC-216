#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 10 (secret10.c)
 *
 * Tests calling print_action() on nonexistent rule numbers in a forkfile.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret10.forkfile");

  /* these should not print anything, and they should definitely not
     crash */
  print_action(forkfile, 5);
  print_action(forkfile, -1);

  printf("If this is the only thing printed the test was successful!\n");

  return 0;
}
