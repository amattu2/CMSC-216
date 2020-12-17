#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Public test 8 (public08.c)
 *
 * Tests calling remove_back() on an empty queue.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int n= 216;

  init(&twosq);

  assert(remove_back(&twosq, &n) == 0);
  assert(n == 216);  /* didn't change */

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
