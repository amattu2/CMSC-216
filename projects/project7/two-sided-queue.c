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
 *
 * Notes
 * - The uses a doubly-linked list, with
 * one exception. The tail does not point to the head.
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
    twosq->head = node;
    twosq->tail = node;
    twosq->size++;
  } else {
    Node *old_head = twosq->head;
    node->prev = NULL;
    old_head->prev = node;
    node->next = old_head;
    twosq->head = node;
    twosq->size++;
  }

  /* Default */
  return 1;
}

/* Add node to the back */
int add_back(Two_sided_queue *const twosq, int new_value) {
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
  if (!twosq->head && !twosq->tail) {
    node->prev = NULL;
    node->next = NULL;
    twosq->tail = node;
    twosq->head = node;
    twosq->size++;
  } else {
    Node *old_tail = twosq->tail;
    old_tail->next = node;
    node->prev = old_tail;
    node->next = NULL;
    twosq->tail = node;
    twosq->size++;
  }

  /* Default */
  return 1;
}

/* Get number of elements in queue */
int num_elements(Two_sided_queue *const twosq) {
  /* Checks */
  if (!twosq || !twosq->size)
    return 0;

  /* Default */
  return twosq->size;
}

/* Print element values in queue */
void print(Two_sided_queue *const twosq) {
  /* Variables */
  Node *current;

  /* Checks */
  if (!twosq || !twosq->size || twosq->size <= 0)
    return;
  if (!twosq->head)
    return;
  else
    current = twosq->head;

  /* Loop */
  while (current && current->next != current) {
    /* Print */
    printf("%d", current->data);

    /* Check next element */
    if (current->next)
      printf(" ");

    /* Assign next current */
    current = current->next;
  }
  printf("\n");
}

/* Remove first node in queue */
int remove_front(Two_sided_queue *const twosq, int *value) {
  /* Variables */
  Node *new_head;

  /* Checks */
  if (!twosq)
    return 0;
  if (!twosq->head)
    return 0;

  /* Assign values */
  new_head = twosq->head->next;
  value = &twosq->head->data;
  free(twosq->head);
  twosq->head = new_head;
  twosq->size = (twosq->size <= 0 ? 0 : twosq->size - 1);

  /* Default */
  return 1;
}

/* Remove lastmost element in queue */
int remove_back(Two_sided_queue *const twosq, int *value) {
  /* Variables */
  Node *new_tail;

  /* Checks */
  if (!twosq)
    return 0;
  if (!twosq->tail)
    return 0;

  /* Assign values */
  new_tail = twosq->tail->prev;
  value = &twosq->tail->data;
  free(twosq->tail);
  twosq->tail = new_tail;
  twosq->size = (twosq->size <= 0 ? 0 : twosq->size - 1);

  /* Default */
  return 1;
}
