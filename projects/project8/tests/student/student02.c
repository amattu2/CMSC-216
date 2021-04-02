/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: -
 * Directory ID: amattu
 *
 * Author: Alec M.
*/

/**
 * Test calling various functions on null/invalid values
 */

#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* Add a good edge, test count */
  assert(add_edge(&graph, "one", "two", 1) == 1);
  assert(num_vertices(&graph) == 2); /* one, two */
  assert(add_edge(&graph, "one", "two", 1) == 1);
  assert(num_vertices(&graph) == 2); /* same as before */
  assert(add_edge(&graph, "two", "one", 1) == 1);
  assert(num_vertices(&graph) == 2); /* same as before */
  assert(add_edge(&graph, "one", "one", 1) == 1);
  assert(add_edge(&graph, "two", "two", 1) == 1);

  printf("Pass\n");

  return 0;
}
