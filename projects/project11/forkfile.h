#if !defined(FORKFILE_H)
#define FORKFILE_H

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

#include "forkfile-datastructure.h"

Forkfile read_forkfile(const char filename[]);
int lookup_target(Forkfile forkfile, const char target_name[]);
void print_action(Forkfile forkfile, int rule_num);
void print_forkfile(Forkfile forkfile);
int num_dependencies(Forkfile forkfile, int rule_num);
char *get_dependency(Forkfile forkfile, int rule_num, int dependency_num);
int exists(const char filename[]);
int is_older(const char filename1[], const char filename2[]);
int do_action(Forkfile forkfile, int rule_num);

#endif
