// ADT for a FIFO queue
// COMP1521 17s2 Week01 Lab Exercise
// Written by John Shepherd, July 2017
// Modified by ...

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Queue.h"

typedef struct QueueNode {
   int jobid;  // unique job ID
   int size;   // size/duration of job
   struct QueueNode *next;
} QueueNode;

struct QueueRep {
   int nitems;      // # of nodes
   QueueNode *head; // first node
   QueueNode *tail; // last node
};


// TODO:
// remove the #if 0 and #endif
// once you've added code to use this function

// create a new node for a Queue
static QueueNode *makeQueueNode(int id, int size)
{
   QueueNode *new;
   new = malloc(sizeof(struct QueueNode));
   assert(new != NULL);
   new->jobid = id;
   new->size = size;
   new->next = NULL;
   return new;
}


// make a new empty Queue
Queue makeQueue()
{
   Queue new;
   new = malloc(sizeof(struct QueueRep));
   assert(new != NULL);
   new->nitems = 0;
   new->head = new->tail = NULL;
   return new;
}

// release space used by Queue
void  freeQueue(Queue q)
{
   assert(q != NULL);
   // TODO
}

// add a new item to tail of Queue
void  enterQueue(Queue q, int id, int size)
{
   assert(q != NULL);
   QueueNode *newNode = makeQueueNode(id, size);
   QueueNode *temp = q->head;
  // printf("%p\n", &q->head);
   // case 1 if queue is empty
   if (q->head == NULL){
       q->head = newNode;
       q->tail = newNode;
   } else {
       printf("hellDSAJKDASHKLHDSALHSDKo\n");
       while (temp->next != NULL){
           temp = temp->next;
       }
       temp = newNode;
       q->tail = newNode;
   }
   assert(q->head != NULL);
}

// remove item on head of Queue
int   leaveQueue(Queue q)
{
   assert(q != NULL);
   // TODO
   return 10; // replace this statement
}

// count # items in Queue
int   lengthQueue(Queue q)
{
   assert(q != NULL);
   return q->nitems;
}

// return total size in all Queue items
int   volumeQueue(Queue q)
{
   assert(q != NULL);
   QueueNode *curr;
   curr = q->head;
   int i = 0;
   while (curr != NULL){
       curr = curr->next;
       i++;
   }

   return 10; // replace this statement
}

// return size/duration of first job in Queue
int   nextDurationQueue(Queue q)
{
   assert(q != NULL);
   QueueNode *curr;
   curr = q->head;
   int i = curr->size;
   printf("size of nextDuration is =  %d\n", curr->size);

   return 10; // replace this statement
}


// display jobid's in Queue
void showQueue(Queue q)
{
   QueueNode *curr;
   curr = q->head;
   while (curr != NULL) {
      printf(" (%d,%d)", curr->jobid, curr->size);
      curr = curr->next;
   }
}
