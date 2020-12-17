#include <stdio.h>
#include <assert.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 14 (secret14.c)
 *
 * Tests calling the functions passing NULL into all WString_graph pointer
 * parameters.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  WString_graph graph;
  char *vertices_to_add[]= {"orangutan", "jellyfish", "amoeba", "unicorn",
                            "Indian purple frog"};
  int i, j;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    for (j= 0; j < NUM_ELTS(vertices_to_add); j++)
      add_edge(&graph, vertices_to_add[i], vertices_to_add[j], (i * 10) + j);

  /* pass NULL into all WString_graph * parameters */
  init_graph(NULL);
  assert(new_vertex_add(NULL, "tarantula") == 0);
  assert(add_edge(NULL, "blobfish", "pelican", 2) == 0);
  assert(remove_edge(NULL, "jellyfish", "Indian purple frog") == 0);
  assert(remove_vertex(NULL, "orangutan") == 0);

  /* check that nothing in the graph changed */
  assert(num_vertices(&graph) == 5);

  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    assert(is_existing_vertex(&graph, vertices_to_add[i]));

  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    for (j= 0; j < NUM_ELTS(vertices_to_add); j++)
      assert(get_weight_of_edge(&graph, vertices_to_add[i],
                                 vertices_to_add[j]) == (i * 10) + j);

  /* now clean up after ourselves */
  free_vertex_list(NULL);  /* should just have no effect */
  destroy_graph(NULL);     /* faked you out */
  destroy_graph(&graph);   /* OK, now we really mean it */

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
