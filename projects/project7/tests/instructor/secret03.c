#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 3 (secret03.c)
 *
 * Tests creating multiple Two_sided_queue} variables and adding different
 * elements to them, to ensure that their data doesn't conflict.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq1, twosq2;
  int i;

  init(&twosq1);
  init(&twosq2);

  for (i= 5; i >= 1; i--)
    add_front(&twosq1, i);
  for (i= 6; i <= 10; i++)
    add_back(&twosq1, i);

  for (i= 105; i >= 101; i--)
    add_front(&twosq2, i);
  for (i= 106; i <= 110; i++)
    add_back(&twosq2, i);

  assert(num_elements(&twosq1) == 10);
  assert(num_elements(&twosq2) == 10);

  print(&twosq1);
  print(&twosq2);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
