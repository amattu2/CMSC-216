#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 7 (secret07.c)
 *
 * Tests calling lookup_target() with target_name being NULL.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret17.forkfile");

  assert(lookup_target(forkfile, NULL) == -1);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
