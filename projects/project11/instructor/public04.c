#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 4 (public04.c)
 *
 * Tests the basic operation of num_dependencies() and get_dependency().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public04.forkfile");
  const char *targets[]= {"main.x", "functions.o", "main.o", "linesize.x",
                          "clean"};
  int expected_num_dependencies[]= {4, 2, 2, 1, 0};
  const char *expected_dependency_names[]= {
    "main.o", "functions.o", "memory-checking.o", "safe-fork.o",
    "functions.c", "functions.h",
    "main.c", "functions.h",
    "linesize.c"
  };
  int i, j, pos= 0;

  for (i= 0; i < (int) (sizeof(targets) / sizeof(targets[0])); i++) {
    assert(num_dependencies(forkfile, i) == expected_num_dependencies[i]);
    for (j= 0; j < expected_num_dependencies[i]; j++)
      assert(strcmp(get_dependency(forkfile, i, j),
                    expected_dependency_names[pos++]) == 0);
  }

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
