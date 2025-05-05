#include <stdio.h>
#include "../../lessons/17-dynamic-array/9v/DynamicArray.h"
#include "../../lessons/17-dynamic-array/9v/util.h"
#include "task_interface.h"

int findIndex(DynamicArray *arr, DynArrType element){
    if (arr->size == 0){
        printf("No elements in the array.");
        return -1;
    }
    for(int i = 0; i < arr->size; i++){
        if(arr->buffer[i] == element){
            return i;
        }
    }
return -1;
}