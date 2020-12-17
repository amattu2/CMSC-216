#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* for sleep() */
#include <assert.h>
#include "forkfile.h"
#include "make-target.h"

/* CMSC 216, Fall 2020, Project #11
 * Secret test 2 (secret02.c)
 *
 * Tests calling make_target() when there is no rule in the forkfile with
 * target_name as its target but a file with that name exists.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Forkfile forkfile= read_forkfile("secret02.forkfile");

  /* see Section 5.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* create a file */
  system("touch nonexistent-target-file");
  sleep(1);

  assert(make_target(forkfile, "nonexistent-target-file") == 0);

  /* remove the file afterwards just to keep things clean */
  system("rm -f nonexistent-target-file");

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
