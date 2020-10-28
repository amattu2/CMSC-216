/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 27th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Simulate a graph storage system
 * - Manipulate a given graph
 * - Use dynamic memory allocation
*/

/* Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wstring-graph.h"
#include "graph-utils.h"

/* Prototypes */
static Vertex *find_vertex_tail(const WString_graph *const graph);
static Edge *find_edge_tail(const WString_graph *const graph);
static Edge *find_existing_edge(const WString_graph *const graph, const char source[], const char dest[]);
static Vertex *find_existing_vertex(const WString_graph *const graph, const char name[]);

/* Initialize the graph structure */
void init_graph(WString_graph *const graph) {
  /* Variables */
  WString_graph *g;

  /* Checks */
  if (!graph)
    return;
  if ((g = malloc(sizeof(int) + sizeof(int) + sizeof(NULL) + sizeof(NULL)))) {
    g->vertex_count = 0;
    g->edge_count = 0;
    g->vertex_head = NULL;
    g->edge_head = NULL;
    *graph = *g;
  }
}

/* Check if a vertex exists */
int is_existing_vertex(const WString_graph *const graph, const char name[]) {
  /* Variables */
  Vertex *current = NULL;

  /* Checks */
  if (!graph || !graph->vertex_head)
    return 0;
  else
    current = *graph->vertex_head;

  /* Loops */
  while (current && current->next != current) {
    if (strcmp(current->name, name) == 0)
      return 1;

    current = current->next;
  }

  /* Default */
  return 0;
}

/* Create a new graph vertex */
int new_vertex_add(WString_graph *const graph, const char new_vertex[]) {
  /* Variables */
  Vertex *vertex;
  Vertex *current = NULL;
  char *name;

  /* Checks */
  if (!graph || is_existing_vertex(graph, new_vertex))
    return 0;
  else
    current = find_vertex_tail(graph);

  /* Create name pointer */
  if ((name = malloc(strlen(new_vertex) + 1)))
      strcpy(name, (new_vertex ? new_vertex : ""));
  else
    return 0;

  /* Create vertex pointer */
  if ((vertex = malloc(sizeof(Vertex)))) {
    vertex->next = NULL;
    vertex->name = name;
  } else
    return 0;

  /* Find insert location */
  if (current == NULL)
    *graph->vertex_head = vertex;
  else
    current->next = vertex;

  /* Default */
  graph->vertex_count++;
  return 1;
}

/* Create a new graph edge */
int add_edge(WString_graph *const graph, const char source[], const char dest[], int cost) {
  /* Variables */
  Edge *edge = find_existing_edge(graph, source, dest);
  Edge *current = find_edge_tail(graph);
  char *source_ptr;
  char *dest_ptr;
  Vertex *source_vertex;
  Vertex *dest_vertex;

  /* Checks */
  if (!graph)
    return 0;
  if (cost < 0)
    return 0;
  if (edge) {
    edge->cost = cost;
    return 1;
  }

  /* Create verticies */
  if (!is_existing_vertex(graph, source))
    new_vertex_add(graph, source);
  if (!is_existing_vertex(graph, dest))
    new_vertex_add(graph, dest);

  /* Assign name pointers */
  if ((source_vertex = find_existing_vertex(graph, source)))
    source_ptr = source_vertex->name;
  if ((dest_vertex = find_existing_vertex(graph, dest)))
    dest_ptr = dest_vertex->name;

  /* Allocate edge memory */
  if ((edge = malloc(sizeof(int)))) {
    edge->source = source_ptr;
    edge->dest = dest_ptr;
    edge->cost = cost;
  }

  /* Find insert location */
  if (!current)
    *graph->edge_head = edge;
  else
    current->next = edge;

  /* Increment internal tracker for size */
  graph->edge_count++;
  return 1;
}

char **get_vertices(const WString_graph *const graph) {
  /* Variables */
  Vertex *current = NULL;

  /* Checks */
  if (!graph || !graph->vertex_head)
    return 0;
  else
    current = *graph->vertex_head;

  /* Iterate */
  while (current && current->next != current) {

  }

  /* Return */
  return NULL;
}

/* Return weight of given edge */
int get_weight_of_edge(const WString_graph *const graph, const char source[], const char dest[]) {
  /* Variables */
  Edge *edge = find_existing_edge(graph, source, dest);

  /* Checks */
  if (!graph || !edge)
    return -1;
  if (!source || !dest)
    return -1;

  /* Return */
  return edge->cost;
}

/* Return vertex count */
int num_vertices(const WString_graph *const graph) {
  /* Checks */
  if (!graph || !graph->vertex_count || graph->vertex_count <= 0)
    return 0;

  /* Return */
  return graph->vertex_count;
}

/* Determine the neighbor count of a vertex */
int num_neighbors(const WString_graph *const graph, const char vertex[]) {
  /* Variables */
  int count = 0;
  Edge *current = NULL;

  /* Checks */
  if (!graph || !vertex)
    return -1;
  else
    current = *graph->edge_head;

  /* Loops */
  while (current && current->next != current) {
    /* Checks */
    if (strcmp(current->source, vertex) == 0)
      count++;
    if (strcmp(current->dest, vertex) == 0)
      count++; /* a V can be it's own neighbor.. source=dest=vertex */

    current = current->next;
  }

  /* Return */
  return count;
}

/* Find tail node of verticies */
static Vertex *find_vertex_tail(const WString_graph *const graph) {
  /* Variables */
  Vertex *current = NULL;

  /* Checks */
  if (!graph || !graph->vertex_head)
    return current;
  else
    current = *graph->vertex_head;

  /* Loops */
  while (current && current->next != current) {
    current = current->next;
  }

  /* Default */
  return current;
}

/* Find edge if it exists */
static Edge *find_existing_edge(const WString_graph *const graph, const char source[], const char dest[]) {
  /* Variables */
  Edge *current = NULL;

  /* Checks */
  if (!graph || !graph->edge_head)
    return current;
  else
    current = *graph->edge_head;

  /* Loops */
  while (current && current->next != current) {
    /* Variables */
    int matches = 1;

    /* Checks */
    if (strcmp(current->source, source) != 0)
      matches = 0;
    if (strcmp(current->dest, dest) != 0)
      matches = 0;
    if (matches)
      return current;

    current = current->next;
  }

  /* Default */
  return current;
}

/* Find tail node of edges */
static Edge *find_edge_tail(const WString_graph *const graph) {
  /* Variables */
  Edge *current = NULL;

  /* Checks */
  if (!graph || !graph->edge_head)
    return current;
  else
    current = *graph->edge_head;

  /* Loops */
  while (current && current->next != current) {
    current = current->next;
  }

  /* Default */
  return current;
}

/* Find vertex if it exists */
static Vertex *find_existing_vertex(const WString_graph *const graph, const char name[]) {
  /* Variables */
  Vertex *current = NULL;

  /* Checks */
  if (!is_existing_vertex(graph, name)) {
    return current;
  }
  if (!graph || !graph->vertex_head)
    return current;
  else
    current = *graph->vertex_head;

  /* Loops */
  while (current && current->next != current) {
    if (strcmp(current->name, name) == 0)
      return current;

    current = current->next;
  }

  /* Default */
  return current;
}
