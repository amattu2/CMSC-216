#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Public test 1 (public01.c)
 *
 * Tests calling num_elements() on an empty queue.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;

  init(&twosq);

  assert(num_elements(&twosq) == 0);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
