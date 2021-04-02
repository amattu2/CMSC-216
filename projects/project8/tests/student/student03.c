/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: -
 * Directory ID: amattu
 *
 * Author: Alec M.
*/

/**
 * Add a edge
 * Check adding it again (Updating it's value)
 * Check it's new value
 */

#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

int main() {
  WString_graph graph;

  init_graph(&graph);

  assert(add_edge(&graph, "v1", "v2", 3) == 1);
  assert(get_weight_of_edge(&graph, "v1", "v2") == 3);
  assert(get_weight_of_edge(&graph, "v2", "v1") == -1); /* doesn't exist */
  assert(get_weight_of_edge(&graph, "v2", NULL) == -1); /* NULL param */
  assert(add_edge(&graph, "v1", "v2", 5) == 1);
  assert(get_weight_of_edge(&graph, "v1", "v2") == 5); /* Updated to 5 */
  
  printf("Pass\n");

  return 0;
}
