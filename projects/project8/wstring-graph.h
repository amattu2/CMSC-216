/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

#include "wstring-graph-datastructure.h"

void init_graph(WString_graph *const graph);
int new_vertex_add(WString_graph *const graph, const char new_vertex[]);
int num_vertices(const WString_graph *const graph);
int is_existing_vertex(const WString_graph *const graph, const char name[]);
char **get_vertices(const WString_graph *const graph);
int add_edge(WString_graph *const graph, const char source[],
             const char dest[], int cost);
int get_weight_of_edge(const WString_graph *const graph, const char source[],
                     const char dest[]);
int num_neighbors(const WString_graph *const graph, const char vertex[]);
