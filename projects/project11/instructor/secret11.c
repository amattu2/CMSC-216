#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 11 (secret11.c)
 *
 * Tests read_forkfile() and print_action() with a forkfile that has a large
 * number of rules.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret11.forkfile");

  /* see Section 5.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* see if the last two rules were read and stored correctly */
  print_action(forkfile, 1999);
  printf("\n");

  print_action(forkfile, 2000);
  printf("\n\n");

  /* try to perform the actions of the last rules */
  do_action(forkfile, 1999);
  do_action(forkfile, 2000);

  return 0;
}
