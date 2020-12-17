#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 6 (secret06.c)
 *
 * Tests calling both remove_front() and remove_back() on the same queue, to
 * remove elements from both ends.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int i, elt;

  init(&twosq);

  for (i= 13; i >= 1; i -= 2)
    add_front(&twosq, i);
  for (i= 14; i >= 2; i -= 2)
    add_back(&twosq, i);

  /* the queue now contains 1 3 5 7 9 13 14 12 10 8 6 4 2 */

  assert(num_elements(&twosq) == 14);

  for (i= 1; i <= 14; i++) {
    if (i % 2 == 1)
      remove_front(&twosq, &elt);
    else remove_back(&twosq, &elt);

    assert(elt == i);
  }

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
