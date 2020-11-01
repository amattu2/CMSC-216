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
  assert(new_vertex_add(&graph, "A") == 1);
  assert(new_vertex_add(&graph, "B") == 0); /* Duplicate */
  assert(new_vertex_add(&graph, "C") == 1);
  assert(new_vertex_add(&graph, "D") == 1);
  assert(new_vertex_add(&graph, "E") == 1);
  assert(new_vertex_add(&graph, "F") == 1);
  assert(new_vertex_add(&graph, "G") == 0); /* duplicate */

  /* Full graph */
  verticies = get_vertices(&graph);
  assert(verticies[0] != NULL);

  /* Test alphabetical ordering */


  printf("Pass\n");

  return 0;
}
