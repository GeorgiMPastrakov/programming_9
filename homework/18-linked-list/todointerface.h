#ifndef TODOINTERFACE_H
#define TODOINTERFACE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define checkpointer(x) if(x == NULL){printf("Error allocating memory\n");\
exit(1);\
}
typedef unsigned int uint;
typedef enum{
    Started=1,
    InProgress,
    Finished
}Status;

typedef struct Task{
    char name[40];
    struct Task *next;
    Status status;
}Task;

typedef struct {
    struct Task *head;
    uint size;
}TodoList;

TodoList init();
void addTask(TodoList *list, uint priority, char *name);
void removeTask(TodoList *list, uint priority);
void changeStatus(TodoList *list, uint priority, Status status);
void printTodoList(TodoList *list);
char *userInput(char *buffer);
void release(TodoList *list);
#endif