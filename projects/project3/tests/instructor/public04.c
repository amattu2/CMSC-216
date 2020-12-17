#include <stdio.h>
#include <assert.h>
#include "machine.h"

#define UNUSED 0

/* CMSC 216, Fall 2020, Project #3
 * Public test 4 (public04.c)
 *
 * Tests calling encode_instruction() when the parameters represent
 * instructions with invalid registers.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Hardware_word instr;

  assert(encode_instruction(ADD, 100, R17, R6, UNUSED, &instr) == 0);
  assert(encode_instruction(ADD, R12, 100, R6, UNUSED, &instr) == 0);
  assert(encode_instruction(ADD, R12, R17, 100, UNUSED, &instr) == 0);

  printf("Your code caused all the assertions to work perfectly!\n");

  return 0;
}
