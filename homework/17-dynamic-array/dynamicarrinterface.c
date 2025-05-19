#include "dynamicarrinterface.h"

static void ASSERT_INDEX_IN_BOUNDS(DynamicArray *arr, uint index){
    if(index > arr->size - 1 ){
        printf("Index is out of bounds");
        exit(1);
    }
}

DynamicArray init(DynArrType capacity){
    ASSERT_VALID_CAPACITY(capacity)
    DynamicArray newArr = {
        .buffer = NULL,
        .size = 0,
        .capacity = capacity
    };

    if(capacity > 0){
        newArr.buffer = (DynArrType *) calloc(sizeof(DynArrType), capacity);
        CHECK_ALLOCATION(newArr.buffer)
    }
    return newArr;
}

static void resize(DynamicArray *arr, uint newSize){
    if(newSize > arr->capacity){
        if(arr->capacity == 0) arr->capacity = 1;
        while(newSize > arr->capacity) arr->capacity *= 2;
    }
    else if(newSize <= arr->capacity / 2) arr->capacity = newSize;
    if(arr->capacity == 0) free(arr->buffer);
    else{
        DynArrType *ptr = (DynArrType *)realloc(arr->buffer, sizeof(DynArrType) * arr->capacity);
        CHECK_ALLOCATION(ptr)
        arr->buffer = ptr;
    }
    arr->size = newSize;
}

void push(DynamicArray *arr, DynArrType value, uint index){
    ASSERT_INDEX_IN_BOUNDS(arr, index);
    resize(arr, arr->size + 1);
    for(uint i = arr->size - 1; i > index; i--){
        arr->buffer[i] = arr->buffer[i-1];
    }
    arr->buffer[index] = value;
}

void pushFront(DynamicArray *arr, DynArrType value){
    push(arr, value, 0);
}

void pushBack(DynamicArray *arr, DynArrType value){
    resize(arr, arr->size + 1);
    arr->buffer[arr->size - 1] = value;
}

DynArrType pop(DynamicArray *arr, uint index){
    ASSERT_INDEX_IN_BOUNDS(arr, index);
    DynArrType result = arr->buffer[index];
    for(uint i = index; i < arr->size - 1; i++ ){
        arr->buffer[i] = arr->buffer[i + 1];
    }
    resize(arr, arr->size - 1);
    return result;
}

DynArrType popFront(DynamicArray *arr){
    pop(arr, 0);
}

DynArrType popBack(DynamicArray *arr){
    DynArrType result = arr->buffer[arr->size - 1];
    resize(arr, arr->size - 1);
    return result;
}


DynArrType get(DynamicArray *arr, uint index){
    ASSERT_INDEX_IN_BOUNDS(arr, index);
    return arr->buffer[index];
}

void set(DynamicArray *arr, uint index, DynArrType value){
    ASSERT_INDEX_IN_BOUNDS(arr, index);
    arr->buffer[index] = value;
}

void release(DynamicArray *arr){
    free(arr->buffer);
    arr->buffer = NULL;
    arr->size = 0;
    arr->capacity = 0;
    
}