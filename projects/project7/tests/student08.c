#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

#define size1 7
#define size2 8

/*
 * Test adding to two independent queues
*/
int main(void) {
  Two_sided_queue queue1;
  Two_sided_queue queue2;
  int elements1[size1]= {2, 6, 3, 8, 0, 1, 5};
  int elements2[size2]= {2, 6, 3, 8, 0, 1, 5, 7};
  int i;

  init(&queue1);
  init(&queue2);

  for (i = 0; i < size1; i++)
    add_back(&queue1, elements1[i]);

  assert(num_elements(&queue1) == size1);

  for (i = 0; i < size2; i++)
    add_front(&queue2, elements2[i]);

  assert(num_elements(&queue2) == size2);

  printf("Pass\n");

  return 0;
}
