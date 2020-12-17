#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 1 (secret01.c)
 *
 * Tests calling both add_front() and add_back() on the same queue, to add
 * elements at both ends.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int i;

  init(&twosq);

  for (i= 1; i <= 12; i++)
    if (i % 2 == 0)
      add_front(&twosq, i);
    else add_back(&twosq, i);

  assert(num_elements(&twosq) == 12);

  print(&twosq);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
