#if !defined(MAKE_TARGET_H)
#define MAKE_TARGET_H

/* just documenting that this header file uses definitions in forkfile.h */
#include "forkfile.h"

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int make_target(Forkfile forkfile, const char target_name[]);

#endif
