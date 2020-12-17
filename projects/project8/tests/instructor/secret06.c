#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #8
 * Secret test 6 (secret06.c)
 *
 * Creates a larger graph with a number of vertices and edges.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_VERTICES 30

static int count_row(const int arr[][NUM_VERTICES], int row);

static int count_row(const int arr[][NUM_VERTICES], int row) {
  int i, sum= 0;

  for (i= 0; i < NUM_VERTICES; i++)
    sum += (arr[row][i] != 0);

  return sum;
}

int main() {
  WString_graph graph;
  char *vertices_to_add[NUM_VERTICES]= {
    "koala", "panda", "snake", "salamander", "gecko", "frog", "dog",
    "hedgehog", "bonobo", "chipmunk", "moose", "mongoose", "nematode",
    "bandicoot", "anteater", "opossum", "sheep", "yak", "tamarin", "antelope",
    "dolphin", "bluebird", "robin", "oriole", "cricket", "turtle", "emu",
    "ostrich", "goat", "horse"
  };
  /* element [i][j] in this array will be the value of the edge that we'll
   * add going from vertex i to vertex j, unless the element is 0, in which
   * case there won't be an edge
   */
  const int edges[NUM_VERTICES][NUM_VERTICES]= {
    { 0, 45,  0,  0,  0, 33, 69, 83,  9,  0, 47, 97, 69, 98, 18,
      8,  0, 70,  0, 91, 24,  6,  0,  0, 28, 33, 13, 77, 66,  0},
    {67,  0, 12, 28, 44, 63,  9, 83, 24, 65,  0,  0, 47, 21,  0,
     93,  5,  3, 60,  0,  6,  0, 60,  0, 85,  0, 85, 52, 36,  0},
    { 0,  0,  0, 98,  2, 92, 96,  0, 26,  0, 98, 99,  0, 18, 85,
      63,  0,  2, 98, 56,  0, 21, 37,  0, 33, 73,  1, 55,  0, 29},
    {14, 16, 55,  0, 88, 74,  0, 58, 86,  0, 40,  0, 70,  0, 28,
     12,  0, 48, 18,  0, 63, 85,  0, 70, 61,  0, 74, 43,  0,  0},
    { 4, 40,  0, 19, 55, 77,  4,  0, 65,  4, 82, 25, 95,  0,  1,
      0,  0,  0,  0,  0,  0, 58, 93, 13,  0, 17,  0, 65,  0, 42},
    {76, 15, 65,  0,  0,  0, 64, 53, 90,  1, 51,  0, 11, 46,  0,
     1,  0,  0,  0, 70,  0, 74, 44, 54, 81, 82, 24,  2, 75, 23},
    { 0, 61, 61, 96, 21, 52, 29,  0, 93,  0, 21,  0,  0, 66, 18,
      0, 47, 22,  3, 51,  0, 72, 60, 82, 35, 11, 32, 54, 17,  6},
    { 0,  0, 22, 50,  0, 66,  0, 19,  0, 76,  0, 18, 79, 74, 51,
      0, 82, 33, 57, 90,  0,  0, 11,  0,  0, 14, 55, 60,  0,  7},
    {50, 44,  0, 27,  0, 86, 36, 84,  0, 47, 44,  0, 42, 88, 28,
     0, 82, 26, 21, 81, 23, 43, 63,  2, 59,  0,  0, 16, 43,  0},
    { 0,  0, 10, 39, 39, 85, 12,  2,  0,  0, 59,  0, 49,  0, 36,
      0, 69, 61, 10, 85, 97, 66, 70, 71, 99, 56,  0, 60,  0,  0},
    { 3,  9, 30, 87,  0,  0, 61,  0, 37,  0, 40, 63, 40, 98,  1,
      20, 73,  0,  0, 60, 62,  0, 87, 23,  0, 38, 27,  0, 70,  0},
    {10,  0, 57,  0, 99, 95,  6, 34, 92, 50, 36,  4, 29, 75, 85,
     12, 32, 31, 47, 34, 48,  0, 50, 73, 80,  0,  0, 58, 97,  0},
    { 0,  0, 65,  4, 63, 12, 85,  0, 24, 76, 27, 61, 80, 99,  0,
      0, 92, 93, 61,  0,  0,  0,  7,  0, 45, 97,  0, 71, 13,  0},
    { 9, 87, 84,  4,  0,  4, 75, 18, 77,  9,  0, 22, 25, 24, 78,
      50, 32, 99, 43,  0,  0, 25, 47, 18, 23,  0,  0,  0, 19,  0},
    {48, 58, 29, 77,  0,  0, 13, 25, 85, 35,  8, 72, 14, 74,  0,
     56,  0, 31, 34,  4, 48,  0, 28, 47, 72, 63,  0, 60,  6, 94},
    { 0,  0,  0, 60, 35,  0, 86, 74,  0,  2, 71, 75, 29, 45, 39,
      68, 90,  0, 69,  5,  0,  0,  6, 23, 58, 16, 98,  0, 51, 79},
    {59, 19,  0, 26,  0,  0, 26, 37, 78,  0,  0,  2, 84, 62,  0,
     75,  0,  9, 25,  0,  5,  0,  2, 14,  0, 66,  0, 88, 43, 17},
    { 0, 78, 46,  0, 23, 22,  0, 45, 17, 30,  0, 19, 42,  0, 45,
      0,  7,  0, 42, 39, 59, 45,  0, 26,  0, 41, 31, 13, 98, 38},
    { 0,  0, 60, 26,  0,  0, 61,  0, 10, 68, 96,  7,  0, 72, 30,
      23,  0,  0, 33, 59, 72, 62, 79, 91, 80, 83, 36, 47, 57,  9},
    {76, 46, 34, 34,  0,  0,  0, 99,  0, 43, 94, 45, 82,  0, 65,
     71, 77,  0, 30, 47, 31, 97, 89,  1, 73,  0, 26, 83,  0,  0},
    { 0, 99, 44,  0, 42,  0,  0,  0, 19,  0,  0, 41,  0, 12,  0,
      72,  0, 80, 15,  0,  0, 42, 54,  0, 44,  0,  0, 36, 97, 50},
    { 0,  0, 32, 48,  8,  0, 21,  0,  0, 13, 28, 70, 50,  0, 53,
      0, 82, 80, 85, 24, 64,  0,  0, 61, 12, 85, 33,  0,  0, 72},
    {40, 32,  0, 99, 45, 14,  0, 13, 59,  0, 42, 68,  0, 14, 86,
     41, 99,  0,  0,  0, 55,  0, 16, 75,  0,  0, 71, 42, 12, 43},
    {63,  6, 21, 85, 52, 97,  0, 37, 88, 40,  0, 85,  2,  0,  0,
     78,  2,  0,  0,  0, 68, 82,  0, 69,  0, 26,  0,  0, 29, 33},
    {46,  5,  0,  0, 89, 57,  0, 82, 85,  0,  7, 79, 25, 63, 80,
     0, 87, 44,  0, 38, 57,  0, 89,  0, 75, 45,  0, 98,  0, 34},
    {23, 73, 73,  0, 19, 87, 80, 32, 23, 22,  0, 92,  0,  0,  0,
     72, 72,  2, 48, 87, 42,  0,  0,  0,  0, 72,  0, 74, 71, 46},
    {82,  5, 47, 27,  0, 33,  0, 37, 22,  3, 48, 71, 96,  0,  0,
     55, 19, 14,  0, 38, 31, 82, 12, 91, 60, 23, 44,  0, 88,  0},
    {71,  0, 39, 86, 26, 39,  0, 28, 33,  0, 14, 91,  0,  0, 95,
     35, 70, 67, 76, 13, 99,  0, 93, 79, 75, 40,  0,  0, 98,  0},
    {83,  0, 14, 33, 60,  0,  0,  0, 86, 61, 68,  0,  0, 18,  8,
     0, 24,  0, 32,  0, 69,  0, 49, 32,  0, 15,  0,  0, 22, 33},
    {42, 43, 59, 78, 19, 80,  0,  0, 96, 24, 93, 14, 36,  0, 73,
     1, 70,  0, 91,  0, 64,  0, 69, 59,  2,  0,  0,  0,  0, 48},
  };
  int i, j, size= sizeof(vertices_to_add) / sizeof(vertices_to_add[0]);

  init_graph(&graph);

  /* add the vertices */
  for (i= 0; i < size; i++)
    new_vertex_add(&graph, vertices_to_add[i]);

  /* add the edges */
  for (i= 0; i < NUM_VERTICES; i++)
    for (j= 0; j < NUM_VERTICES; j++)
      if (edges[i][j] != 0)
        add_edge(&graph, vertices_to_add[i], vertices_to_add[j], edges[i][j]);

  /* check the vertices */
  assert(num_vertices(&graph) == 30);

  for (i= 0; i < size; i++)
    assert(is_existing_vertex(&graph, vertices_to_add[i]));

  /* check the edges */
  for (i= 0; i < NUM_VERTICES; i++)
    for (j= 0; j < NUM_VERTICES; j++)
      if (edges[i][j] != 0)
        assert(get_weight_of_edge(&graph, vertices_to_add[i],
                                  vertices_to_add[j]) == edges[i][j]);
      else assert(get_weight_of_edge(&graph, vertices_to_add[i],
                                vertices_to_add[j]) == -1);

  /* check the number of neighbors of each vertex */
  for (i= 0; i < size; i++)
    assert(num_neighbors(&graph, vertices_to_add[i]) == count_row(edges, i));

  printf("The assertions all worked!\n");

  return 0;
}
