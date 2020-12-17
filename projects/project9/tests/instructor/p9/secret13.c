#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #9
 * Secret test 13 (secret13.c)
 *
 * Tests whether the conditional compilation directives in
 * wstring-graph-datastructure.h are using the correct preprocessor symbol
 * (which should be either WSTRING_GRAPH_DATASTRUCTURE_H, or using the Reek
 * text's naming convention, _WSTRING_GRAPH_DATASTRUCTURE_H).  It uses an
 * auxiliary program secret12a.c, which will not compile unless the
 * preprocessor symbol defined in wstring-graph-datastructure.h has one of
 * these two specific names.  (That program won't even need to be run; the
 * only question is whether it compiles or not.)
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  assert(!system("gcc -c secret13a.c"));
  
  printf("Everything worked perfectly!\n");

  return 0;
}
