#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 5 (secret05.c)
 *
 * Tests passing NULL into the twosq parameters of the functions that it
 * wasn't tested for in the public tests.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;

  init(&twosq);

  assert(add_back(NULL, 123) == 0);
  print(NULL);
  assert(num_elements(NULL) == 0);

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
