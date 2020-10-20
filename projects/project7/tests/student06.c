#include <stdio.h>
#include <assert.h>
#include "two-sided-queue.h"

/*
 * Test adding to front/back rotationally
 * Then removing elements
*/
int main(void) {
  Two_sided_queue queue;

  init(&queue);
  add_front(&queue, 2);
  print(&queue);
  assert(num_elements(&queue) == 1);

  printf("You should see ONLY 2 on the above line\n");

  return 0;
}
