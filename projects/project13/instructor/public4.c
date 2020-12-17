#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* CMSC 216, Fall 2020, Project #13
 * Public test 4 (public4.c)
 *
 * Runs your program with a large number of filenames on the command line-
 * 300 of them- so 300 threads will be created, and the files will all have
 * many numbers (10000 per file).  The filenames will be of the format
 * public4XX.input, e.g., public4aa.input, public4ab.input, ... ,
 * public4az.input, public4ba.input, ... up through public4ln.inputdata.
 * This test runs your program as
 *
 *   ./sum-files-threaded.x public4*.inputdata
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX 100
#define FILENAMES "public4*.inputdata"
#if !defined(EXECUTABLE)
#define EXECUTABLE "./sum-files-threaded.x"
#endif
#define COMMAND_TO_RUN EXECUTABLE " " FILENAMES
#define NUM_FILES 300
#define NUMBERS_PER_FILE 10000

int main(void) {
  FILE *datafile;
  int which_file, i;
  char filename[23];

  /* causes the pseudorandom number sequence to always be the same every
     time the test is run, even on different machines */
  srand(216);

  /* create output files */
  for (which_file= 0; which_file < NUM_FILES; which_file++) {
    sprintf(filename, "public4%c%c.inputdata", 'a' + (which_file / 26),
            'a' + (which_file % 26));
    datafile= fopen(filename, "w");

    for (i= 1; i <= NUMBERS_PER_FILE; i++)
      fprintf(datafile, "%d\n", rand() % MAX);

    fclose(datafile);
  }

  /* run threaded program, or sequential one, depending upon the value of
     EXECUTABLE */
  assert(system("ulimit -u 350 ; " COMMAND_TO_RUN) == 0);

  #if !defined(KEEP)
  for (which_file= 0; which_file < NUM_FILES; which_file++) {
    sprintf(filename, "public4%c%c.inputdata", 'a' + (which_file / 26),
            'a' + (which_file % 26));
    remove(filename);
  }
  #endif

  return 0;
}
