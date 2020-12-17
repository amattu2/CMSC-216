#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* CMSC 216, Fall 2020, Project #1
 * Secret test 6 (secret06.c)
 *
 * Tests calling has366() on a negative year.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(has366(-1976) == -1);
  printf("\nTest passed!\n");

  return 0;
}
