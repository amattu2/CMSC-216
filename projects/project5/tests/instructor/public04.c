#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #5
 * Public test 4 (public04.c)
 *
 * Tests calling change_name().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Courtney Koala", 38463, 5.0);

  change_name(s, "Kourtney");

  assert(has_id(s, 38463));
  assert(get_id(s) == 38463);
  assert(has_name(s, "Kourtney"));
  assert(get_shoe_size(s) == 5.0);

  printf("The evaluation of every assertion was completely satisfactory!\n");

  return 0;
}
