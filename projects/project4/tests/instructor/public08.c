#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #4
 * Public test 8 (public08.c)
 *
 * Tests calling some of the functions with name parameters that are NULL.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student s= new_student("Hao", 11111, 8.0);

  /* should return 0, and by the way not crash */
  assert(!has_name(s, NULL));
  assert(has_name(s, "Hao"));

  /* should set the student's name to an empty string, and not crash */
  change_name(&s, NULL);
  assert(has_name(s, ""));

  printf("Yes!\n");

  return 0;
}
