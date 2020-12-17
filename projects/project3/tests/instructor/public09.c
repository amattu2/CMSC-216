#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2020, Project #3
 * Public test 9 (public09.c)
 *
 * Tests calling disassemble() on a program that contains an invalid
 * instruction.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MEMORY_WORDS 8
#define NUM_INSTRS 8

int main() {
  Hardware_word program[MEMORY_WORDS]= {0x2894c000, 0x74956000, 0x3298c000,
                                        0xc30000d8, 0xffffffff, 0xb4080000,
                                        0x93980000, 0x00000000};

  disassemble(program, MEMORY_WORDS, NUM_INSTRS);

  return 0;
}
