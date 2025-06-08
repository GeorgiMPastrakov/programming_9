#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citizen.h"

FILE *file = NULL;

void openFile(char *filename) {
    file = fopen(filename, "rb+");
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Error opening file %s\n", filename);
            exit(1);
        }
    }
}

void closeFile() {
    if (file != NULL) fclose(file);
}

void saveCitizen(Citizen *c) {
    fseek(file, 0, SEEK_END);
    fwrite(c->egn, sizeof(char), 10, file);
    fwrite(&c->name_len, sizeof(uchar), 1, file);
    fwrite(c->full_name, sizeof(char), c->name_len, file);
    fwrite(&c->age, sizeof(uchar), 1, file);
    fwrite(&c->flags, sizeof(uchar), 1, file);
    fflush(file);
}

void listCitizens() {
    rewind(file);
    while (1) {
        Citizen c;
        size_t read = fread(c.egn, sizeof(char), 10, file);
        if (read != 10) break;
        if (fread(&c.name_len, sizeof(uchar), 1, file) != 1) break;
        c.full_name = malloc(c.name_len + 1);
        if (!c.full_name || fread(c.full_name, sizeof(char), c.name_len, file) != c.name_len) break;
        c.full_name[c.name_len] = '\0';
        if (fread(&c.age, sizeof(uchar), 1, file) != 1) break;
        if (fread(&c.flags, sizeof(uchar), 1, file) != 1) break;
        printCitizen(&c);
        printf("\n");
        free(c.full_name);
    }
}

void deleteByEGN(char *targetEGN) {
    rewind(file);
    Citizen *records = NULL;
    size_t count = 0;
    while (1) {
        Citizen c;
        size_t read = fread(c.egn, sizeof(char), 10, file);
        if (read != 10) break;
        if (fread(&c.name_len, sizeof(uchar), 1, file) != 1) break;
        c.full_name = malloc(c.name_len + 1);
        if (!c.full_name || fread(c.full_name, sizeof(char), c.name_len, file) != c.name_len) break;
        c.full_name[c.name_len] = '\0';
        if (fread(&c.age, sizeof(uchar), 1, file) != 1) break;
        if (fread(&c.flags, sizeof(uchar), 1, file) != 1) break;
        if (strncmp(c.egn, targetEGN, 10) != 0) {
            records = realloc(records, sizeof(Citizen) * (count + 1));
            records[count++] = c;
        } 
        else {
            free(c.full_name);
        }
    }
    freopen(NULL, "wb+", file);
    for (size_t i = 0; i < count; ++i) {
        saveCitizen(&records[i]);
        free(records[i].full_name);
    }
    free(records);
}

int main() {
    char filename[256];
    printf("Enter binary data filename: ");
    scanf("%255s", filename);
    openFile(filename);

    int choice;
    do {
        printf("\n1. Add citizen\n2. List all citizens\n3. Delete by EGN\n0. Exit\nChoose: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            Citizen c = readInput();
            saveCitizen(&c);
            free(c.full_name);
        } else if (choice == 2) {
            listCitizens();
        } else if (choice == 3) {
            char egn[11];
            printf("Enter EGN to delete: ");
            scanf("%10s", egn);
            deleteByEGN(egn);
        }
    } while (choice != 0);

    closeFile();
    return 0;
}
