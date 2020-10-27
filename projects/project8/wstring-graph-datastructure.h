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

typedef struct node {
  int vertex;
  struct node* next;
} Node;

typedef struct graph {
  int numVertices;
  struct node** adjLists;
} WString_graph;
