#ifndef DYNAMIC_ARR_INTERFACE
#define DYNAMIC_ARR_INTERFACE
#include <stdlib.h>
#include <stdio.h>

#define CHECK_ALLOCATION(x) if(x == NULL){\
        printf("Error allocating memory");\
        exit(1);}

#define ASSERT_VALID_CAPACITY(x) if((int)x < 0){\
    printf("Not a valid capacity (must be over 0)");\
    exit(1);}

typedef int DynArrType;
typedef unsigned int uint;
typedef struct {
    DynArrType *buffer;
    uint size;
    uint capacity;
}DynamicArray;

DynamicArray init(DynArrType capacity);

void pushFront(DynamicArray *arr, DynArrType value);
void push(DynamicArray *arr, DynArrType value, uint index);
void pushBack(DynamicArray *arr, DynArrType value);

DynArrType popFront(DynamicArray *arr);
DynArrType pop(DynamicArray *arr, uint index);
DynArrType popBack(DynamicArray *arr);

DynArrType get(DynamicArray *arr, uint index);
void set(DynamicArray *arr, uint index, DynArrType value);

void release(DynamicArray *arr);

#endif