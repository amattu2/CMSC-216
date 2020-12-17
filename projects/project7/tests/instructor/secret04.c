#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 4 (secret04.c)
 *
 * Tests calling remove_front() and remove_back() on empty queues, and tests
 * the return values of the functions other than num_elements().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int elt;

  init(&twosq);

  assert(remove_front(&twosq, &elt) == 0);
  assert(remove_back(&twosq, &elt) == 0);
  assert(num_elements(&twosq) == 0);

  assert(add_front(NULL, 123) == 0);
  assert(add_back(NULL, 456) == 0);

  assert(add_front(&twosq, 216) == 1);
  assert(add_front(&twosq, 216) == 1);

  assert(num_elements(&twosq) == 2);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
