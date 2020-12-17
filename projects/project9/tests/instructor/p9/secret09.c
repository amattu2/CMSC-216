#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 9 (secret09.c)
 *
 * Tests calling remove_vertex() on nonexistent vertices, and ensures that
 * all memory was properly released and there are no errors in the heap.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog",
                 "hedgehog", "parrot", "giraffe", "snake", "snake"};
  char *to[]= {"hedgehog", "dog", "frog", "koala", "dog", "parrot",
               "koala", "salamander", "frog", "salamander"};
  char *expected_vertices[]= {"dog", "frog", "giraffe", "hedgehog", "koala",
                              "parrot", "salamander", "snake", NULL};
  char *expected_neighbors[][5]= {
    {"hedgehog", NULL},                        /* neighbors of dog */
    {"dog", NULL},                             /* neighbors of frog */
    {"salamander", NULL},                      /* neighbors of giraffe */
    {"dog", "frog", "koala", "parrot", NULL},  /* neighbors of hedgehog */
    {NULL},                                    /* neighbors of koala */
    {"koala", NULL},                           /* neighbors of parrot */
    {NULL},                                    /* neighbors of salamander */
    {"frog", "salamander", NULL},              /* neighbors of snake */
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
    add_edge(&graph, from[i], to[i], i);

  /* call remove_vertex() on bogus vertices */
  assert(!remove_vertex(&graph, "turkey"));
  assert(!remove_vertex(&graph, "lamb"));
  assert(!remove_vertex(&graph, "goat"));

  /* now check the graph */
  assert(num_vertices(&graph) == NUM_ELTS(vertices_to_add));

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
