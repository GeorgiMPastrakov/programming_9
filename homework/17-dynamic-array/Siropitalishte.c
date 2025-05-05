#include <stdio.h>
#include <stdlib.h>
#include "../../lessons/17-dynamic-array/9v/DynamicArray.h"
#include "../../lessons/17-dynamic-array/9v/util.h"
#include "task_interface.h"

DynArrType user_input_EGN(){
    DynArrType EGN;
    printf("\nEnter a personal identification number: ");
    scanf("%d", &EGN);
    return EGN;
}

void display_donors(DynamicArray *EGNta){
    if(EGNta->size == 0){
        printf("There are no donors.\n");
    }
    else{
    printf("\nDonors personal identification numbers: ");
    for(uint i = 0; i < EGNta->size; i++){
        printf("EGN at index %d is: %d \n", i, get(EGNta, i));
    }
}
}


int main(void) {
DynamicArray EGNta = init(0);
int choice = 0;

while (1) {
    printf("\n==== Donor Management ====\n");
    printf("1. Register new donor\n");
    printf("2. Remove donor by ID\n");
    printf("3. Show all donors\n");
    printf("4. Exit\n");
    printf("Choose option: \n");
    scanf("%d", &choice);

    switch (choice){
        case 1:{
            DynArrType buffer_egn = user_input_EGN();
            findIndex(&EGNta, buffer_egn) == -1
            ? pushBack(&EGNta, buffer_egn)
            : printf("Donor already registered. \n");
            break;
        }
        case 2:{
            DynArrType temp_egn = user_input_EGN();
            int egn_index = findIndex(&EGNta, temp_egn);
            (egn_index != -1)
             ? pop(&EGNta, (int)egn_index), printf("Donor %d removed. \n", egn_index)
             : printf("Donor not found\n");
            break;
        }
        case 3:{
            display_donors(&EGNta);
            break;
        }
        case 4:{
            release(&EGNta);
            printf("Exiting...");
            exit(0);
        }
    }
}
return 0;
}