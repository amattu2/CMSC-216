#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 9 (public09.c)
 *
 * Tests adding edges back to a vertex after all of its edges were removed
 * using remove_edge(), and ensures that all memory was properly released
 * and there are no errors in the heap.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"horse", "cow", "chicken", "turkey", "lamb",
                            "goat", "donkey", "goose", "mule"};
  char *from[]= {"cow", "cow", "cow", "cow",
                 "lamb", "lamb", "lamb", "lamb", "lamb", "lamb",
                 "mule", "mule", "mule",
                 "donkey", "donkey", "donkey", "donkey",
                 "turkey",
                 "goose",
                 "horse", "horse",
                 "chicken", "chicken", "chicken", "chicken",
                 "goat", "goat", "goat", "goat", "goat"};
  char *to[]= {"lamb", "turkey", "chicken", "goat",
               "mule", "turkey", "goat", "horse", "lamb", "chicken",
               "goose", "mule", "chicken",
               "turkey", "horse", "goat", "cow",
               "horse",
               "turkey", 
               "goose", "chicken", 
               "lamb", "cow", "horse", "mule",
               "cow", "goose", "turkey", "horse", "mule"};
  const int costs[]= {9, 3, 4, 10, 15, 3, 18, 7, 5, 21, 1, 12, 5, 30, 17,
                      14, 8, 29, 15, 27, 3, 1, 5, 1, 6, 8, 15, 26, 10, 9};
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

  /* check donkey's neighbors */
  assert(num_neighbors(&graph, "donkey") == 4);

  /* now remove all of them */
  remove_edge(&graph, "donkey", "turkey");
  remove_edge(&graph, "donkey", "horse");
  remove_edge(&graph, "donkey", "goat");
  remove_edge(&graph, "donkey", "cow");

  /* check its neighbors again */
  assert(num_neighbors(&graph, "donkey") == 0);

  /* now add some new edges to donkey */
  add_edge(&graph, "donkey", "lamb", 100);
  add_edge(&graph, "donkey", "mule", 200);
  add_edge(&graph, "donkey", "chicken", 300);

  /* check its neighbors again */
  assert(num_neighbors(&graph, "donkey") == 3);

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
