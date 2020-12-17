#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 7 (public07.c)
 *
 * Tests calling remove_vertex() and ensures that the vertices are properly
 * removed, and ensures that all memory was properly released and there are
 * no errors in the heap.  This test is the same as public03.c other than
 * for checking the correctness of the heap.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "quokka", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  char *expected_results[]= {"dog", "frog", "hedgehog", "quokka", "zebra",
                             NULL};
  char **names;
  int i;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* now remove two of them */
  remove_vertex(&graph, "koala");
  remove_vertex(&graph, "parrot");

  names= get_vertices(&graph);

  /* check the vertices against the results that we expect to be returned */
  compare_vertex_lists(names, expected_results);

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
