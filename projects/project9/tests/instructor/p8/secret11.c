#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 11 (secret11.c)
 *
 * Tests that add_edge() does allow zero-weight edges.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  new_vertex_add(&graph, "hedgehog");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "panda");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "numbat");

  add_edge(&graph, "hedgehog", "parrot", 1);
  add_edge(&graph, "panda", "koala", 7);

  assert(add_edge(&graph, "hedgehog", "kangaroo", 0) == 1);
  assert(add_edge(&graph, "numbat", "panda", 0) == 1);

  assert(get_weight_of_edge(&graph, "hedgehog", "kangaroo") == 0);
  assert(get_weight_of_edge(&graph, "numbat", "panda") == 0);

  printf("The assertions all worked!\n");

  return 0;
}
