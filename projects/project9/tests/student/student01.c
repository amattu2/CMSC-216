#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

/**
 * This test adds and removes verticies multiple times
 * It also tests destroying/recreating a graph
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "quokka", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  char *vertices_to_add2[]= {"koala", "quokka", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  int i;

  init_graph(&graph);

  /* Add verticies */
  for (i = 0; i < 7; i++)
    new_vertex_add(&graph, vertices_to_add[i]);
  assert(num_vertices(&graph) == 7);

  /* Remove them */
  for (i = 0; i < 7; i++)
    remove_vertex(&graph, vertices_to_add[i]);
  assert(num_vertices(&graph) == 0);

  /* Destroy graph */
  destroy_graph(&graph);

  /* Add Verticies */
 for (i = 0; i < 7; i++)
   new_vertex_add(&graph, vertices_to_add2[i]);
 assert(num_vertices(&graph) == 7);

 /* Remove them */
 for (i = 0; i < 7; i++)
   remove_vertex(&graph, vertices_to_add2[i]);
 assert(num_vertices(&graph) == 0);

  printf("Pass!\n");

  return 0;
}
