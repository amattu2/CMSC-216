#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 11 (secret11.c)
 *
 * Tests that remove_vertex() removes the incoming edges to the vertex being
 * removed.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"snake", "salamander", "koala", "parrot",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *from[]= {"frog", "dog", "dog", "parrot", "parrot", "hedgehog",
                 "hedgehog", "hedgehog", "giraffe", "snake", "snake"};
  char *to[]= {"dog", "frog", "salamander", "frog", "salamander", "koala",
               "salamander", "snake", "snake", "salamander", "parrot"};
  char *expected_vertices[]= {"dog", "frog", "giraffe", "hedgehog", "koala",
                              "parrot", "snake", NULL};
  char *expected_neighbors[][4]= {
    {"frog", NULL},            /* neighbors of dog */
    {"dog", NULL},             /* neighbors of frog */
    {"snake", NULL},           /* neighbors of giraffe */
    {"koala", "snake", NULL},  /* neighbors of hedgehog */
    {NULL},                    /* neighbors of koala */
    {"frog", NULL},            /* neighbors of parrot */
    {"parrot", NULL},          /* neighbors of snake */
  };
  char **names, **neighbors;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], i);

  /* remove salamander, which has multiple incoming edges (but no outgoing
     edges) */
  assert(remove_vertex(&graph, "salamander"));

  /* now check the graph */
  assert(num_vertices(&graph) == NUM_ELTS(vertices_to_add) - 1);

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

  printf("Everything worked perfectly!\n");

  return 0;
}
