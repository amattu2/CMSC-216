#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 6 (public06.c)
 *
 * Tests the return value of add_edge() with both positive and negative
 * weight edges.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* add some vertices */
  new_vertex_add(&graph, "hedgehog");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "panda");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "giraffe");

  /* call add_edge() and don't even test for the presence or absence of the
     edges later, just test add_edge()'s return value */

  /* these two edges are valid */
  assert(add_edge(&graph, "hedgehog", "kangaroo", 8));
  assert(add_edge(&graph, "koala", "parrot", 2));

  /* this edges is not valid */
  assert(add_edge(&graph, "giraffe", "panda", -10) == 0);

  printf("The assertions all worked!\n");

  return 0;
}
