#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #5
 * Public test 11 (public11.c)
 *
 * Ensures that pointer aliasing is not occurring in new_student().
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  char name[]= "Shelby Sheep";
  Student *s= new_student(name, 11144, 6.5);

  /* change the string (only its first six characters); now "Sharon Sheep" */
  strncpy(name, "Sharon", 6);

  assert(has_id(s, 11144));
  assert(get_id(s) == 11144);
  /* changing the string "name" should not have affected s's name */
  assert(has_name(s, "Shelby Sheep"));
  assert(get_shoe_size(s) == 6.5);

  printf("The evaluation of every assertion was completely satisfactory!\n");

  return 0;
}
