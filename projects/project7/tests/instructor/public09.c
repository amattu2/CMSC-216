#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Public test 9 (public09.c)
 *
 * Tests adding elements to both ends of a queue.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define SZ 10

int main(void) {
  Two_sided_queue twosq;
  int elements[SZ]= {1, 4, 7, 0, 3, 6, 9, 2, 5, 8};
  int i;

  init(&twosq);

  for (i= 0; i < SZ; i++)
    add_front(&twosq, elements[i]);

  for (i= 0; i < SZ; i++)
    add_back(&twosq, elements[i]);

  assert(num_elements(&twosq) ==  2 * SZ);

  printf("About to print the queue.\n");
  print(&twosq);
  printf("Finished printing the queue.\n");

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
