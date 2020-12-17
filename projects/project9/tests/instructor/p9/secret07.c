#
#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 7 (secret07.c)
 *
 * Tests adding vertices and edges back to a graph after destroy_graph() is
 * called on it, and ensures that all memory was properly released and there
 * are no errors in the heap.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "panda", "parrot", "snake",
                            "salamander", "giraffe", "frog", "dog",
                            "hedgehog"};
  char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog", "panda",
                 "parrot", "giraffe", "snake", "snake"};
  char *to[]= {"frog", "dog", "salamander", "koala", "dog", "parrot", "koala",
               "salamander", "frog", "salamander"};
  int costs[]= {2, 5, 9, 8, 7, 3, 1, 2, 10, 6};
  char *expected_vertices[]= {"dog", "frog", "giraffe", "hedgehog", "koala",
                              "panda", "parrot", "salamander", "snake",
                              NULL};
  char *expected_neighbors[][4]= {
    {"salamander", NULL},              /* neighbors of dog */
    {"koala", NULL},                   /* neighbors of frog */
    {"salamander", NULL},              /* neighbors of giraffe */
    {"dog", "koala", "parrot", NULL},  /* neighbors of hedgehog */
    {NULL},                            /* neighbors of koala */
    {"salamander", NULL},              /* neighbors of parrot */
    {"frog"},                          /* neighbors of panda */
    {NULL},                            /* neighbors of salamander */
    {"dog", "frog", NULL},             /* neighbors of snake */
  };
  char **names, **neighbors;
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

  /* now trash the whole thing */
  destroy_graph(&graph);

  /* now reinitialize */
  init_graph(&graph);

  /* now add some vertices and edges back */
  /* the vertices are the same as before, just added in a different order */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[(i + 3) %
                   NUM_ELTS(vertices_to_add)]);
  /* the edges are different than the original ones */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[(i + 2) % NUM_ELTS(from)], costs[i]);

  /* now check the graph */
  names= get_vertices(&graph);
  assert(compare_vertex_lists(names, expected_vertices));

  i= 0;
  while (names[i] != NULL) {
    neighbors= get_neighbors(&graph, names[i]);
    assert(compare_vertex_lists(neighbors, expected_neighbors[i++]));
    free_vertex_list(neighbors);
  }
    
  /* now clean up after ourselves */
  free_vertex_list(names);
  destroy_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
