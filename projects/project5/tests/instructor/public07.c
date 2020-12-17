#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #5
 * Public test 7 (public07.c)
 *
 * Tests copy_student().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Perry Parrot", 11144, 6.5);
  Student *t= new_student("Oswald Owl", 64321, 7.5);

  copy_student(t, s);

  assert(has_id(s, 11144));
  assert(get_id(s) == 11144);
  assert(has_name(s, "Perry Parrot"));
  assert(get_shoe_size(s) == 6.5);

  assert(has_id(t, 11144));
  assert(get_id(t) == 11144);
  assert(has_name(t, "Perry Parrot"));
  assert(get_shoe_size(t) == 6.5);

  printf("The evaluation of every assertion was completely satisfactory!\n");

  return 0;
}
