#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 1 (public01.c)
 *
 * Tests initializing a graph and calling num_vertices() before any vertices
 * have been added, then after some vertices have been added.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* the graph should be completely devoid of vertices */
  assert(num_vertices(&graph) == 0);

  /* let's address that situation now */
  new_vertex_add(&graph, "hedgehog");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "elephant");
  new_vertex_add(&graph, "naked mole rat");

  /* how many vertices now? */
  assert(num_vertices(&graph) == 6);

  printf("The assertions all worked!\n");

  return 0;
}
