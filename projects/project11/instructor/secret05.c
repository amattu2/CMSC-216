#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 5 (secret05.c)
 *
 * Tests calling some of the functions on nonexistent target names or rule
 * numbers in a forkfile.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret05.forkfile");

  assert(lookup_target(forkfile, "nonexistent-target-name") == -1);
  assert(num_dependencies(forkfile, 4) == -1);
  assert(get_dependency(forkfile, 0, 2) == NULL);
  assert(get_dependency(forkfile, 1, 2) == NULL);
  assert(get_dependency(forkfile, 2, 2) == NULL);
  assert(get_dependency(forkfile, 3, 0) == NULL);
  assert(get_dependency(forkfile, 4, 0) == NULL);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
