#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 16 (secret16.c)
 *
 * Tests that new_vertex_add() is making a copy of vertex names and not just
 * doing pointer aliasing.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* in the scope where an array is declared (and *only* in the scope where
 * it's declared), this expression will evaluate to the number of elements
 * in the array
 */
#define NUM_ELTS(arr) ((int) (sizeof(arr) / sizeof(arr[0])))

int main() {
  WString_graph graph;
  char vertex_name[20];
  char *vertices_to_add[]= {"koala", "parrot", "panda", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  int i;

  init_graph(&graph);

  /* add vertices; note the string vertex_name is overwritten each time */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++) {
    strcpy(vertex_name, vertices_to_add[i]);
    new_vertex_add(&graph, vertex_name);
  }

  /* now check the vertices */
  assert(num_vertices(&graph) == 8);
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++) {
    strcpy(vertex_name, vertices_to_add[i]);
    assert(is_existing_vertex(&graph, vertex_name));
  }

  printf("The assertions all worked!\n");

  return 0;
}
