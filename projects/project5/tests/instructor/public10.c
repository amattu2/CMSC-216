#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #5
 * Public test 10 (public10.c)
 *
 * Tests passing NULL into the functions' Student pointer parameters (which
 * should have no effect, but not crash).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Laura Llama", 83648, 10.5);

  assert(!has_id(NULL, 83648));
  assert(!has_name(NULL, "Laura Llama"));
  assert(get_id(NULL) == 0);
  assert(get_shoe_size(NULL) == 0.0);
  change_shoe_size(NULL, 11.0);
  change_name(NULL, "Leslie Llama");
  copy_student(NULL, NULL);

  assert(has_id(s, 83648));
  assert(get_id(s) == 83648);
  assert(has_name(s, "Laura Llama"));
  assert(get_shoe_size(s) == 10.5);

  printf("The evaluation of every assertion was completely satisfactory!\n");

  return 0;
}
