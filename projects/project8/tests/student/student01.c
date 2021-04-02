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

  /* Test invalid verticies */
  assert(new_vertex_add(NULL, "NULL") == 0);
  assert(new_vertex_add(NULL, NULL) == 0);
  assert(new_vertex_add(&graph, NULL) == 0);

  /* Check size */
  assert(num_vertices(&graph) == 0);
  assert(num_vertices(NULL) == 0);

  /* Add bad edges */
  assert(add_edge(&graph, "one", "two", -1) == 0);
  assert(num_vertices(&graph) == 0);
  assert(add_edge(&graph, NULL, "two", 6) == 0);
  assert(num_vertices(&graph) == 0);
  assert(add_edge(&graph, "one", NULL, 9) == 0);
  assert(num_vertices(&graph) == 0);
  assert(add_edge(&graph, NULL, NULL, 4) == 0);
  assert(num_vertices(&graph) == 0);

  /* Add a good edge, test count */
  assert(add_edge(&graph, "one", "two", 1) == 1);
  assert(num_vertices(&graph) == 2); /* one, two */

  printf("Pass\n");

  return 0;
}
