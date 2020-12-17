#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* CMSC 216, Fall 2020, Project #1
 * Secret test 10 (secret10.c)
 *
 * Tests calling sopd(1, 1).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(sopd(1, 1) == 1);
  printf("\nTest passed!\n");

  return 0;
}
