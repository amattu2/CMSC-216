#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #9
 * Secret test 12 (secret12.c)
 *
 * Tests whether conditional compilation directives are properly used in
 * wstring-graph-datastructure.h, using an auxiliary program secret12a.c,
 * which tries to include wstring-graph-datastructure.h twice.  If that
 * program does not compile (it won't even need to be run),
 * wstring-graph-datastructure.h must not be using conditional compilation
 * (or not using it correctly).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  assert(!system("gcc -c secret12a.c"));

  printf("Everything worked perfectly!\n");

  return 0;
}
