#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2020, Project #3
 * Public test 1 (public01.c)
 *
 * Tests calling print_instruction() on some basic instructions.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  print_instruction(0x1644c000);
  printf("\n");

  print_instruction(0x3298c000);
  printf("\n");

  print_instruction(0x2894c000);
  printf("\n");

  print_instruction(0x85a4a000);
  printf("\n");

  print_instruction(0x74956000);
  printf("\n");

  return 0;
}
