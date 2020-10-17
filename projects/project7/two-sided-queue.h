/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* REMOVE this entire comment, and ADD your definition of the type
 * Two_sided_queue here, along with any other definitions you need for it.
 *
 * (You can add your name to the copyright notice above if you like, since
 * you will have written part of the code in this file).
 *
 * NOTE: if you write helper functions in your two-sided-queue.c you should
 * NOT add their prototypes to this header file.  In this case your helper
 * functions will be defined and called only from the file
 * two-sided-queue.c, so their prototypes should just be put at the top of
 * that file- and your helper functions should also be made static, so they
 * are "private" to two-sided-queue.c.
 */

void init(Two_sided_queue *const twosq);
int add_front(Two_sided_queue *const twosq, int new_value);
int add_back(Two_sided_queue *const twosq, int new_value);
int num_elements(Two_sided_queue *const twosq);
void print(Two_sided_queue *const twosq);
int remove_front(Two_sided_queue *const twosq, int *value);
int remove_back(Two_sided_queue *const twosq, int *value);
