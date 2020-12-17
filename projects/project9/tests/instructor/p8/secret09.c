#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 9 (secret09.c)
 *
 * Tests calling num_neighbors() on a nonexistent vertex.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < sizeof(vertices_to_add) / sizeof(vertices_to_add[0]); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  assert(num_neighbors(&graph, "Venezuelan poodle moth") == -1);

  printf("The assertions all worked!\n");  /* the assertion succeeded */

  return 0;
}
