#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #5
 * Public test 2 (public02.c)
 *
 * Tests creating several students to ensure that their data does not
 * conflict.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Rocky Racoon", 11144, 6.5);
  Student *t= new_student("Wally Walrus", 64321, 7.5);
  Student *u= new_student("Ellie Elephant", 88444, 8.5);

  assert(has_id(s, 11144));
  assert(get_id(s) == 11144);
  assert(has_name(s, "Rocky Racoon"));
  assert(get_shoe_size(s) == 6.5);

  assert(has_id(t, 64321));
  assert(get_id(t) == 64321);
  assert(has_name(t, "Wally Walrus"));
  assert(get_shoe_size(t) == 7.5);

  assert(has_id(u, 88444));
  assert(get_id(u) == 88444);
  assert(has_name(u, "Ellie Elephant"));
  assert(get_shoe_size(u) == 8.5);

  printf("The evaluation of every assertion was completely satisfactory!\n");

  return 0;
}
