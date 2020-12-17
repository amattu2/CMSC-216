#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #4
 * Public test 10 (public10.c)
 *
 * Tests that init_student() and new_student() will store an empty string
 * for a student's name if NULL is passed into their name parameters.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student s, t= new_student(NULL, 33333, 9.0);

  init_student(&s, NULL, 22222, 8.0);

  assert(has_id(s, 22222));
  assert(get_id(s) == 22222);
  assert(has_name(s, ""));
  assert(get_shoe_size(s) == 8.0);

  assert(has_id(t, 33333));
  assert(get_id(t) == 33333);
  assert(has_name(t, ""));
  assert(get_shoe_size(t) == 9.0);

  printf("Yes!\n");

  return 0;
}
