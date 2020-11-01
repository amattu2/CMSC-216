/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 30th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Structure for edge (road) */
#ifndef edge_def
  #define edge_def
  typedef struct edge {
    int cost;
    char *dest;
    struct edge *next;
  } Edge;
#endif

/* Structure for vertex (point) */
#ifndef vertex_def
  #define vertex_def
  typedef struct vertex {
    int edge_count;
    char *name;
    struct vertex *next;
    struct edge **edge_list;
  } Vertex;
#endif

/* Structure for graph */
#ifndef graph_def
  #define graph_def
  typedef struct graph {
    int vertex_count;
    struct vertex **vertex_list;
  } WString_graph;
#endif
