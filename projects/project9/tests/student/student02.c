#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

/**
 * Add edges to graph
 * Remove edges in weird positions
 */

int main() {
  WString_graph graph;
  char *vertices_to_add[]= {"koala", "quokka", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  char *vertices_to_add2[]= {"koala", "quokka", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  int i;

  init_graph(&graph);

  /* Add Edges */
  assert(add_edge(&graph, "one", "two", 1) == 1);
  assert(add_edge(&graph, "two", "one", 2) == 1);
  assert(add_edge(&graph, "three", "four", 3) == 1);
  assert(add_edge(&graph, "four", "three", 4) == 1);
  assert(add_edge(&graph, "four", "five", 1) == 1);

  /* Remove 2nd one */
  assert(remove_edge(&graph, "two", "one") == 1);

  /* Remove Last one */
  assert(remove_edge(&graph, "four", "five") == 1);

  /* Remove first one */
  assert(remove_edge(&graph, "one", "two") == 1);

  /* Remove first one (non-existent) */
  assert(remove_edge(&graph, "one", "two") == 0);

  printf("Pass!\n");

  return 0;
}
