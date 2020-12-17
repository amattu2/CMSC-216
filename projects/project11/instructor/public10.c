#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* for sleep() */
#include <assert.h>
#include "forkfile.h"
#include "make-target.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 10 (public10.c)
 *
 * Tests calling make_target() using a forkfile similar to the one in the
 * project assignment, to build a program main.x, which is then executed.
 * When run, main.x just prints 216.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public10.forkfile");

  /* see Section 4.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* remove files if they already exist (from a previous execution); -f
     suppresses error messages even if some or all of the files don't exist */
  system("rm -f main.x main.o functions.o");

  assert(make_target(forkfile, "main.x") == 0);

  printf("Running main.x now, it prints ");
  system("./main.x");

  printf("\nYet again, all assertions were successful!\n");

  return 0;
}
