#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* CMSC 216, Fall 2020, Project #1
 * Secret test 11 (secret11.c)
 *
 * Tests calling sopd(7, 6).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(sopd(7, 6) == 117650);
  printf("\nTest passed!\n");

  return 0;
}
