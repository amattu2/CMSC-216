#include <stdio.h>
#include "forkfile.h"
#include "make-target.h"

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* make_target() tries to build the target target_name in the forkfile
 * forkfile.
 *
 * The procedure for building a target is:
 *
 *   - If there is no rule with target target_name and there is no file with
 *     that name, return -1.
 *
 *   - There is a file with that name but there is no rule with target
 *     target_name then just return 0.
 *
 *   - In all other cases try to build each dependency of target_name
 *     (recursively), left to right, stopping and returning the error code
 *     if performing any of the actions produced a nonzero exit code.
 *     Otherwise perform the action command if target_name still doesn't
 *     exist or if it does exist but is older than any of its dependencies.
 *     
 *   - If the action command doesn't need to be performed just return 0,
 *     otherwise whatever do_action() returns is what is returned.
 */

/* note that we named a local variable __dependency, with two preceding
 * underscores, to avoid possibly conflicting with any declarations in your
 * code
 */
int make_target(Forkfile forkfile, const char target_name[]) {
  int which_rule= lookup_target(forkfile, target_name), i, need_to_run_cmd= 0,
           command_ret_value;
  char *__dependency;

  if (which_rule == -1)  /* there is no rule for target_name */
    if (exists(target_name))
      return 0;  /* target_name exists and there's no rule for it- OK */
    else return -1;  /* error if any target_name doesn't exist and there's
                        no rule to create it */

  else {

    /* first recursively call on all of the target's dependencies */
    for (i= 0; i < num_dependencies(forkfile, which_rule); i++) {
      __dependency= get_dependency(forkfile, which_rule, i);

      command_ret_value= make_target(forkfile, __dependency);

      /* if all of the recursive calls return 0 we will just continue
         below */
      if (command_ret_value != 0)
        return command_ret_value;
    }

    /* if the target exists (the recursive call on one of the dependencies
       may have created it even if it didn't exist before), check whether
       any of its dependencies are newer than it- if so, we need to perform
       the command for this rule */
    if (exists(target_name))
      for (i= 0; i < num_dependencies(forkfile, which_rule); i++) {
        __dependency= get_dependency(forkfile, which_rule, i);

        if (exists(__dependency) && is_older(target_name, __dependency))
          need_to_run_cmd= 1;
      }

    /* if at this point the target name still doesn't exist, or we
       determined above that we have to perform the command because the
       target does exist but is older than any of its dependencies, print
       the command, execute it, and return whatever its exit status is */
    if (!exists(target_name) || need_to_run_cmd) {
      printf("%s:\n\t", target_name);
      print_action(forkfile, which_rule);
      printf("\n");
      command_ret_value= do_action(forkfile, which_rule);

      return command_ret_value;
    }

    /* the target already exists and is newer than its dependency */
    return 0;
  }
}
