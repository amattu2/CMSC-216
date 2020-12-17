#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 15 (secret15.c)
 *
 * Tests calling some of the functions passing NULL into WString_graph
 * pointer parameters.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"orangutan", "jellyfish", "amoeba", "unicorn",
                            "Indian purple frog"};
  int i, j, size= sizeof(vertices_to_add) / sizeof(vertices_to_add[0]);

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < size; i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      add_edge(&graph, vertices_to_add[i], vertices_to_add[j], (i * 10) + j);

  /* pass NULL into all functions that take a pointer to a WString_graph as
     an argument */
  assert(new_vertex_add(NULL, "snail") == 0);
  assert(add_edge(NULL, "eel", "jellyfish", 1) == 0);

  /* check that nothing in the graph changed */
  assert(num_vertices(&graph) == 5);

  for (i= 0; i < size; i++)
    assert(is_existing_vertex(&graph, vertices_to_add[i]));

  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      assert(get_weight_of_edge(&graph, vertices_to_add[i],
                                vertices_to_add[j]) == (i * 10) + j);

  printf("The assertions all worked!\n");

  return 0;
}
