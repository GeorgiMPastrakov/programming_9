#include "hashmap.h"

static uint hashISBN(char *isbn, HashMap *map){
    uint sum = 0;
    while (*isbn)
        sum += (uchar)*isbn++;
    return sum % map->bucketCnt;
}

static HashNode *createHashNode(Book *b){
    HashNode *node = malloc(sizeof(HashNode));
    checkPointer(node);
    node->book = *b;
    node->next = NULL;
    return node;
}

HashMap initMap(uint bucketCnt){
    HashMap map;
    map.bucketCnt = bucketCnt;
    map.size = 0;
    map.bucket = calloc(bucketCnt, sizeof(HashNode *));
    checkPointer(map.bucket);
    return map;
}

void insert(HashMap *map, Book *b){
    uint index = hashISBN(b->isbn, map);
    for (HashNode *current = map->bucket[index]; current != NULL; current = current->next){
        if (strcmp(current->book.isbn, b->isbn) == 0) {
            printf("Book with ISBN %s already exists.\n", b->isbn);
            return;
        }
    }
    HashNode *newNode = createHashNode(b);
    newNode->next = map->bucket[index];
    map->bucket[index] = newNode;
    map->size++;
}

Book *get(HashMap *map, char *isbn){
    uint index = hashISBN(isbn, map);
    HashNode *current = map->bucket[index];
    while (current != NULL) {
        if (strcmp(current->book.isbn, isbn) == 0) {
            return &current->book;
        }
        current = current->next;
    }
    printf("Book with ISBN %s not found.\n", isbn);
    return NULL;
}

void erase(HashMap *map, char *isbn){
    uint index = hashISBN(isbn, map);
    HashNode *current = map->bucket[index];
    HashNode *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->book.isbn, isbn) == 0) {
            if (prev == NULL) {
                map->bucket[index] = current->next;
            } 
            else {
                prev->next = current->next;
            }
            free(current);
            map->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Book with ISBN %s not found for deletion.\n", isbn);
}


void printBook(Book *b){
    if (b != NULL) {
        printf("Title: %s\n", b->title);
        printf("Author: %s\n", b->author);
        printf("Genre: %s\n", b->genre);
        printf("Year: %d\n", b->year);
        printf("ISBN: %s\n \n", b->isbn);
    } else {
        printf("Book not found.\n");
    }
}

void printAllBooks(HashMap *map){
    for (uint i = 0; i < map->bucketCnt; i++) {
        HashNode *current = map->bucket[i];
        while (current != NULL) {
            printBook(&current->book);
            current = current->next;
        }
    }
}

static void freeList(HashNode *n){
    while (n != NULL) {
        HashNode *tmp = n->next;
        free(n);
        n = tmp;
    }
}

void release(HashMap *map){
    for (uint i = 0; i < map->bucketCnt; freeList(map->bucket[i++])){}
    free(map->bucket);
    map->bucket = NULL;
    map->bucketCnt = 0;
    map->size = 0;
}
