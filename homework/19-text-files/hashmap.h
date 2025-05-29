#ifndef HASHMAP_H
#define HASHMAP_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define checkPointer(x) \
    if ((x) == NULL) { \
        printf("Error allocating memory\n"); \
        exit(1);}

typedef unsigned char uchar;
typedef unsigned int uint;


typedef struct {
    char title[100];
    char author[100];
    char genre[50];
    int  year;
    char isbn[20];
} Book;

typedef struct HashNode {
    Book book;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **bucket;
    uint bucketCnt;
    uint size;
} HashMap;

HashMap initMap(uint bucketCnt);
void insert(HashMap *map, Book *b);
Book *get(HashMap *map, char *isbn);
void erase(HashMap *map, char *isbn);
void printBook(Book *b);
void printAllBooks(HashMap *map);
void release(HashMap *map);

#endif
