#include <stdio.h>
#include <string.h>  /* for the memset() function */
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 5 (secret05.c)
 *
 * Adds some vertices with very long names to a graph.  (You are likely to
 * fail this test if you are allocating the wrong amount of memory for
 * vertex names, since the test will write beyond the names and clobber
 * other data in the heap.)
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NAME_SZ 12345
#define NUM_VERTICES 20

int main() {
  WString_graph graph;
  char ch= '\0', name[NAME_SZ + 1], name2[NAME_SZ + 1];
  int i;

  init_graph(&graph);

  /* create 20 vertices with really long names */
  for (i= 0; i < NUM_VERTICES; i++) {
    /* fill vertex names with the characters 'A' for the first vertex, 'B'
       for the second one, etc. */
    memset(name, (ch++ + 'A'), NAME_SZ);
    name[NAME_SZ]= '\0';

    new_vertex_add(&graph, name);
  }

  assert(num_vertices(&graph) == NUM_VERTICES);

  /* add an edge from every vertex to the one with the next name, except for
   * the last one, which has an edge back to the first one
   */
  ch= '\0';
  for (i= 0; i < NUM_VERTICES; i++) {
    memset(name, ch + 'A', NAME_SZ);
    name[NAME_SZ]= '\0';

    ch= (ch + 1) % NUM_VERTICES;
    memset(name2, ch + 'A', NAME_SZ);
    name2[NAME_SZ]= '\0';

    assert(add_edge(&graph, name, name2, i * 3) == 1);
  }

  /* check the edges */
  ch= '\0';
  for (i= 0; i < NUM_VERTICES; i++) {
    memset(name, ch + 'A', NAME_SZ);
    name[NAME_SZ]= '\0';

    ch= (ch + 1) % NUM_VERTICES;
    memset(name2, ch + 'A', NAME_SZ);
    name2[NAME_SZ]= '\0';

    assert(num_neighbors(&graph, name) == 1);
    assert(get_weight_of_edge(&graph, name, name2) == i * 3);
  }

  printf("The assertions all worked!\n");

  return 0;
}
