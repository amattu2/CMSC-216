#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #5
 * Public test 3 (public03.c)
 *
 * Tests calling change_shoe_size().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Lizzie Lizard", 88282, 10.0);

  change_shoe_size(s, 10.5);

  assert(has_id(s, 88282));
  assert(get_id(s) == 88282);
  assert(has_name(s, "Lizzie Lizard"));
  assert(get_shoe_size(s) == 10.5);

  printf("The evaluation of every assertion was completely satisfactory!\n");

  return 0;
}
