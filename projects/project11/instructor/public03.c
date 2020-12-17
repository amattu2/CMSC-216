#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 3 (public03.c)
 *
 * Tests the basic operation of lookup_target().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public03.forkfile");
  const char *targets[]= {"main.x", "functions.o", "main.o", "clean"};
  int i;

  for (i= 0; i < (int) (sizeof(targets) / sizeof(targets[0])); i++)
    assert(lookup_target(forkfile, targets[i]) == i);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
