/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

typedef struct {
  struct node *head;
  struct node *tail;
  int size;
} Two_sided_queue;

typedef struct node {
  struct node *prev;
  struct node *next;
  int data;
} Node;

void init(Two_sided_queue *const twosq);
int add_front(Two_sided_queue *const twosq, int new_value);
int add_back(Two_sided_queue *const twosq, int new_value);
int num_elements(Two_sided_queue *const twosq);
void print(Two_sided_queue *const twosq);
int remove_front(Two_sided_queue *const twosq, int *value);
int remove_back(Two_sided_queue *const twosq, int *value);
