#include <stdio.h>
#include <unistd.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 5 (public05.c)
 *
 * Tests the basic operation of do_action().  (The test waits for a second
 * between performing actions.)
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public05.forkfile");

  do_action(forkfile, 0);
  printf("\n");
  sleep(1);

  do_action(forkfile, 1);
  printf("\n");
  sleep(1);

  do_action(forkfile, 2);
  printf("\n");
  sleep(1);

  do_action(forkfile, 3);

  return 0;
}
