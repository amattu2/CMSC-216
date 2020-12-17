#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 14 (secret14.c)
 *
 * Tests calling add_edge() to change the weights of some existing edges
 * that are already present in a graph.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* add vertices */
  new_vertex_add(&graph, "hedgehog");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "panda");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "giraffe");

  /* add edges between them */
  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "koala", "parrot", 2);
  add_edge(&graph, "giraffe", "panda", 6);
  add_edge(&graph, "koala", "giraffe", 10);
  add_edge(&graph, "hedgehog", "parrot", 1);
  add_edge(&graph, "panda", "koala", 7);
  add_edge(&graph, "hedgehog", "hedgehog", 9);

  /* change some of the edge weights; because these edges already exist */
  add_edge(&graph, "koala", "giraffe", 100);
  add_edge(&graph, "panda", "koala", 400);
  add_edge(&graph, "hedgehog", "kangaroo", 200);
  add_edge(&graph, "hedgehog", "hedgehog", 300);
  /* changing the edge weight to be the same as before is also OK */
  add_edge(&graph, "giraffe", "panda", 6);

  /* check the edge weights have changed */
  assert(get_weight_of_edge(&graph, "koala", "giraffe") == 100);
  assert(get_weight_of_edge(&graph, "panda", "koala") == 400);
  assert(get_weight_of_edge(&graph, "hedgehog", "kangaroo") == 200);
  assert(get_weight_of_edge(&graph, "hedgehog", "hedgehog") == 300);
  assert(get_weight_of_edge(&graph, "giraffe", "panda") == 6);

  printf("The assertions all worked!\n");

  return 0;
}
