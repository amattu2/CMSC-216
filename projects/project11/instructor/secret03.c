#include <stdio.h>
#include <assert.h>
#include "forkfile.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 3 (secret03.c)
 *
 * Tests calling is_older() when one or both files don't exist.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  /* we know that secret03 exists, because we are it */
  assert(is_older("secret03.c", "non-existent-file") == 0);
  assert(is_older("non-existent-file", "secret03.c") == 0);
  assert(is_older("non-existent-file", "really-non-existent-file") == 0);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
