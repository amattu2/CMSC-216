#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 10 (secret10.c)
 *
 * Tests that add_edge() does not actually add an edge when the edge has a
 * negative weight.
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

  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "koala", "parrot", 2);
  add_edge(&graph, "numbat", "panda", 6);
  add_edge(&graph, "koala", "numbat", 10);
  add_edge(&graph, "hedgehog", "parrot", 1);
  add_edge(&graph, "panda", "koala", 7);
  add_edge(&graph, "hedgehog", "hedgehog", 9);

  assert(add_edge(&graph, "hedgehog", "parrot", -5) == 0);

  assert(get_weight_of_edge(&graph, "hedgehog", "parrot") == 1);

  printf("The assertions all worked!\n");  /* the assertion succeeded */

  return 0;
}
