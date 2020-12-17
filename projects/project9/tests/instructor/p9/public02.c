#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 2 (public02.c)
 *
 * Tests calling remove_edge() and ensures that the edges are properly
 * removed.  This test does not check for memory leaks or correctness of the
 * heap; it is only testing the correct behavior of the function.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog", "hedgehog",
                 "parrot", "panda", "giraffe", "snake", "snake"};
  char *to[]= {"frog", "dog", "dog", "salamander", "koala", "snake", "koala",
               "salamander", "frog", "salamander", "parrot"};
  const int costs[]= {2, 5, 9, 8, 7, 3, 1, 2, 10, 6, 12};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  /* check hedgehog's neighbors */
  assert(num_neighbors(&graph, "hedgehog") == 4);

  /* now remove two of them */
  remove_edge(&graph, "hedgehog", "koala");
  remove_edge(&graph, "hedgehog", "salamander");

  /* check its neighbors again */
  assert(num_neighbors(&graph, "hedgehog") == 2);
  assert(get_weight_of_edge(&graph, "hedgehog", "dog") == 9);
  assert(get_weight_of_edge(&graph, "hedgehog", "snake") == 3);

  printf("Everything worked perfectly!\n");

  return 0;
}
