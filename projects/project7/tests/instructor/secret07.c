#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/* CMSC 216, Fall 2020, Project #7
 * Secret test 7 (secret07.c)
 *
 * Tests making a mixture of calls that add and remove elements to and from
 * both ends of a queue.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Two_sided_queue twosq;
  int i, elt;

  init(&twosq);

  for (i= 1; i <= 40; i++) {
    if (i % 3 == 0)
      add_front(&twosq, i);
    else
      if (i % 3 == 1)
        add_back(&twosq, i);
      else {
        if (i % 6 == 0)
          remove_front(&twosq, &elt);
        else remove_back(&twosq, &elt);

        assert(elt == i - 1);
      }
  }

  printf("All assertions experienced a favorable outcome!\n");

  return 0;
}
