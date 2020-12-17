#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 8 (secret08.c)
 *
 * Tests calling some of the functions on a forkfile that has no rules.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret08.forkfile");

  assert(lookup_target(forkfile, "nonexistent-target") == -1);
  assert(num_dependencies(forkfile, 0) == -1);
  assert(num_dependencies(forkfile, 1) == -1);
  assert(get_dependency(forkfile, 0, 0) == NULL);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
