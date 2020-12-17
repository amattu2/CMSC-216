#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* CMSC 216, Fall 2020, Project #1
 * Secret test 9 (secret09.c)
 *
 * Tests calling sopd(0, 0).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(sopd(0, 0) == -1);
  printf("\nTest passed!\n");

  return 0;
}
