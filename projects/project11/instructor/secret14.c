#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 14 (secret14.c)
 *
 * Tests that do_action() correctly returns the exit status of the command
 * being run if it exited normally.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret14.forkfile");

  /* see Section 5.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  assert(do_action(forkfile, 1) == 0);  /* create executable program */
  assert(do_action(forkfile, 0) == 2);  /* now run it; its exit status is 2 */

  /* remove the executable program created */
  system("rm -f secret14-testprogram.x");

  printf("\nYet again, all assertions were successful!\n");

  return 0;
}
