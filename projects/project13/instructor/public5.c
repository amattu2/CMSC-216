#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #13
 * Public test 5 (public5.c)
 *
 * Runs your program with two filenames on the command line, so two threads
 * will be created.  Each file will have just a few numbers.  The files will
 * be the same as for the second public test, so the results should be the
 * same.  The difference is that this test uses valgrind to check for memory
 * leaks and corruption of the heap.  This test runs your program as
 *
 *   sum-files-threaded.x public5a.inputdata public5b.inputdata
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX 100
#define FILENAME1 "public5a.inputdata"
#define FILENAME2 "public5b.inputdata"
#if !defined(EXECUTABLE)
#define EXECUTABLE "./sum-files-threaded.x"
#endif
#define COMMAND_TO_RUN "valgrind -q --leak-check=full --error-exitcode=100 " \
                       EXECUTABLE " " FILENAME1 " " FILENAME2

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

  printf("Success!  Your program worked right and didn't have any memory "
         "problems.\n");

  #if !defined(KEEP)
  remove(FILENAME1 " " FILENAME2);
  #endif

  return 0;
}
