#ifndef ASTAR_H
#define ASTAR_H

#include <stdbool.h>

typedef struct {
    int row;
    int col;
} Point;

typedef struct Node {
    Point pos;
    int gCost;
    int hCost;
    int fCost;
    struct Node *parent;
    bool inOpen;
    bool inClosed;
} Node;

int manhattan(Point a, Point b);
bool isValid(int row, int col, int ROWS, int COLS, char **maze);
Node *createNode(int row, int col);
void reconstructPath(Node *endNode, char **maze);
void aStar(Point start, Point end, char **maze, Node *nodes[100][100], int ROWS, int COLS);

#endif
