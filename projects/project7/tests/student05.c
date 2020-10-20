#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

#define size 8

/*
 * Test adding to front/back rotationally
 * Then removing elements
*/
int main(void) {
  Two_sided_queue queue;
  int elements[size]= {2, 6, 3, 8, 0, 1, 5, 7};
  int i;
  int temp;

  init(&queue);

  for (i = 0; i < size; i++) {
    if (i % 2 == 0) {
      add_front(&queue, elements[i]);
    } else {
      add_back(&queue, elements[i]);
    }
  }

  assert(num_elements(&queue) == 8);

  for (i = 0; i < size; i++) {
    if (i % 2 == 0) {
      remove_back(&queue, &temp);
    } else {
      remove_front(&queue, &temp);
    }
  }

  assert(num_elements(&queue) == 0);

  printf("Pass\n");

  return 0;
}
