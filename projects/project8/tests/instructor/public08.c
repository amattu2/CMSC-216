#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 8 (public08.c)
 *
 * Tests calling new_vertex_add() with a NULL vertex name.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* add some vertices, but the fourth one has a NULL name */
  new_vertex_add(&graph, "hedgehog");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "panda");
  new_vertex_add(&graph, NULL);  /* should have no effect, but not crash */
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "giraffe");

  /* test that all of the other new_vertex_add() calls worked fine, and the
     fourth one was just ignored and had no effect */
  assert(num_vertices(&graph) == 5);
  assert(is_existing_vertex(&graph, "hedgehog"));
  assert(is_existing_vertex(&graph, "koala"));
  assert(is_existing_vertex(&graph, "panda"));
  assert(is_existing_vertex(&graph, "parrot"));
  assert(is_existing_vertex(&graph, "giraffe"));

  printf("The assertions all worked!\n");

  return 0;
}
