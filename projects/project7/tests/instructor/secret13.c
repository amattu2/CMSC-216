#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 13 (secret13.c)
 *
 * Tests removing all elements from a queue and then calling num_elements()
 * and print().
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

  assert(num_elements(&twosq) == 0);
  print(&twosq);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
