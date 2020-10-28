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
#include "wstring-graph.h"
#include "graph-utils.h"

/* Initialize the graph structure */
void init_graph(WString_graph *const graph) {
  /* Variables */
  WString_graph *g;

  /* Checks */
  if (!graph)
    return;
  if ((g = malloc(sizeof(int) + sizeof(int) + sizeof(Vertex)))) {
    g->head = NULL;
    g->verticies = 0;
    g->edges = 0;
    *graph = *g;
  }
}

int is_existing_vertex(const WString_graph *const graph, const char name[]) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

int new_vertex_add(WString_graph *const graph, const char new_vertex[]) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

int add_edge(WString_graph *const graph, const char source[], const char dest[], int cost) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

char **get_vertices(const WString_graph *const graph) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

int get_weight_of_edge(const WString_graph *const graph, const char source[], const char dest[]) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

int num_vertices(const WString_graph *const graph) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}

int num_neighbors(const WString_graph *const graph, const char vertex[]) {
  /* Checks */
  if (!graph)
    return 0;

  return 0;
}
