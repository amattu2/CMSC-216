#include <stdio.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Public test 2 (public02.c)
 *
 * Tests calling print() on an empty queue.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;

  init(&twosq);

  printf("About to print an empty queue.\n");
  print(&twosq);
  printf("Finished printing an empty queue.\n");

  return 0;
}
