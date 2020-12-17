#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 5 (secret05.c)
 *
 * Tests calling get_neighbors() on a nonexistent vertex name that isn't
 * present in a graph.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog", "parrot",
                 "panda", "giraffe", "snake", "snake"};
  char *to[]= {"frog", "dog", "salamander", "koala", "dog", "parrot", "koala",
               "salamander", "frog", "salamander"};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], i);

  /* no walruses here */
  assert(get_neighbors(&graph, "walrus") == NULL);

  printf("Everything worked perfectly!\n");

  return 0;
}
