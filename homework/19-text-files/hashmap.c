#include "hashmap.h"

static uint hashISBN(char *isbn, HashMap *map) {
    uint sum = 0;
    while (*isbn)
        sum += (uchar)*isbn++;
    return sum % map->bucketCnt;
}

static createHashNode(Book *b) {
    HashNode *node = malloc(sizeof(HashNode));
    checkPointer(node);
    node->book = *b;
    node->next = NULL;
    return node;
}

HashMap initMap(uint bucketCnt) {
    HashMap map;
    map.bucketCnt = bucketCnt;
    map.size = 0;
    map.bucket = calloc(bucketCnt, sizeof(HashNode *));
    checkPointer(map.bucket);
    return map;
}

void insert(HashMap *map, Book *b) {
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

static HashNode *get(HashMap *map, char *isbn) {
    uint index = hashISBN(isbn, map);
    for (HashNode *current = map->bucket[index]; current != NULL; current = current->next) {
        if (strcmp(current->book.isbn, isbn) == 0) {
            return current;
        }
    }
    printf("Book with ISBN %s not found.\n", isbn);
    return NULL;
}

Book erase(HashMap *map, char *isbn) {
    uint index = hashISBN(isbn, map);
    HashNode *prev = NULL;
    HashNode *current = map->bucket[index];

    while (current != NULL) {
        if (strcmp(current->book.isbn, isbn) == 0) {
            Book removedBook = current->book;
            if (prev == NULL) {
                map->bucket[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            map->size--;
            return removedBook;
        }
        prev = current;
        current = current->next;
    }
    printf("Book with ISBN %s not found.\n", isbn);
    Book emptyBook = {0};
    return emptyBook;
    
}


static void freeList(HashNode *n) {
    while (n != NULL) {
        HashNode *tmp = n->next;
        free(n);
        n = tmp;
    }
}

void release(HashMap *map) {
    for (uint i = 0; i < map->bucketCnt; i++){
        freeList(map->bucket[i]);
    }
    free(map->bucket);
    map->bucket    = NULL;
    map->bucketCnt = 0;
    map->size      = 0;
}
