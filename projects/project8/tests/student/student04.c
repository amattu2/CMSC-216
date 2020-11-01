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
 * - Ordering
 * - Adding
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

int main() {
  WString_graph graph;
  char **verticies;
  char *current = NULL;
  int index = 0;
  char *ordered[] = {"A", "B", "C", "D", "E", "F", "G", NULL};

  init_graph(&graph);

  /* Empty graph */
  verticies = get_vertices(&graph);
  assert(verticies[0] == NULL);

  /* Add verticies */
  assert(new_vertex_add(&graph, "B") == 1);
  assert(new_vertex_add(&graph, "G") == 1);
  assert(new_vertex_add(&graph, "F") == 1);
  assert(new_vertex_add(&graph, "C") == 1);
  assert(new_vertex_add(&graph, "D") == 1);
  assert(new_vertex_add(&graph, "A") == 1);
  assert(new_vertex_add(&graph, "E") == 1);

  /* Full graph */
  verticies = get_vertices(&graph);
  current = verticies[0];
  while (current != NULL) {
    assert(strcmp(current, ordered[index]) == 0);
    current = verticies[++index];
  }

  printf("Pass\n");

  return 0;
}
