/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 18th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Implement a 2 sided queue
 * - Implement a makefile
 * - Operate on the 2 sided queue
 * - Build public tests with makefile
*/


/* Files */
#include <stdio.h>
#include <stdlib.h>
#include "two-sided-queue.h"

/* Initialize queue struct */
void init(Two_sided_queue *const twosq) {
  /* Variables */
  Two_sided_queue *queue;

  /* Checks */
  if (!twosq)
    return;

  /* Assign Variables */
  if ((queue = malloc(sizeof(Node) + sizeof(Node) + sizeof(int)))) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    *twosq = *queue;
  }
}

/* Add node to front */
int add_front(Two_sided_queue *const twosq, int new_value) {
  /* Variables */
  Node *node;

  /* Checks */
  if (!twosq)
    return 0;
  if (!(node = malloc(sizeof(Node) + sizeof(Node) + sizeof(int))))
    return 0;
  else
    node->data = new_value;

  /* Find insert spot */
  if (!twosq->head) {
    node->prev = NULL;
    node->next = NULL;
    *twosq->head = *node;
    *twosq->tail = *node;
    twosq->size++;
  } else {
    /* Get first element, reassign it's prev value to node, change twosq pointer to node */
  }

  /* Default */
  return 1;
}

int add_back(Two_sided_queue *const twosq, int new_value);
int num_elements(Two_sided_queue *const twosq);
void print(Two_sided_queue *const twosq);
int remove_front(Two_sided_queue *const twosq, int *value);
int remove_back(Two_sided_queue *const twosq, int *value);
