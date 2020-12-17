#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 12 (secret12.c)
 *
 * Tests read_forkfile() and print_action() with a forkfile that has a
 * very long dependency list, and a long command.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret12.forkfile");

  /* see Section 5.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* see if the rules were read correctly */
  print_action(forkfile, 0);
  printf("\n\n");

  print_action(forkfile, 1);
  printf("\n\n");

  print_action(forkfile, 2);
  printf("\n\n");

  /* try to perform the very long action */
  do_action(forkfile, 1);

  return 0;
}
