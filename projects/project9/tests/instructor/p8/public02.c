#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 2 (public02.c)
 *
 * Tests initializing a graph and calling num_vertices() before any vertices
 * have been added, then on some vertices that have been added to the graph,
 * as well as some nonexistent vertices.
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
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "elephant");
  new_vertex_add(&graph, "naked mole rat");

  /* check that these are existent vertices */
  assert(is_existing_vertex(&graph, "hedgehog"));
  assert(is_existing_vertex(&graph, "parrot"));
  assert(is_existing_vertex(&graph, "elephant"));
  assert(is_existing_vertex(&graph, "naked mole rat"));

  /* check that these are nonexistent vertices */
  assert(!is_existing_vertex(&graph, "deer"));
  assert(!is_existing_vertex(&graph, "rabbit"));

  printf("The assertions all worked!\n");

  return 0;
}
