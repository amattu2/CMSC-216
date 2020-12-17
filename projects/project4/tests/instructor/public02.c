#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #4
 * Public test 2 (public02.c)
 *
 * Tests calling init_student() and checking that the student's data was
 * stored correctly.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student s;

  init_student(&s, "Aaliyah", 64321, 7.5);

  assert(has_id(s, 64321));
  assert(get_id(s) == 64321);
  assert(has_name(s, "Aaliyah"));
  assert(get_shoe_size(s) == 7.5);

  printf("Yes!\n");

  return 0;
}
