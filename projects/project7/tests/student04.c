#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

#define size 8

/*
 * Test double initialization
*/
int main(void) {
  Two_sided_queue queue;
  int elements[size]= {2, 6, 3, 8, 0, 1, 5, 7};
  int elements2[size]= {7, 5, 1, 0, 8, 3, 6, 2};
  int i;

  init(&queue);

  for (i= 0; i < size; i++)
    add_front(&queue, elements[i]);

  assert(num_elements(&queue) == 8);

  init(&queue);

  for (i= 0; i < size; i++)
    add_front(&queue, elements2[i]);

  assert(num_elements(&queue) == 8);

  printf("Pass\n");

  return 0;
}
