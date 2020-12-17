#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* for sleep() */
#include <assert.h>
#include "forkfile.h"
#include "make-target.h"

/* CMSC 216, Fall 2020, Project #11
 * Public test 8 (public08.c)
 *
 * Tests calling make_target() on the target of a single-rule forkfile, when
 * the target already exists but is older than its dependency (so the action
 * should be performed).
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("public08.forkfile");

  /* see Section 4.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* remove files if they already exist (from a previous execution); -f
     suppresses error messages even if some or all of the files don't exist */
  system("rm -f older-file file newer-file");
  system("date > older-file");
  /* sleep for 1 second before creating files, to ensure that their
     timestamps are later */
  sleep(1);
  system("date > file");
  sleep(1);
  system("date > newer-file");

  assert(make_target(forkfile, "file") == 0);

  printf("\nYet again, all assertions were successful!\n");

  return 0;
}
