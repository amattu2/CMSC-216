#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 9 (public09.c)
 *
 * Tests calling num_neighbors() on some vertices that have neighbors in a
 * graph.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* add some vertices */
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "panda");
  new_vertex_add(&graph, "giraffe");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "hedgehog");

  /* add some edges between them */
  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "koala", "parrot", 2);
  add_edge(&graph, "giraffe", "panda", 6);
  add_edge(&graph, "koala", "giraffe", 10);
  add_edge(&graph, "hedgehog", "parrot", 1);
  add_edge(&graph, "panda", "koala", 7);
  add_edge(&graph, "hedgehog", "hedgehog", 9);

  /* test the number of neighbors of three of the vertices */
  assert(num_neighbors(&graph, "giraffe") == 1);
  assert(num_neighbors(&graph, "koala") == 2);
  assert(num_neighbors(&graph, "hedgehog") == 3);

  printf("The assertions all worked!\n");

  return 0;
}
