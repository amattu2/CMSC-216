/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: November 5th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * This project is designed to:
 * - Implement dynamic memory
 * - Extend upon project 8 with a few extra functions
 * - Implement a makefile (Also extended from project 8)
 *
 * This project uses:
 * - Linked lists for edges
 * - Dynamic arrays for verticies
*/

/* Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wstring-graph.h"

/* Prototypes */
static Edge *find_edge_tail(const WString_graph *const graph,
                            const char source[]);
static Edge *find_existing_edge(const WString_graph *const graph,
                                const char source[], const char dest[]);
static Vertex *find_existing_vertex(const WString_graph *const graph,
                                    const char name[]);
static int compare_chars(const void *a, const void *b);

/* Initialize the graph structure */
void init_graph(WString_graph *const graph) {
  /* Variables */
  struct graph *g = NULL;

  /* Checks */
  if (!graph)
    return;
  if ((g = malloc(sizeof(struct graph) + sizeof(struct vertex*) +
                  (sizeof(int))))) {
    g->vertex_count = 0;
    g->vertex_array = malloc(sizeof(struct vertex*));
    *graph = *g;
  }
}

/* Destroy the graph structure */
void destroy_graph(WString_graph *const graph) {
  /* Variables */
  struct vertex *current_vertex = NULL;
  int index;

  /* Checks */
  if (!graph)
    return;

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    /* Variables */
    struct edge *current_edge = current_vertex->edge_head;
    current_vertex = graph->vertex_array[index];

    /* Loops */
    while (current_edge) {
      /* Variables */
      struct edge *temp = current_edge;
      current_edge = temp->next;

      /* Free Memory */
      free(temp->dest); /* TBD, not needed? */
      free(temp->next); /* TBD, not needed? */
      free(temp);
    }

    /* Free Memory */
    free(current_vertex->name);
    free(current_vertex->edge_head);
    free(current_vertex);
  }

  /* Free Memory */
  free(graph->vertex_array);
  free(graph);
}

/* Check if a vertex exists */
int is_existing_vertex(const WString_graph *const graph, const char name[]) {
  /* Variables */
  int index;

  /* Checks */
  if (!graph || !name)
    return 0;
  if (!graph->vertex_array || !graph->vertex_count)
    return 0;

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    if (strcmp(graph->vertex_array[index]->name, name) == 0)
      return 1;
  }

  /* Default */
  return 0;
}

/* Create a new graph vertex */
int new_vertex_add(WString_graph *const graph, const char new_vertex[]) {
  /* Variables */
  struct vertex *vertex = NULL;
  char *name;

  /* Checks */
  if (!graph || !new_vertex || is_existing_vertex(graph, new_vertex))
    return 0;

  /* Allocate new name */
  if ((name = malloc(strlen(new_vertex) + 1)))
    strcpy(name, (new_vertex ? new_vertex : ""));
  else return 0;

  /* Allocate space for new vertex pointer */
  if (!(graph->vertex_array = realloc(graph->vertex_array,
              (graph->vertex_count + 1) * sizeof(struct vertex*))))
    return 0;

  /* Allocate space for new vertex */
  if ((vertex = malloc(sizeof(struct vertex) + sizeof(int) +
                      sizeof(char*) + sizeof(struct edge*)))) {
    vertex->edge_count = 0;
    vertex->name = name;
    vertex->edge_head = NULL;
  } else return 0;

  /* Default */
  graph->vertex_array[graph->vertex_count] = vertex;
  graph->vertex_count++;
  return 1;
}

/* Create a new graph edge */
int add_edge(WString_graph *const graph, const char source[],
            const char dest[], int cost) {
  /* Variables */
  struct edge *edge = find_existing_edge(graph, source, dest);
  struct edge *current_tail = find_edge_tail(graph, source);
  struct vertex *source_vertex;
  struct vertex *dest_vertex;
  char *dest_ptr;

  /* Check Input */
  if (!graph || !source || !dest || cost < 0)
    return 0;
  if (edge) {
    edge->cost = cost;
    return 1;
  }

  /* Check Verticies */
  if (!is_existing_vertex(graph, source) && !new_vertex_add(graph, source))
    return 0;
  if (!is_existing_vertex(graph, dest) && !new_vertex_add(graph, dest))
    return 0;
  if (!(source_vertex = find_existing_vertex(graph, source)))
    return 0;
  if ((dest_vertex = find_existing_vertex(graph, dest)))
    dest_ptr = dest_vertex->name;

  /* Check Memory Allocation */
  if (!(edge = malloc(sizeof(struct edge) + sizeof(int) +
                      sizeof(char*) + sizeof(struct edge*))))
    return 0;

  /* Find insert spot */
  if (!current_tail)
    source_vertex->edge_head = edge;
  else current_tail->next = edge;

  /* Return */
  edge->cost = cost;
  edge->dest = dest_ptr;
  edge->next = NULL;
  source_vertex->edge_count++;
  return 1;
}

