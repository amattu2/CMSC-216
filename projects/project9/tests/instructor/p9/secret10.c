#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 10 (secret10.c)
 *
 * Tests calling remove_vertex() to remove vertices that have self-edges,
 * and ensures that all memory was properly released and there are no errors
 * in the heap.
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
    add_edge(&graph, from[i], to[i], i);

  /* remove the vertices with self-edges, which should not cause an error */
  assert(remove_vertex(&graph, "frog"));
  assert(remove_vertex(&graph, "snake"));
  assert(num_vertices(&graph) == 6);

  /* now clean up after ourselves */
  destroy_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
