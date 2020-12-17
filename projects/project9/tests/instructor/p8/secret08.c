#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 8 (secret08.c)
 *
 * Creates multiple graphs, to ensure that their data doesn't conflict.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph1, graph2;
  char *vertices_to_add1[]= {"hedgehog", "koala", "panda"};
  /* yes, there really is such a thing as a Venezuelan poodle moth! */
  char *vertices_to_add2[]= {"orangutan", "jellyfish", "amoeba", "unicorn",
                             "Venezuelan poodle moth"};
  int i, size1= sizeof(vertices_to_add1) / sizeof(vertices_to_add1[0]),
      size2= sizeof(vertices_to_add2) / sizeof(vertices_to_add2[0]);

  init_graph(&graph1);
  init_graph(&graph2);

  /* add some vertices to the first graph */
  for (i= 0; i < size1; i++)
    new_vertex_add(&graph1, vertices_to_add1[i]);

  /* add some vertices to the second graph */
  for (i= 0; i < size2; i++)
    new_vertex_add(&graph2, vertices_to_add2[i]);

  /* add some edges to the first graph */
  add_edge(&graph1, "hedgehog", "koala", 2);
  add_edge(&graph1, "hedgehog", "panda", 3);
  add_edge(&graph1, "koala", "hedgehog", 4);
  add_edge(&graph1, "koala", "panda", 5);
  add_edge(&graph1, "panda", "hedgehog", 6);
  add_edge(&graph1, "panda", "koala", 7);

  /* add some edges to the second graph */
  for (i= 0; i < size2; i++)
    add_edge(&graph2, vertices_to_add2[i], vertices_to_add2[(i + 2) % size2],
             i + 2);

  /* check the results */
  for (i= 0; i < size1; i++)
    assert(num_neighbors(&graph1, vertices_to_add1[i]) == 2);

  for (i= 0; i < size2; i++)
    assert(num_neighbors(&graph2, vertices_to_add2[i]) == 1);

  printf("The assertions all worked!\n");

  return 0;
}
