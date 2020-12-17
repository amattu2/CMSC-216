#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 13 (secret13.c)
 *
 * Tests that add_edge() adds vertices that don't already exist.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char **names;
  char *expected_vertices[]= {"giraffe", "hedgehog", "kangaroo", "koala",
                              "panda", "parrot", NULL};

  init_graph(&graph);

  /* add edges without having added any vertices */
  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "koala", "parrot", 2);
  add_edge(&graph, "giraffe", "panda", 6);
  add_edge(&graph, "koala", "giraffe", 10);
  add_edge(&graph, "hedgehog", "parrot", 1);
  add_edge(&graph, "panda", "koala", 7);
  add_edge(&graph, "hedgehog", "hedgehog", 9);

  /* all the edges should exist */
  assert(get_weight_of_edge(&graph, "hedgehog", "kangaroo") == 8);
  assert(get_weight_of_edge(&graph, "koala", "parrot") == 2);
  assert(get_weight_of_edge(&graph, "giraffe", "panda") == 6);
  assert(get_weight_of_edge(&graph, "koala", "giraffe") == 10);
  assert(get_weight_of_edge(&graph, "hedgehog", "parrot") == 1);
  assert(get_weight_of_edge(&graph, "panda", "koala") == 7);
  assert(get_weight_of_edge(&graph, "hedgehog", "hedgehog") == 9);

  /* check the vertices also */
  names= get_vertices(&graph);
  assert(compare_vertex_lists(names, expected_vertices));

  printf("The assertions all worked!\n");

  return 0;
}
