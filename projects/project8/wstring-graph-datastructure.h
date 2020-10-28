/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 28th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Structure for edge (road) */
#ifndef Edge
typedef struct edge {
  int weight;
  struct vertex *source;
  struct vertex *destination;
  struct edge *next;
} Edge;
#endif

/* Structure for vertex (point) */
#ifndef Vertex
typedef struct vertex {
  char *name;
  struct vertex *next;
  struct queue *edges;
} Vertex;
#endif

/* Structure for graph */
#ifndef WString_graph
typedef struct graph {
  int vertex_count;
  int edge_count;
  struct vertex **vertex_head;
  struct edge **edge_head;
} WString_graph;
#endif
