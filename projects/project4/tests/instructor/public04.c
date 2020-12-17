#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #4
 * Public test 4 (public04.c)
 *
 * Tests calling change_shoe_size().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student s= new_student("Skyler", 88282, 10.0);

  s= change_shoe_size(s, 10.5);

  assert(has_id(s, 88282));
  assert(get_id(s) == 88282);
  assert(has_name(s, "Skyler"));
  assert(get_shoe_size(s) == 10.5);

  printf("Yes!\n");

  return 0;
}
