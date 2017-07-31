#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

struct nnode{
    int value;
    node next;
};

struct head{
    int num_nodes;
    node startList;
};

// build node;
node newNode(int nodeValue){
    node ptr = malloc(sizeof(struct nnode));
    assert (ptr != NULL);
    ptr->value = nodeValue;
    ptr->next = NULL;
    return ptr;
}

head newQueue(){
    head start = malloc(sizeof(struct head));
    assert(start != NULL);
    start->num_nodes = 0;
    start->startList = NULL;

    return start;
}
