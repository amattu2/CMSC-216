#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 12 (secret12.c)
 *
 * Tests that edges are being properly added- adds edges in both directions
 * between two vertices, adds different outgoing edges with the same weight
 * going from a vertex to different neighbors, and checks that adding an
 * outgoing edge from a vertex does not cause an incoming edge to be added
 * as well.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"hedgehog", "koala", "panda", "kangaroo",
                            "parrot", "numbat"};
  int expected_neighbors[]= {3, 0, 1, 1, 0, 0};
  int i, size= sizeof(vertices_to_add) / sizeof(vertices_to_add[0]);

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < size; i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add a pair of edges in both directions between two vertices */
  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "kangaroo", "hedgehog", 2);

  /* add multiple outgoing edges from the same vertex with the same weight */
  add_edge(&graph, "hedgehog", "panda", 8);
  add_edge(&graph, "hedgehog", "numbat", 8);

  /* used to check that adding an edge does not add the symmetric edge */
  add_edge(&graph, "panda", "koala", 7);

  /* check the results */
  for (i= 0; i < size; i++)
    assert(num_neighbors(&graph, vertices_to_add[i]) == expected_neighbors[i]);

  assert(get_weight_of_edge(&graph, "hedgehog", "kangaroo") == 8);
  assert(get_weight_of_edge(&graph, "kangaroo", "hedgehog") == 2);

  assert(get_weight_of_edge(&graph, "hedgehog", "panda") == 8);
  assert(get_weight_of_edge(&graph, "hedgehog", "numbat") == 8);

  assert(get_weight_of_edge(&graph, "koala", "panda") == -1);

  printf("The assertions all worked!\n");

  return 0;
}
