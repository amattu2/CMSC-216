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

/**
 * This project implements singly linked lists,
 * and dynamically allocated arrays to store
 * the Verticies and Edges within verticies.
 *
 * The purpose of this project is to:
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
static int compare_chars(const void *a, const void *b);

/* Initialize the graph structure */
void init_graph(WString_graph *const graph) {
  /* Variables */
  struct graph *g;

  /* Checks */
  if (!graph)
    return;
  if ((g = malloc(sizeof(struct graph) + sizeof(struct edge*) + sizeof(struct vertex*) + (sizeof(int) * 2)))) {
    *graph = *g;
    graph->vertex_count = 0;
    graph->edge_count = 0;
    graph->vertex_list = malloc(sizeof(struct vertex*));
    graph->edge_list = malloc(sizeof(struct edge*));
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
  struct vertex *vertex = NULL;
  struct vertex *current = NULL;
  char *name;

  /* Checks */
  if (!graph || !new_vertex || is_existing_vertex(graph, new_vertex))
    return 0;
  else
    current = find_vertex_tail(graph);

  /* Create name pointer */
  if ((name = malloc(strlen(new_vertex) + 1)))
    strcpy(name, (new_vertex ? new_vertex : ""));
  else
    return 0;

  /* Create vertex pointer */
  if (!(graph->vertex_list = realloc(graph->vertex_list, (graph->vertex_count + 1) * sizeof(struct vertex*))))
    return 0;
  if ((vertex = malloc(sizeof(struct vertex) + sizeof(struct vertex*) + sizeof(char*)))) {
    vertex->next = NULL;
    vertex->name = name;
  } else
    return 0;

  /* Attach to existing node */
  if (current != NULL)
    current->next = vertex;

  /* Default */
  graph->vertex_list[graph->vertex_count] = vertex;
  graph->vertex_count++;
  return 1;
}

/* Create a new graph edge */
int add_edge(WString_graph *const graph, const char source[], const char dest[], int cost) {
  /* Variables */
  struct edge *edge = find_existing_edge(graph, source, dest);
  struct edge *current = find_edge_tail(graph);
  struct vertex *source_vertex;
  struct vertex *dest_vertex;
  char *source_ptr;
  char *dest_ptr;

  /* Checks */
  if (!graph || cost < 0)
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
  if (!(graph->edge_list = realloc(graph->edge_list, (graph->edge_count + 1) * sizeof(struct edge*))))
    return 0;
  if ((edge = malloc(sizeof(struct edge) + sizeof(int) + (sizeof(char*) * 2) + sizeof(struct edge*)))) {
    edge->cost = cost;
    edge->source = source_ptr;
    edge->dest = dest_ptr;
    edge->next = NULL;
  }

  /* Attach to existing node */
  if (current != NULL)
    current->next = edge;

  /* Return */
  graph->edge_list[graph->edge_count] = edge;
  graph->edge_count++;
  return 1;
}

/* Get array of verticies alphabetically ordered */
char **get_vertices(const WString_graph *const graph) {
  /* Variables */
  char **verticies = NULL;
  int index;
  int array_size = graph->vertex_count + 1; /* Space for NULL */

  /* Checks */
  if (!graph || !graph->vertex_list || !graph->vertex_count)
    return 0;
  if (!(verticies = realloc(verticies, (array_size) * sizeof(char*))))
    return 0;

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    /* Variables */
    char *name = NULL;

    /* Checks */
    if ((name = malloc(sizeof(char))))
      strcpy(name, graph->vertex_list[index]->name);
    else
      return NULL;

    /* Append */
    verticies[index] = name;
  }

  /* Sort Array */
  qsort(verticies, array_size, sizeof(char*), compare_chars);
  verticies[array_size] = NULL; /* Null terminator */

  /* Return */
  return verticies;
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
    if (strcmp(graph->edge_list[index]->source, vertex) == 0)
      count++;
  }

  /* Return */
  return count;
}

/* Find tail node of verticies */
static Vertex *find_vertex_tail(const WString_graph *const graph) {
  /* Checks */
  if (!graph || !graph->vertex_list || !graph->vertex_count)
    return NULL;

  /* Return */
  return graph->vertex_list[graph->vertex_count - 1]; /* Zero indexed */
}

/* Find tail node of edges */
static Edge *find_edge_tail(const WString_graph *const graph) {
  /* Checks */
  if (!graph || !graph->edge_list || !graph->edge_count)
    return NULL;

  /* Return */
  return graph->edge_list[graph->edge_count - 1]; /* Zero indexed */
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
    if (strcmp(graph->vertex_list[index]->name, name) == 0)
      return graph->vertex_list[index];
  }

  /* Default */
  return NULL;
}

/* Compare to characters */
static int compare_chars(const void *a, const void *b) {
  return *(char*) a - *(char*) b;
}
