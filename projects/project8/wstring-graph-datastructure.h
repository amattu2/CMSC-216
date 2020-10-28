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
typedef struct edge {
  int source;
  int destination;
  int weight;
  struct edge *next;
} Edge;

/* Structure for vertex (point) */
typedef struct vertex {
  char *name;
  struct vertex *next;
  struct queue *edges;
} Vertex;

/* Structure for vertex edges */
typedef struct queue {
  int size;
  struct node *head;
} Queue;

/* Structure for graph */
typedef struct graph {
  int verticies;
  struct vertex **head;
} WString_graph;
