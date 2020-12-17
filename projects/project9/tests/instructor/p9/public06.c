#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 6 (public06.c)
 *
 * Tests calling remove_edge() and ensures that the edges are properly
 * removed, and ensures that all memory was properly released and there are
 * no errors in the heap.  This test is the same as public02.c other than
 * for checking the correctness of the heap.
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

  /* check hedgehog's neighbors */
  assert(num_neighbors(&graph, "hedgehog") == 4);

  /* now remove two of them */
  remove_edge(&graph, "hedgehog", "koala");
  remove_edge(&graph, "hedgehog", "salamander");

  /* check its neighbors again */
  assert(num_neighbors(&graph, "hedgehog") == 2);
  assert(get_weight_of_edge(&graph, "hedgehog", "dog") == 9);
  assert(get_weight_of_edge(&graph, "hedgehog", "snake") == 3);

  /* now clean up after ourselves */
  destroy_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  /* if this is the only thing printed the heap must be valid, and there
   * must not have been any memory leaks
   */
  printf("Everything worked perfectly!\n");

  return 0;
}
