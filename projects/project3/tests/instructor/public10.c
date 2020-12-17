#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Fall 2020, Project #3
 * Public test 10 (public10.c)
 *
 * Tests calling compare_instructions() on two instructions whose fields are
 * all identical, and on two whose fields are different.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(compare_instructions(0x3298c000, 0x3298c000) == 1);
  assert(compare_instructions(0x3298c000, 0x3398c000) == 0);

  printf("Your code caused all the assertions to work perfectly!\n");

  return 0;
}
