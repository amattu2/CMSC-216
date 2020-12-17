#include <stdio.h>
#include <assert.h>
#include "forkfile.h"
#include "make-target.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 4 (secret04.c)
 *
 * Tests that do_action() is waiting for the action command to be performed
 * before returning.  The "seq" UNIX command has two command-line arguments,
 * which are numbers, and it just prints all the numbers between them,
 * inclusive.  (For illustration, try the command "seq 1 10" on Grace.)
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret04.forkfile");

  /* see Section 5.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  assert(make_target(forkfile, "target1") == 0);

  return 0;
}
