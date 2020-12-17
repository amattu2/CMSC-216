#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 3 (secret03.c)
 *
 * Tests calling destroy_graph() on a graph that has some vertices with
 * self-edges.
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
  char *to[]= {"frog", "frog", "dog", "salamander", "koala", "koala",
               "salamander", "giraffe", "salamander", "snake"};
  int costs[]= {2, 5, 9, 8, 7, 3, 1, 2, 10, 6};
  int i;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  /* now clean up after ourselves */
  destroy_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
