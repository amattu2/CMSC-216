#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 6 (public06.c)
 *
 * Tests calling do_action() when the command to be executed doesn't exit
 * normally.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public06.forkfile");

  /* compile a program that we know isn't going to exit normally */
  system("gcc public06-testprogram.c -o public06-testprogram.x");

  assert(do_action(forkfile, 0) == -1);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
