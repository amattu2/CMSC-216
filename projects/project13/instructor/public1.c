#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #13
 * Public test 1 (public1.c)
 *
 * Runs your program with just one filename on the command line, meaning
 * only one thread will be created.  The file will have just a few numbers.
 * This test runs your program as
 *
 *   sum-files-threaded.x public1.inputdata
 *
 * This test just ensures that your program is able to create one thread
 * that works correctly.
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX 100
#define FILENAME "public1.inputdata"
#if !defined(EXECUTABLE)
#define EXECUTABLE "./sum-files-threaded.x"
#endif
#define COMMAND_TO_RUN EXECUTABLE " " FILENAME

int main(void) {
  FILE *datafile= fopen(FILENAME, "w");
  int i;

  /* causes the pseudorandom number sequence to always be the same every
     time the test is run, even on different machines */
  srand(216);

  /* create output file */
  for (i= 1; i <= 3; i++)
    fprintf(datafile, "%d\n", rand() % MAX);

  fclose(datafile);

  /* run threaded program, or sequential one, depending upon the value of
     EXECUTABLE */
  assert(system(COMMAND_TO_RUN) == 0);

  #if !defined(KEEP)
  remove(FILENAME);
  #endif

  return 0;
}
