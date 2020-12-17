#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 4 (public04.c)
 *
 * Tests calling get_vertices() on a graph that has some vertices.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *expected_vertices[]= {"elephant", "hedgehog", "kangaroo", "koala",
                              "naked mole rat", "parrot", NULL};

  init_graph(&graph);

  /* add some vertices */
  new_vertex_add(&graph, "hedgehog");
  new_vertex_add(&graph, "koala");
  new_vertex_add(&graph, "parrot");
  new_vertex_add(&graph, "kangaroo");
  new_vertex_add(&graph, "elephant");
  new_vertex_add(&graph, "naked mole rat");

  /* uses helper function to ensure that the list of names returned by
     get_vertices() equals the expected list declared above */
  assert(compare_vertex_lists(get_vertices(&graph), expected_vertices));

  printf("The assertions all worked!\n");

  return 0;
}
