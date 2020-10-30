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
#ifndef Edge
typedef struct edge {
  int cost;
  char *source;
  char *dest;
  struct edge *next;
} Edge;
#endif

/* Structure for vertex (point) */
#ifndef Vertex
typedef struct vertex {
  char *name;
  struct vertex *next;
} Vertex;
#endif

/* Structure for graph */
#ifndef WString_graph
typedef struct graph {
  int vertex_count;
  int edge_count;
  struct vertex **vertex_list;
  struct edge **edge_list;
} WString_graph;
#endif
