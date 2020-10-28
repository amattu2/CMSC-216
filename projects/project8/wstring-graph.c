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
  struct graph *g;

  /* Checks */
  if (!graph)
    return;
  if ((g = malloc(sizeof(struct graph)))) {
    *graph = *g;
    g->vertex_count = 0;
    g->edge_count = 0;
    g->vertex_list = malloc(sizeof(struct vertex*));
    g->edge_list = malloc(sizeof(struct edge*));
  }
}

/* Check if a vertex exists */
int is_existing_vertex(const WString_graph *const graph, const char name[]) {
  /* Variables */
  int index;

  /* Checks */
  if (!graph || !graph->vertex_list || !graph->vertex_count || !name)
    return 0;

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    if (strcmp(graph->vertex_list[index]->name, name) == 0)
      return 1;
  }

  /* Default */
  return 0;
}

/* Create a new graph vertex */
int new_vertex_add(WString_graph *const graph, const char new_vertex[]) {
  /* Variables */
  struct vertex *vertex;
  struct vertex *current = NULL;
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
  if ((graph->vertex_list = realloc(graph->vertex_list, sizeof(struct vertex*) * (graph->vertex_count+1)))) {
    vertex = malloc(sizeof(struct vertex*));
    vertex->next = NULL;
    vertex->name = name;
  } else
    return 0;

  /* Find insert location */
  if (current == NULL)
    graph->vertex_list[2] = vertex;
  else
    current->next = vertex;

  /* Default */
  graph->vertex_count++;
  return 1;
}

/* Create a new graph edge */
int add_edge(WString_graph *const graph, const char source[], const char dest[], int cost) {
  /* Variables */
  struct edge *edge = find_existing_edge(graph, source, dest);
  struct edge *current = find_edge_tail(graph);
  char *source_ptr;
  char *dest_ptr;
  struct vertex *source_vertex;
  struct vertex *dest_vertex;

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
  if ((edge = malloc(sizeof(struct edge)))) {
    edge->source = source_ptr;
    edge->dest = dest_ptr;
    edge->cost = cost;
    edge->next = NULL;
  }

  /* Find insert location */
  if (!current)
    graph->edge_list = &edge;
  else
    current->next = edge;

  /* Increment internal tracker for size */
  graph->edge_count++;
  return 1;
}

char **get_vertices(const WString_graph *const graph) {
  /* Variables */
  struct vertex *current = NULL;

  /* Checks */
  if (!graph || !graph->vertex_list)
    return 0;
  else
    current = *graph->vertex_list;

  /* Iterate */
  while (current && current->next != current) {
    exit(1); /* TDB */
  }

  /* Return */
  return NULL;
}

/* Return weight of given edge */
int get_weight_of_edge(const WString_graph *const graph, const char source[], const char dest[]) {
  /* Variables */
  struct edge *edge = find_existing_edge(graph, source, dest);

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
  int index;

  /* Checks */
  if (!graph || !vertex || !graph->edge_list)
    return -1;

  /* Loops */
  for (index = 0; index < graph->edge_count; index++) {
    /* Checks */
    if (strcmp((!graph->edge_list[index]->source ? "" : graph->edge_list[index]->source), vertex) == 0)
      count++;
    if (strcmp((!graph->edge_list[index]->dest ? "" : graph->edge_list[index]->dest), vertex) == 0)
      count++; /* a V can be it's own neighbor.. source=dest=vertex */
  }

  /* Return */
  return count;
}

/* Find tail node of verticies */
static Vertex *find_vertex_tail(const WString_graph *const graph) {
  /* Checks */
  if (!graph || !graph->vertex_list || !graph->vertex_count)
    return NULL;

  /* Default */
  return graph->vertex_list[graph->vertex_count];
}

/* Find tail node of edges */
static Edge *find_edge_tail(const WString_graph *const graph) {
  /* Checks */
  if (!graph || !graph->edge_list || !graph->edge_count)
    return NULL;

  /* Return */
  return graph->edge_list[graph->edge_count - 1];
}

/* Find edge if it exists */
static Edge *find_existing_edge(const WString_graph *const graph, const char source[], const char dest[]) {
  /* Variables */
  int index;

  /* Checks */
  if (!graph || !graph->edge_list || !graph->edge_count)
    return NULL;

  /* Loops */
  for (index = 0; index < graph->edge_count; index++) {
    /* Variables */
    struct edge *edge = graph->edge_list[index];

    /* Checks */
    if (strcmp(edge->source, source) == 0 && strcmp(edge->dest, dest) == 0)
      return edge;
  }

  /* Default */
  return NULL;
}

/* Find vertex if it exists */
static Vertex *find_existing_vertex(const WString_graph *const graph, const char name[]) {
  /* Variables */
  int index;

  /* Checks */
  if (!is_existing_vertex(graph, name)) {
    return NULL;
  }
  if (!graph || !graph->vertex_list || !graph->vertex_count)
    return NULL;

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    if (strcmp((!graph->vertex_list[index]->name ? "" : graph->vertex_list[index]->name), (!name ? "" : name)) == 0)
      return graph->vertex_list[index];
  }

  /* Default */
  return NULL;
}
