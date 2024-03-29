#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Public test 1 (public01.c)
 *
 * Tests calling free_vertex_list() on an array of dynamically allocated
 * strings, and calling destroy_graph().  This test does not check for memory
 * leaks or correctness of the heap; it is only testing the correct behavior
 * of these functions.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *some_strings[]= {"koala", "giraffe", "parrot", "zebra", "hedgehog",
                         "hippopotamus", "rhinoceros", "dog", "frog"};
  char **animals;
  int i;

  init_graph(&graph);

  /* first check free_vertex_list() */

  /* some_strings is not dynamically allocated so we can't call
   * free_vertex_list() on it; we will make a dynamically allocated copy of
   * what's in it to test the function with
   */
  animals= calloc(1 + NUM_ELTS(some_strings), sizeof(*animals));

  if (animals != NULL) {
    for (i= 0; i < NUM_ELTS(some_strings); i++) {
      animals[i]= malloc(strlen(some_strings[i]) + 1);
      if (animals[i] != NULL)
        strcpy(animals[i], some_strings[i]);
    }

    /* ensure the last element is NULL */
    animals[i]= NULL;

    /* now release everything that was allocated */
    free_vertex_list(animals);
  }

  /* next check destroy_graph(), using those same strings to create vertices
     in the graph */

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(some_strings); i++)
    new_vertex_add(&graph, some_strings[i]);

  /* check that the vertices were all added */
  assert(num_vertices(&graph) == NUM_ELTS(some_strings));

  /* now trash the whole thing */
  destroy_graph(&graph);

  /* note that it's not valid to call num_vertices()- or any other
     functions- on the graph at this point, not unless init_graph() is
     called on it first, which we will skip doing because here we just care
     about memory leaks and correctness of the heap */

  printf("Everything worked perfectly!\n");

  return 0;
}
