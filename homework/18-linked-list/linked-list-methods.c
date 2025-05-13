#include <stdio.h>
#include "../../lessons/18-linked-list/9v/LinkedList.h"

static Node * createNode(ListType value) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
      printf("Error allocating memory \n");
      exit(1);
    }
    newNode->value = value;
  
    return newNode;
  }

void pushBack(LinkedList * list, ListType value) {

}
void set(LinkedList * list, uint index, ListType value) {

}

ListType popBack(LinkedList * list) {

}

ListType pop(LinkedList * list, uint index) {

}

void release(LinkedList * list) {
  
}