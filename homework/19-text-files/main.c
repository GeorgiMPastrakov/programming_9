#include "hashmap.h"

void loadBooksFromFile(HashMap *map, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existing data found.\n");
        return;
    }

    Book b;
    while (fscanf(file, "%s %s %s %d %s", b.title, b.author, b.genre, &b.year, b.isbn) == 5) {
        insert(map, &b);
    }
    fclose(file);
}

void saveBooksToFile(HashMap *map, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (uint i = 0; i < map->bucketCnt; i++) {
        HashNode *node = map->bucket[i];
        while (node != NULL) {
            Book *b = &node->book;
            fprintf(file, "%s %s %s %d %s\n", b->title, b->author, b->genre, b->year, b->isbn);
            node = node->next;
        }
    }
    fclose(file);
    printf("Books saved successfully.\n");
}

void addBookMenu(HashMap *map) {
    Book b;
    printf("Enter book title (no spaces): ");
    scanf("%s", b.title);
    printf("Enter author: ");
    scanf("%s", b.author);
    printf("Enter genre: ");
    scanf("%s", b.genre);
    printf("Enter year: ");
    scanf("%d", &b.year);
    printf("Enter ISBN: ");
    scanf("%s", b.isbn);

    insert(map, &b);
}

void deleteBookMenu(HashMap *map) {
    char isbn[20];
    printf("Enter ISBN to delete: ");
    scanf("%s", isbn);
    erase(map, isbn);
}

int main() {
    HashMap map = initMap(29);

    loadBooksFromFile(&map, "library.txt");

    int choice;
    while (1) {
        printf("\n--- Electronic Library Menu ---\n");
        printf("1. Add new book\n");
        printf("2. Show all books\n");
        printf("3. Delete book by ISBN\n");
        printf("4. Save books to file\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBookMenu(&map);
                break;
            case 2:
                printAllBooks(&map);
                break;
            case 3:
                deleteBookMenu(&map);
                break;
            case 4:
                saveBooksToFile(&map, "library.txt");
                break;
            case 5:
                saveBooksToFile(&map, "library.txt");
                release(&map);
                printf("Exiting \n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }

    }

    return 0;
}
