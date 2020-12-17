#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 13 (secret13.c)
 *
 * Tests calling some of the functions with NULL character string arguments.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret13.forkfile");

  assert(lookup_target(forkfile, NULL) == -1);
  assert(exists(NULL) == 0);
  assert(is_older(NULL, NULL) == 0);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
