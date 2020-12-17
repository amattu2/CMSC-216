#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Public test 10 (public10.c)
 *
 * Tests passing NULL into init() and add_front().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  init(NULL);
  assert(add_front(NULL, 216) == 0);

  printf("This should print, and the program should not have crashed.\n");

  return 0;
}
