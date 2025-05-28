#ifndef MAZE_H
#define MAZE_H

#include "astar.h"

#define MAX_ROWS 100
#define MAX_COLS 100

extern int ROWS;
extern int COLS;

void loadMaze(char *filename, char ***mazePtr, Node *nodes[MAX_ROWS][MAX_COLS], Point *start, Point *end);
void printMaze(char **maze);
void freeMaze(char **maze, Node *nodes[MAX_ROWS][MAX_COLS]);

#endif
