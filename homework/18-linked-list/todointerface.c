#include "todointerface.h"

TodoList init(){
    TodoList list = {NULL, 0};
    return list;
}

char *statusToString(Status status){
    switch(status){
        case(Started):return "Started";
        case(InProgress):return "In Progress";
        case(Finished):return "Finished";
        default:return "Not given";
    }  
}

static void assertPriority(uint priority){
    if(priority < 1){
        printf("You cant have priority lower than 1");
        exit(1);
    }
}

static void assertListNotEmpty(TodoList *list){
    if(list->size == 0){
        printf("This list is empty.");
        exit(1);
    }
}

static Task *createTask(char *name){
    Task *newTask = (Task *)malloc(sizeof(Task));
    checkpointer(newTask)
    newTask->next = NULL;
    newTask->status = Started;
    strcpy(newTask->name, name);
    return newTask;
}

char *userInput(char *buffer){
    printf("Enter a name for the task: \n");
    fgets(buffer, 40, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}

static Task *getTask(TodoList *list, uint priority){
    assertPriority(priority);
    Task *currentTask = list->head;
    if(priority > list->size) priority = list->size;
    for(uint i = 1; i < priority; i++){
        currentTask = currentTask->next;
    }
    return currentTask;
}

void addTask(TodoList *list, uint priority, char *name){
    assertPriority(priority);
    Task *newTask = createTask(name);
    if (list->size == 0 || priority == 1){
        newTask->next = list->head;
        list->head = newTask;
    }
    else{
        Task *prevTask = getTask(list, priority - 1);
        newTask->next = prevTask->next;
        prevTask->next = newTask;
    }
    list->size++;
}

void removeTask(TodoList *list, uint priority){
    assertPriority(priority);
    assertListNotEmpty(list);
    if (priority == 1){
        Task *taskToDelete = list->head;
        list->head = list->head->next;
        free(taskToDelete);
    }
    else{
        Task *prevTask = getTask(list, priority - 1);
        Task *taskToDelete = prevTask->next;
        prevTask->next = taskToDelete->next;
        free(taskToDelete);
    }
    list->size--;
}

void changeStatus(TodoList *list, uint priority, Status status){
    getTask(list, priority)->status = status;
}

void printTodoList(TodoList *list){
    if(list->size == 0){
        printf("List is empty\n");
    }
    else{
    Task *currentTask = list->head;
    for (uint i = 1;currentTask; i++){
        printf("%s is priority: %u, with status: %s \n", currentTask->name, i, statusToString(currentTask->status));
        currentTask = currentTask->next;
    }
    }
}

void release(TodoList *list){
    for(Task *taskToDelete = NULL; list->head; free(taskToDelete)){
        taskToDelete = list->head;
        list->head = list->head->next;
    }
}