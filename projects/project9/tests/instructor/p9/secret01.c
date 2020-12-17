#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "wstring-graph.h"

/* CMSC 216, Fall 2020, Project #9
 * Secret test 1 (secret01.c)
 *
 * Tests calling free_vertex_list() on an empty array with no vertex names
 * (its parameter is the address of a valid one-element array, whose single
 * element is just NULL).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  char **names;

  names= malloc(sizeof(*names));
  assert(names != NULL);  /* ensures that memory allocation succeeded */
  names[0]= NULL;

  free_vertex_list(names);

  printf("Everything worked perfectly!\n");

  return 0;
}
