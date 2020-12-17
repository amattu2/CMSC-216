#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 6 (secret06.c)
 *
 * Tests that each forkfile is independent and doesn't share any data with
 * other ones.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile1= read_forkfile("secret06a.forkfile"),
           forkfile2= read_forkfile("secret06b.forkfile");

  assert(lookup_target(forkfile1, "frog") == 0);
  assert(num_dependencies(forkfile1, 0) == 1);
  assert(num_dependencies(forkfile1, 1) == -1);
  print_action(forkfile1, 0);
  printf("\n\n");

  assert(lookup_target(forkfile2, "aardvark") == 0);
  assert(lookup_target(forkfile2, "zebra") == 1);
  assert(num_dependencies(forkfile2, 0) == 2);
  assert(num_dependencies(forkfile2, 1) == 2);
  assert(num_dependencies(forkfile2, 2) == -1);
  print_action(forkfile2, 0);
  printf("\n");
  print_action(forkfile2, 1);
  printf("\n\n");

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
