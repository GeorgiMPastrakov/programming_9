#include "llinterface.h"

LinkedList init() {
  LinkedList newList = {
    .head = NULL,
    .size = 0
  };
  return newList;
}

static void assertListNotEmpty(LinkedList *list){
  if(list->size == 0){
    printf("List is empty! \n");
    exit(1);
  }
}

static void assertIndexInBounds(LinkedList * list, uint index) {
  if (list->size <= index) {
    printf("Index out of bounds\n");
    exit(1);
  }
}

static Node * createNode(ListType value) {
  Node * newNode = (Node *)malloc(sizeof(Node));
  checkpointer(newNode)
  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

Node * getNode(LinkedList * list, uint index) {
  assertIndexInBounds(list, index);
  Node * currentNode = list->head;
  for (uint i = 0; i < index; i++) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

ListType get(LinkedList * list, uint index) {
  return getNode(list, index)->value;
}

void set(LinkedList * list, uint index, ListType value) {
  getNode(list, index)->value = value;
}

void pushFront(LinkedList * list, ListType value) {
  Node * newNode = createNode(value);
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

void push(LinkedList * list, uint index, ListType value) {
  if (index == 0) {
    pushFront(list, value);
  } 
  else {
    assertIndexInBounds(list, index - 1);
    Node * prevNode = getNode(list, index - 1);
    Node * newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    list->size++;
  }
}

void pushBack(LinkedList * list, ListType value) {
  if(list->size == 0){
    pushFront(list, value);
  }
  else{
  Node *lastNode = getNode(list, list->size - 1);
  Node *newNode = createNode(value);
  lastNode->next = newNode;
  list->size++;
  }
}

ListType popFront(LinkedList * list) {
  assertListNotEmpty(list);
  Node * nodeToDelete = list->head;
  list->head = nodeToDelete->next;
  ListType result = nodeToDelete->value;
  free(nodeToDelete);
  list->size--;
  return result;
}


ListType popBack(LinkedList * list) {
  assertListNotEmpty(list);
  if(list->size == 1){
    return popFront(list);
  }
  else{
  Node *prevNode = getNode(list, list->size - 2);
  ListType result = prevNode->next->value;
  free(prevNode->next);
  prevNode->next = NULL;
  list->size--;
  return result;
  }
}

ListType pop(LinkedList * list, uint index) {
  assertIndexInBounds(list, index);
  if(index == 0){
    return popFront(list);
  }
  else {
  Node *prevNode = getNode(list, index - 1);
  Node *nodeToDelete = prevNode->next;
  ListType result = nodeToDelete->value;
  prevNode->next = nodeToDelete->next;
  free(nodeToDelete); 
  list->size--;
  return result;
  }
}

void release(LinkedList * list) {
  for(Node *nodeToDelete = NULL; list->head; list->head = list->head->next){
    nodeToDelete = list->head;
    free(nodeToDelete);
  }
  list->size = 0;
}