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

int add_edge(WString_graph *const graph, const char source[], const char dest[], int cost) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
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

int get_weight_of_edge(const WString_graph *const graph, const char source[], const char dest[]) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

/* Return vertex count */
int num_vertices(const WString_graph *const graph) {
  /* Checks */
  if (!graph || !graph->vertex_count || graph->vertex_count <= 0)
    return 0;

  /* Return */
  return graph->vertex_count;
}

int num_neighbors(const WString_graph *const graph, const char vertex[]) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
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
