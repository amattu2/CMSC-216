#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 6 (secret06.c)
 *
 * Tests calling get_vertices() on an empty graph with no vertices.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  WString_graph graph;
  char **names;

  init_graph(&graph);

  names= get_vertices(&graph);

  assert(names[0] == NULL);

  printf("Everything worked perfectly!\n");

  return 0;
}
