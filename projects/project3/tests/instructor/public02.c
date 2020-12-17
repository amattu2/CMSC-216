#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2020, Project #3
 * Public test 2 (public02.c)
 *
 * Tests calling print_instruction() on some instructions that use other
 * fields.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  print_instruction(0xc30000d8);
  printf("\n");

  print_instruction(0x93980000);
  printf("\n");

  print_instruction(0xb4080000);
  printf("\n");

  print_instruction(0xd30000d8);
  printf("\n");

  print_instruction(0x00000000);
  printf("\n");

  return 0;
}
