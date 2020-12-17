#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 10 (public10.c)
 *
 * Tests adding vertices back to a graph after all vertices were removed
 * using remove_vertex(), and ensures that all memory was properly released
 * and there are no errors in the heap.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices[]= {"koala", "quokka", "parrot", "zebra", "hedgehog", "dog",
                     "frog"};
  char *expected_results[]= {"blobfish", "naked mole rat",
                             "pink fairy armadillo", "star-nosed mole"};
  char **names;
  int i;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices); i++)
    new_vertex_add(&graph, vertices[i]);

  /* check them */
  assert(num_vertices(&graph) == 7);

  /* now remove all of them */
  for (i= 0; i < NUM_ELTS(vertices); i++)
    remove_vertex(&graph, vertices[i]);

  /* check them again */
  assert(num_vertices(&graph) == 0);

  /* add a few more */
  new_vertex_add(&graph, "star-nosed mole");
  new_vertex_add(&graph, "blobfish");
  new_vertex_add(&graph, "pink fairy armadillo");
  new_vertex_add(&graph, "naked mole rat");

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
