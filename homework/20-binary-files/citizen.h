#ifndef CITIZEN_H
#define CITIZEN_H
#include <stdint.h>
#define MAX_NAME_LEN 255

#define CHECK_ALLOCATION(ptr) \
    if (ptr == NULL) { \
        printf("Memory allocation failed\n"); \
        exit(1); \
    }

typedef enum { NO_EDU, PRIMARY, SECONDARY, HIGHER } Education;
typedef enum { UNEMPLOYED, EMPLOYED } Employment;
typedef enum { SINGLE, MARRIED } Marital;
typedef unsigned char uchar;

typedef struct {
    char egn[11];
    uchar name_len;
    char *full_name;
    uchar age;
    uchar flags;      // 3 бита: образование (2), работен статус (1), сем. положение (1)
} Citizen;


Citizen readInput();
void printCitizen(Citizen* c);
uchar packFlags(Education edu, Employment emp, Marital mar);
void unpackFlags(uchar flags, Education* edu, Employment* emp, Marital* mar);

#endif
