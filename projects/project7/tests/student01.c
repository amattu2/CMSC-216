#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

#define size 8

/*
 * Test adding 8 elements to the back of a queue
 * Test removing exactly 8 elements from a queue
*/
int main(void) {
  Two_sided_queue queue;
  int elements[size]= {2, 6, 3, 8, 0, 1, 5, 7};
  int i;
  int temp;

  init(&queue);

  for (i= 0; i < size; i++)
    add_back(&queue, elements[i]);

  assert(num_elements(&queue) == 8);

  for (i= 0; i < size; i++)
    remove_back(&queue, &temp);

  assert(num_elements(&queue) == 0);

  printf("Pass\n");

  return 0;
}
