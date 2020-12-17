#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #13
 * Public test 3 (public3.c)
 *
 * Runs your program with two filenames on the command line, so two threads
 * will be created, but this time the files will have many numbers.  This
 * test runs your program as
 *
 *   sum-files-threaded.x public3a.inputdata public3b.inputdata
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX 100
#define FILENAME1 "public3a.inputdata"
#define FILENAME2 "public3b.inputdata"
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
  for (i= 1; i <= 50000; i++)
    fprintf(datafile1, "%d\n", rand() % MAX);

  fclose(datafile1);

  for (i= 1; i <= 50000; i++)
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
