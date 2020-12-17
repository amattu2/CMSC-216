#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 3 (secret03.c)
 *
 * Creates a graph with a large number of vertices.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_VERTICES 12345

int main() {
  WString_graph graph;
  char name[12];
  int i;

  init_graph(&graph);

  /* create many vertices */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%05d", i);
    new_vertex_add(&graph, name);
  }

  assert(num_vertices(&graph) == NUM_VERTICES);

  printf("The assertions all worked!\n");  /* the assertion succeeded */

  return 0;
}
