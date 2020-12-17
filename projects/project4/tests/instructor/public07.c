#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2020, Project #4
 * Public test 7 (public07.c)
 *
 * Tests the functions simulating a slightly more realistic scenario- an
 * array of multiple students is created, and the functions are used to
 * search for and modify elements of the array.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define SZ 10

int main(void) {
  Student roster[SZ]= {{"Sally", 18491, 7.5}, {"Lucas", 81747, 11},
                       {"David", 89747, 11.5}, {"Chloe", 88195, 8.0},
                       {"Jose", 11928, 10.0}, {"Madison", 76644, 8.5},
                       {"Benjamin", 80875, 9.0}, {"Mia", 76647, 9.5},
                       {"Ernest", 99974, 10.5}, {"Kendra", 66331, 8.5}};
  int i;

  i= 0;
  while (i < 10 && !has_name(roster[i], "Jose"))
    i++;
  assert(i == 4);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Kendra"))
    i++;
  assert(i == 9);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Oscar"))
    i++;
  assert(i == 10);

  i= 0;
  while (i < 10 && !has_id(roster[i], 76644))
    i++;
  assert(i == 5);

  i= 0;
  while (i < 10 && !has_id(roster[i], 66331))
    i++;
  assert(i == 9);

  i= 0;
  while (i < 10 && !has_id(roster[i], 99999))
    i++;
  assert(i == 10);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Chloe"))
    i++;
  change_name(&roster[i], "Khloe");
  roster[i]= change_shoe_size(roster[i], 9.0);
  assert(has_id(roster[i], 88195));
  assert(get_id(roster[i]) == 88195);
  assert(get_shoe_size(roster[i]) == 9.0);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Khloe"))
    i++;
  assert(i == 3);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Chloe"))
    i++;
  assert(i == 10);

  printf("Yes!\n");

  return 0;
}
