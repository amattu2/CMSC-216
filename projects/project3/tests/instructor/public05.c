#include <stdio.h>
#include <assert.h>
#include "machine.h"

#define UNUSED 0

/* CMSC 216, Fall 2020, Project #3
 * Public test 5 (public05.c)
 *
 * Tests calling encode_instruction() when the parameters are invalid
 * because hw_word is NULL.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  assert(encode_instruction(ADD, R12, R17, R6, UNUSED, NULL) == 0);

  printf("Your code caused the assertion to work perfectly!\n");

  return 0;
}
