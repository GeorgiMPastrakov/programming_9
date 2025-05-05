#include <stdio.h>
#include "../../lessons/17-dynamic-array/9v/DynamicArray.h"
#include "../../lessons/17-dynamic-array/9v/util.h"
#include "task_interface.h"

int main(void) {
    DynamicArray arr = init(5);

    pushBack(&arr, 10);
    pushBack(&arr, 20);
    pushBack(&arr, 30);
    pushBack(&arr, 40);

    int index1 = findIndex(&arr, 30);
    printf("Index of 30: %d\n", index1);

    int index2 = findIndex(&arr, 99);
    printf("Index of 99: %d\n", index2);

    int index3 = findIndex(&arr, 10);
    printf("Index of 10: %d\n", index3);

    int index4 = findIndex(&arr, 40);
    printf("Index of 40: %d\n", index4);

    release(&arr);
    
return 0;
}
