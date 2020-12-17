#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 10 (secret10.c)
 *
 * Tests passing NULL into the value (pointer) parameters of remove_front()
 * and remove_back().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int elt;

  init(&twosq);

  add_front(&twosq, 216);
  add_back(&twosq, 250);

  /* these should have no effect- they certainly should not crash */
  remove_front(&twosq, NULL);
  remove_back(&twosq, NULL);

  assert(num_elements(&twosq) == 2);

  remove_front(&twosq, &elt);
  assert(elt == 216);
  remove_front(&twosq, &elt);
  assert(elt == 250);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
