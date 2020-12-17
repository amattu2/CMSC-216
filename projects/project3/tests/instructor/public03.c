#include <stdio.h>
#include <assert.h>
#include "machine.h"

#define UNUSED 0

/* CMSC 216, Fall 2020, Project #3
 * Public test 3 (public03.c)
 *
 * Tests calling encode_instruction() when the parameters are valid and they
 * represent a valid instruction.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Hardware_word instr;

  encode_instruction(ADD, R12, R17, R6, UNUSED, &instr);
  assert(instr == 0x1644c000);

  encode_instruction(NOT, R7, R6, UNUSED, UNUSED, &instr);
  assert(instr == 0x93980000);

  encode_instruction(MV, R8, R2, UNUSED, UNUSED, &instr);
  assert(instr == 0xb4080000);

  encode_instruction(LOAD, R6, UNUSED, UNUSED, 216, &instr);
  assert(instr == 0xd30000d8);

  encode_instruction(HALT, UNUSED, UNUSED, UNUSED, UNUSED, &instr);
  assert(instr == 0x00000000);

  printf("Your code caused all the assertions to work perfectly!\n");

  return 0;
}
