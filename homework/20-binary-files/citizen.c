#include "citizen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Citizen readInput() {
    Citizen c;
    int edu;
    int emp;
    int mar;
    printf("\nEGN: ");
    scanf("%10s", c.egn);
    getchar();
    char buffer[MAX_NAME_LEN + 1];
    printf("\nFull name: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    c.name_len = strlen(buffer);
    c.full_name = malloc(c.name_len + 1);
    CHECK_ALLOCATION(c.full_name);
    strcpy(c.full_name, buffer);
    printf("\nAge: ");
    scanf("%hhu", &c.age);
    printf("\nEducation (0:None, 1:Primary, 2:Secondary, 3:Higher): ");
    scanf("%d", &edu);
    printf("\nEmployment status (0:Unemployed, 1:Employed): ");
    scanf("%d", &emp);
    printf("\nMarital status (0:Single, 1:Married): ");
    scanf("%d", &mar);
    c.flags = packFlags((Education)edu, (Employment)emp, (Marital)mar);
    return c;
}

void printCitizen(Citizen* c) {
    Education edu;
    Employment emp;
    Marital mar;
    unpackFlags(c->flags, &edu, &emp, &mar);

    printf("EGN: %s\n", c->egn);
    printf("Name: %s\n", c->full_name);
    printf("Age: %hhu\n", c->age);

    char* edu_str[] = {"None", "Primary", "Secondary", "Higher"};
    char* emp_str[] = {"Unemployed", "Employed"};
    char* mar_str[] = {"Single", "Married"};

    printf("Education: %s\n", edu_str[edu]);
    printf("Employment status: %s\n", emp_str[emp]);
    printf("Marital status: %s\n", mar_str[mar]);
}

uchar packFlags(Education edu, Employment emp, Marital mar) {
    return (edu & 3) | ((emp & 1) << 2) | ((mar & 1) << 3);
}

void unpackFlags(uchar flags, Education *edu, Employment *emp, Marital *mar) {
    *edu = (Education)(flags & 3);
    *emp = (Employment)((flags >> 2) & 1);
    *mar = (Marital)((flags >> 3) & 1);
}

void releaseCitizen(Citizen* c) {
    if (c->full_name != NULL) {
        free(c->full_name);
        c->full_name = NULL;
    }
}