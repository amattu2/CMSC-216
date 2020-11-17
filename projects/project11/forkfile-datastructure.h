/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Nov 17th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Forkfile data structure */
#ifndef STRUCT_DEF
  /* Define preprocessor variable */
  #define STRUCT_DEF

  /* Forkfile Generic Node */
  typedef struct node {
    char *name;
  } Node;

  /* Forkfile Target Structure */
  typedef struct rule {
    /* Item Index */
    int index;
    /* Rule (Target) Name */
    char *name;
    /* Dependancy Count */
    int dependency_count;
    /* Dependancies (Linked List) */
    Node *dependency_head;
    /* Command */
    char *command;
  } Rule;

  /* Forkfile Encompassing Structure */
  typedef struct {
    int rule_count;
    Rule *target_head;
  } Forkfile;
#endif
