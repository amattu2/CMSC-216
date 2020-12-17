#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 2 (secret02.c)
 *
 * Tests that when remove_front() and remove_back() are called on an empty
 * queue they don't modify the variable that their parameter value points
 * to.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int elt= 216;

  init(&twosq);

  remove_front(&twosq, &elt);
  assert(elt == 216);

  remove_back(&twosq, &elt);
  assert(elt == 216);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
