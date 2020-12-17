#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #4
 * Public test 9 (public09.c)
 *
 * Tests calling init_student() and change_name() passing NULL into their
 * first (Student) pointer parameters.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student s= new_student("Ali", 83648, 10.5);

  /* these should have no effect, but not crash */
  init_student(NULL, "Omar", 84774, 1.0);
  change_name(NULL, "Ahmed");

  assert(has_id(s, 83648));
  assert(get_id(s) == 83648);
  assert(has_name(s, "Ali"));
  assert(get_shoe_size(s) == 10.5);

  printf("Yes!\n");

  return 0;
}
