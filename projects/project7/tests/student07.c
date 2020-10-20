#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/*
 * Test calling functions on null pointer
*/
int main(void) {
  Two_sided_queue queue;
  int prt;
  init(&queue); /* legit setup */

  init(NULL);
  print(NULL);
  assert(remove_front(NULL, NULL) == 0);
  assert(remove_back(NULL, NULL) == 0);

  /* Legit queue, illegitimate value pointer */
  assert(remove_front(&queue, NULL) == 0);
  assert(remove_back(&queue, NULL) == 0);

  /* Legit value, illegitimate queue */
  assert(remove_front(NULL, &prt) == 0);
  assert(remove_back(NULL, &prt) == 0);

  printf("Pass\n");

  return 0;
}
