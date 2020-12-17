#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Public test 3 (public03.c)
 *
 * Tests adding elements to the back of a queue and checking its size.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define SZ 8

int main(void) {
  Two_sided_queue twosq;
  int elements[SZ]= {2, 6, 3, 8, 0, 1, 5, 7};
  int i;

  init(&twosq);

  for (i= 0; i < SZ; i++)
    add_back(&twosq, elements[i]);

  assert(num_elements(&twosq) == 8);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
