#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

void loadMaze(char *filename, char ***mazePtr, Node *nodes[MAX_ROWS][MAX_COLS], Point *start, Point *end) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Cannot open maze file");
        exit(1);
    }

    char line[MAX_COLS + 2];
    char **maze = malloc(MAX_ROWS * sizeof(char*));
    ROWS = 0;

    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0';
        if (COLS == 0) COLS = strlen(line);
        maze[ROWS] = malloc(COLS + 1);
        strcpy(maze[ROWS], line);

        for (int c = 0; c < COLS; c++) {
            if (line[c] == 'S') *start = (Point){ROWS, c};
            if (line[c] == 'E') *end = (Point){ROWS, c};
            nodes[ROWS][c] = createNode(ROWS, c);
        }
        ROWS++;
    }

    fclose(file);
    *mazePtr = maze;
}

void printMaze(char **maze) {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", maze[i]);
    }
}

void freeMaze(char **maze, Node *nodes[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < ROWS; i++) {
        free(maze[i]);
        for (int j = 0; j < COLS; j++) {
            free(nodes[i][j]);
        }
    }
    free(maze);
}
