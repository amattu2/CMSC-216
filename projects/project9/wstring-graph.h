/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

#if !defined(WSTRING_GRAPH_H)
#define WSTRING_GRAPH_H

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
/* new Project #9 functions */
void free_vertex_list(char **const names);
void destroy_graph(WString_graph *const graph);
int remove_edge(WString_graph *const graph, const char source[],
                const char dest[]);
int remove_vertex(WString_graph *const graph, const char vertex[]);
char **get_neighbors(const WString_graph *const graph, const char vertex[]);

/* in the scope where an array is declared (and *only* in the scope where
 * it's declared), this expression will evaluate to the number of elements
 * in the array
 */
#define NUM_ELTS(arr) ((int) (sizeof(arr) / sizeof(arr[0])))

#endif
