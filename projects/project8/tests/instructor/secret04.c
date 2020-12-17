#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 4 (secret04.c)
 *
 * Creates a graph with a large number of edges.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_VERTICES 500

int main() {
  WString_graph graph;
  char name[11], name2[11];
  int i, j;

  init_graph(&graph);

  /* create many vertices */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%04d", i);
    new_vertex_add(&graph, name);
  }

  assert(num_vertices(&graph) == NUM_VERTICES);

  /* create many edges; every vertex has an edge to every vertex */
  for (i= 0; i < NUM_VERTICES; i++)
    for (j= 0; j < NUM_VERTICES; j++) {
      sprintf(name, "vertex%04d", i);
      sprintf(name2, "vertex%04d", j);
      assert(add_edge(&graph, name, name2, i + j) == 1);
    }

  /* check the edges */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%04d", i);
    assert(num_neighbors(&graph, name) == NUM_VERTICES);
  }

  printf("The assertions all worked!\n");

  return 0;
}
