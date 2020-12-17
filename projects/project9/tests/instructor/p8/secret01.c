#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 1 (secret01.c)
 *
 * Tests that vertex names are being correctly compared when vertices are
 * added and looked up using is_existing_vertex().
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

  /* these are not names of existing vertices */
  assert(is_existing_vertex(&graph, "Caterpillar") == 0);
  assert(is_existing_vertex(&graph, "ELEPHANT") == 0);
  assert(is_existing_vertex(&graph, "cat") == 0);
  assert(is_existing_vertex(&graph, "cup") == 0);
  assert(is_existing_vertex(&graph, "ant") == 0);

  printf("The assertions all worked!\n");

  return 0;
}
