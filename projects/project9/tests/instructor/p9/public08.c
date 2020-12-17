#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 8 (public08.c)
 *
 * Tests calling get_neighbors(), and ensures that all memory was properly
 * released and there are no errors in the heap.  This test is the same as
 * public04.c other than for checking the correctness of the heap.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hippopotamus"};
  char *from[]= {"dog", "frog", "hippopotamus", "hippopotamus",
                 "hippopotamus", "parrot", "panda", "giraffe", "snake",
                 "snake"};
  char *to[]= {"frog", "dog", "dog", "salamander", "koala", "koala",
               "salamander", "frog", "salamander", "parrot"};
  const int costs[]= {2, 5, 9, 8, 7, 3, 1, 2, 10, 6};
  char *expected_results[]= {"dog", "koala", "salamander", NULL};
  char **names;
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

  names= get_neighbors(&graph, "hippopotamus");

  /* check the neighbors against the results that we expect to be returned */
  assert(compare_vertex_lists(names, expected_results));

  /* now clean up after ourselves */
  free_vertex_list(names);
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
