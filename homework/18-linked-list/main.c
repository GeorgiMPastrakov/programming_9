#include "todointerface.h"

void printMenu(){
    printf("\n===== TODO LIST MENU =====\n");
    printf("1. Add new task\n");
    printf("2. Remove task\n");
    printf("3. Change task status\n");
    printf("4. Print all tasks\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main(void){
    TodoList List = init();

    while(1){
        printMenu();
        int choice;
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1: {
                char name[40];
                userInput(name);
                uint priority;
                printf("Enter the priority (1-%d): ", List.size + 1);
                scanf("%u", &priority);
                getchar();
                addTask(&List, priority, name);
                break;
            }
            case 2: {
                uint priority;
                printf("Enter the task priority to remove: ");
                scanf("%u", &priority);
                removeTask(&List, priority);
                break;
            }
            case 3: {
                uint priority;
                printf("Enter the task priority to change status: ");
                scanf("%u", &priority);
                Status status;
                printf("Enter new status (1-Started, 2-InProgress, 3-Finished): ");
                scanf("%u", (unsigned int *)&status);
                changeStatus(&List, priority, status);
                break;
            }
            case 4:
                printTodoList(&List);
                break;
            case 5:
                release(&List);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
}