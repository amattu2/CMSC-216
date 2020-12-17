#include <stdio.h>
#include "wstring-graph-datastructure.h"

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int main(void) {
  #if !defined(WSTRING_GRAPH_DATASTRUCTURE_H) && \
      !defined(_WSTRING_GRAPH_DATASTRUCTURE_H)
    #error "Incorrect preprocessor symbol name in graph-datastructure.h."
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
