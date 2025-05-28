#include <stdio.h>
#include "maze.h"
#include "astar.h"

int ROWS, COLS;

int main() {
    char **maze;
    Node *nodes[MAX_ROWS][MAX_COLS];
    Point start, end;

    loadMaze("maze.txt", &maze, nodes, &start, &end);
    printf("Original maze:\n");
    printMaze(maze);

    aStar(start, end, maze, nodes, ROWS, COLS);

    printf("\nSolved maze:\n");
    printMaze(maze);

    freeMaze(maze, nodes);
    return 0;
}
