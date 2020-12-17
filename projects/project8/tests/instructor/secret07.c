#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 7 (secret07.c)
 *
 * Tests calling some of the functions on an empty graph.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* yes, there really is such a thing as a Venezuelan poodle moth!  but
     there is no vertex with that name in the graph */
  assert(is_existing_vertex(&graph, "Venezuelan poodle moth") == 0);
  assert(num_vertices(&graph) == 0);
  assert(get_weight_of_edge(&graph, "porcupine", "elephant") == -1);
  assert(num_neighbors(&graph, "caterpillar") == -1);

  printf("The assertions all worked!\n");

  return 0;
}
