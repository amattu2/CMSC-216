#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 3 (public03.c)
 *
 * Tests the return value of new_vertex_add() when a new vertex is successfully
 * added, and when it's called on already-existing vertices.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;

  init_graph(&graph);

  /* add some vertices */
  assert(new_vertex_add(&graph, "koala"));
  assert(new_vertex_add(&graph, "parrot"));
  assert(new_vertex_add(&graph, "panda"));

  /* now try to add them again */
  assert(!new_vertex_add(&graph, "koala"));
  assert(!new_vertex_add(&graph, "parrot"));
  assert(!new_vertex_add(&graph, "panda"));

  printf("The assertions all worked!\n");

  return 0;
}
