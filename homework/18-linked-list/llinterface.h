#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#define checkpointer(x) if(x == NULL){printf("Error allocating memory\n");\
exit(1);\
}

typedef int ListType;
typedef unsigned int uint;

typedef struct Node {
  ListType value;
  struct Node * next;
} Node;

typedef struct {
  struct Node * head;
  uint size;
} LinkedList;

LinkedList init();

void pushFront(LinkedList * list, ListType value);
void pushBack(LinkedList * list, ListType value);
void push(LinkedList * list, uint index, ListType value);

ListType popFront(LinkedList * list);
ListType popBack(LinkedList * list);
ListType pop(LinkedList * list, uint index);

Node * getNode(LinkedList * list, uint index);

ListType get(LinkedList * list, uint index);
void set(LinkedList * list, uint index, ListType value);

void release(LinkedList * list);

#endif