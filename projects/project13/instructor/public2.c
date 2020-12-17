#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #13
 * Public test 2 (public2.c)
 *
 * Runs your program with two filenames on the command line, so two threads
 * will be created.  Each file will have just a few numbers.  This test runs
 * your program as
 *
 *   sum-files-threaded.x public2a.inputdata public2b.inputdata
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX 100
#define FILENAME1 "public2a.inputdata"
#define FILENAME2 "public2b.inputdata"
#if !defined(EXECUTABLE)
#define EXECUTABLE "./sum-files-threaded.x"
#endif
#define COMMAND_TO_RUN EXECUTABLE " " FILENAME1 " " FILENAME2

int main(void) {
  FILE *datafile1= fopen(FILENAME1, "w"), *datafile2= fopen(FILENAME2, "w");
  int i;

  /* causes the pseudorandom number sequence to always be the same every
     time the test is run, even on different machines */
  srand(216);

  /* create output files */
  for (i= 1; i <= 3; i++)
    fprintf(datafile1, "%d\n", rand() % MAX);

  fclose(datafile1);

  for (i= 1; i <= 7; i++)
    fprintf(datafile2, "%d\n", rand() % MAX);

  fclose(datafile2);

  /* run threaded program, or sequential one, depending upon the value of
     EXECUTABLE */
  assert(system(COMMAND_TO_RUN) == 0);

  #if !defined(KEEP)
  remove(FILENAME1 " " FILENAME2);
  #endif

  return 0;
}
