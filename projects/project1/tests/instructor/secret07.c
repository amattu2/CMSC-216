#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* CMSC 216, Fall 2020, Project #1
 * Secret test 7 (secret07.c)
 *
 * Tests calling sopd(216, 0).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(sopd(216, 0) == 16);
  printf("\nTest passed!\n");

  return 0;
}
