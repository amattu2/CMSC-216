/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
*/

/*
 * Testing get_vertices
 * Ensure that a pointer is used to reference each element
 * and also that they don't point to node elements (deep copy)
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

int main() {
  WString_graph graph;
  char **verticies;
  char *current;

  init_graph(&graph);

  /* Empty graph */
  verticies = get_vertices(&graph);
  assert(verticies[0] == NULL);

  /* Add verticies */
  assert(new_vertex_add(&graph, "v1") == 1);
  assert(new_vertex_add(&graph, "v1") == 0); /* Duplicate */
  assert(new_vertex_add(&graph, "v2") == 1);
  assert(new_vertex_add(&graph, "v3") == 1);
  assert(new_vertex_add(&graph, "v4") == 1);
  assert(new_vertex_add(&graph, "v5") == 1);
  assert(new_vertex_add(&graph, "v3") == 0); /* duplicate */

  /* Full graph */
  verticies = get_vertices(&graph);
  assert(verticies[0] != NULL);

  /* Test alphabetical ordering */


  printf("Pass\n");

  return 0;
}
