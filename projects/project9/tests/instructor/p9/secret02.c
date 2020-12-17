#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 2 (secret02.c)
 *
 * Tests calling get_neighbors() on a vertex that has a self-edge, which is
 * one of its own neighbors.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog", "parrot",
                 "parrot", "giraffe", "snake", "snake"};
  char *to[]= {"frog", "frog", "dog", "salamander", "koala", "koala",
               "salamander", "giraffe", "salamander", "snake"};
  char *expected_neighbors1[]= {"frog", NULL};
  char *expected_neighbors2[]= {"salamander", "snake", NULL};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], i);

  /* check the neighbors of frog; it itself is its only neighbor */
  names= get_neighbors(&graph, "frog");
  assert(compare_vertex_lists(names, expected_neighbors1));

  /* check the neighbors of snake; it is one of its two neighbors */
  names= get_neighbors(&graph, "snake");
  assert(compare_vertex_lists(names, expected_neighbors2));

  /* now clean up after ourselves */
  destroy_graph(&graph);

  printf("Everything worked perfectly!\n");

  return 0;
}
