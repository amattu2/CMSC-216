#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 2 (secret02.c)
 *
 * Tests that vertex names are being correctly compared when edges are
 * added, and looked up using get_weight_of_edge().  This also tests calling
 * add_edge() and get_weight_of_edge() with nonexistent source and destination
 * vertices.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i, j, size= sizeof(vertices_to_add) / sizeof(vertices_to_add[0]);

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < size; i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      add_edge(&graph, vertices_to_add[i], vertices_to_add[j], (i * 10) + j);

  /* these are not names of existing vertices */
  assert(get_weight_of_edge(&graph, "Caterpillar", "porcupine") == -1);
  assert(get_weight_of_edge(&graph, "porcupine", "Caterpillar") == -1);
  assert(get_weight_of_edge(&graph, "ELEPHANT", "caterpillar") == -1);
  assert(get_weight_of_edge(&graph, "caterpillar", "ELEPHANT") == -1);
  assert(get_weight_of_edge(&graph, "cat", "ant") == -1);
  assert(get_weight_of_edge(&graph, "ant", "cat") == -1);
  assert(get_weight_of_edge(&graph, "cup", "cat") == -1);
  assert(get_weight_of_edge(&graph, "cat", "cup") == -1);

  for (i= 0; i < size; i++)
    for (j= 0; j < size; j++)
      assert(get_weight_of_edge(&graph, vertices_to_add[i],
                                vertices_to_add[j]) == (i * 10) + j);

  printf("The assertions all worked!\n");

  return 0;
}
