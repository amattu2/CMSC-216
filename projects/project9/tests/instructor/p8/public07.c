#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 7 (public07.c)
 *
 * Tests calling get_weight_of_edge() on nonexistent edges.
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

  /* none of these edges exist */
  assert(get_weight_of_edge(&graph, "koala", "hedgehog") == -1);
  assert(get_weight_of_edge(&graph, "hedgehog", "frog") == -1);
  assert(get_weight_of_edge(&graph, "frog", "dog") == -1);
  assert(get_weight_of_edge(&graph, "lion", "tiger") == -1);

  printf("The assertions all worked!\n");

  return 0;
}
