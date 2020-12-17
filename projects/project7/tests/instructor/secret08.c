#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 8 (secret08.c)
 *
 * Tests calling remove_front() to remove all elements from a queue, and
 * then verifies that new elements can be added to the front.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int i, elt;

  init(&twosq);

  /* add 100 elements */
  for (i= 1; i <= 100; i++)
    add_front(&twosq, i);

  assert(num_elements(&twosq) == 100);

  /* remove them all */
  for (i= 1; i <= 100; i++)
    remove_back(&twosq, &elt);

  /* add 10 more to the back */
  for (i= 10; i >= 1; i--)
    add_front(&twosq, i);

  /* check them */
  assert(num_elements(&twosq) == 10);

  for (i= 1; i <= 10; i++) {
    remove_front(&twosq, &elt);
    assert(elt == i);
  }

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
