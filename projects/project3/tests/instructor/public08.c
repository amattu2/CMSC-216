#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2020, Project #3
 * Public test 8 (public08.c)
 *
 * Tests calling disassemble() with an invalid value for memory_size.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MEMORY_WORDS 4000
#define NUM_INSTRS 8

int main() {
  Hardware_word program[MEMORY_WORDS]= {0x2894c000, 0x74956000, 0x3298c000,
                                        0xc30000d8, 0xd30000d8, 0xb4080000,
                                        0x93980000, 0x00000000, 0x02020202,
                                        0x00200020, 0x02000200, 0x10001000};

  disassemble(program, MEMORY_WORDS, NUM_INSTRS);

  printf("If anything prints other than this the test will fail.\n");

  return 0;
}