/* Get array of verticies alphabetically ordered */
char **get_vertices(const WString_graph *const graph) {
  /* Variables */
  char **verticies = NULL;
  int index;
  int array_size = graph->vertex_count + 1; /* Space for NULL */

  /* Checks */
  if (!(verticies = malloc((array_size) * sizeof(char*))))
    return NULL;
  if (!graph)
    return NULL;
  if (!graph->vertex_array) {
    verticies[array_size - 1] = NULL;
    return verticies;
  }

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    /* Variables */
    char *name = NULL;

    /* Checks */
    if ((name = malloc(strlen(graph->vertex_array[index]->name))))
      strcpy(name, graph->vertex_array[index]->name);
    else return NULL;

    /* Append */
    verticies[index] = name;
  }

  /* Sort Array */
  qsort(verticies, array_size-1, sizeof(char*), compare_chars);
  verticies[array_size - 1] = NULL; /* Null terminator */

  /* Return */
  return verticies;
}

char **get_neighbors(const WString_graph *const graph, const char vertex[]) {
  /* Checks */
  if (!graph || !vertex)
    return NULL;
  if (!is_existing_vertex(graph, vertex))
    return NULL;

  exit(1);

  return NULL;
}

/* Return weight of given edge */
int get_weight_of_edge(const WString_graph *const graph,
                      const char source[], const char dest[]) {
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
  struct vertex *v = find_existing_vertex(graph, vertex);

  /* Checks */
  if (!graph || !v || !vertex)
    return -1;
  if (!v->edge_count || !v->edge_head)
    return 0;

  /* Return */
  return v->edge_count;
}

int remove_edge(WString_graph *const graph, const char source[],
                const char dest[]) {
  /* Variables */
  struct edge *edge = find_existing_edge(graph, source, dest);

  /* Checks */
  if (!graph || !source || !dest)
    return 0;
  if (!is_existing_vertex(graph, source))
    return 0;
  if (!is_existing_vertex(graph, dest))
    return 0;
  if (!edge)
    return 0;

  exit(1);
  /* Remove edge, and any references to it */
  /* Free memory */
  /* It's a linked list, so handle the removal properly */

  return 0;
}

int remove_vertex(WString_graph *const graph, const char vertex[]) {
  /* Checks */
  if (!graph || !vertex)
    return 0;
  if (!is_existing_vertex(graph, vertex))
    return 0;

  exit(1);
  /* Remove all edges attached (ongoing/incoming) */
  /* Remove vertex and all references to it (char struct pointer) */

  /* Default */
  return 1;
}

/* Free a array of strings */
void free_vertex_list(char **const names) {
  /* Variables */
  char *current = NULL;
  int index = 0;

  /* Checks */
  if (!names)
    return;
  else current = names[0];

  /* Loops */
  while (current != NULL) {
    free(current);
    current = names[++index];
  }
}

/* Find tail node of edges */
static Edge *find_edge_tail(const WString_graph *const graph,
                            char const source[]) {
  /* Variables */
  struct vertex *vertex = find_existing_vertex(graph, source);
  struct edge *current = NULL;

  /* Checks */
  if (!graph || !vertex || !vertex->edge_head)
    return NULL;
  else current = vertex->edge_head;

  /* Loops */
  while (current && current->next)
    current = current->next;

  /* Return */
  return current;
}

/* Find edge if it exists */
static Edge *find_existing_edge(const WString_graph *const graph,
                                const char source[], const char dest[]) {
  /* Variables */
  struct vertex *vertex = find_existing_vertex(graph, source);
  struct edge *current = NULL;

  /* Checks */
  if (!graph || !vertex || !vertex->edge_head)
    return NULL;
  else current = vertex->edge_head;

  /* Loops */
  while (current != NULL) {
    if (strcmp(current->dest, dest) == 0)
      return current;
    else current = current->next;
  }

  /* Default */
  return NULL;
}

/* Find vertex if it exists */
static Vertex *find_existing_vertex(const WString_graph *const graph,
                                    const char name[]) {
  /* Variables */
  int index;

  /* Checks */
  if (!is_existing_vertex(graph, name))
    return NULL;
  if (!graph || !graph->vertex_array || !graph->vertex_count)
    return NULL;

  /* Loops */
  for (index = 0; index < graph->vertex_count; index++) {
    if (strcmp(graph->vertex_array[index]->name, name) == 0)
      return graph->vertex_array[index];
  }

  /* Default */
  return NULL;
}

/* Compare to characters */
static int compare_chars(const void *a, const void *b) {
  return strcmp(*(char**) a, *(char**) b);
}
