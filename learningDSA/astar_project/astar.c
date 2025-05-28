#include <stdlib.h>
#include <stdio.h>
#include "astar.h"

int manhattan(Point a, Point b) {
    return abs(a.row - b.row) + abs(a.col - b.col);
}

bool isValid(int row, int col, int ROWS, int COLS, char **maze) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#';
}

Node *createNode(int row, int col) {
    Node *node = malloc(sizeof(Node));
    node->pos = (Point){row, col};
    node->gCost = node->hCost = node->fCost = 0;
    node->parent = NULL;
    node->inOpen = node->inClosed = false;
    return node;
}

void reconstructPath(Node *endNode, char **maze) {
    Node *current = endNode;
    while (current->parent && maze[current->pos.row][current->pos.col] != 'S') {
        maze[current->pos.row][current->pos.col] = '.';
        current = current->parent;
    }
}

void aStar(Point start, Point end, char **maze, Node *nodes[100][100], int ROWS, int COLS) {
    Node *openSet[10000];
    int openSize = 0;

    Node *startNode = nodes[start.row][start.col];
    startNode->gCost = 0;
    startNode->hCost = manhattan(start, end);
    startNode->fCost = startNode->hCost;
    startNode->inOpen = true;
    openSet[openSize++] = startNode;

    while (openSize > 0) {
        int bestIndex = 0;
        for (int i = 1; i < openSize; i++) {
            if (openSet[i]->fCost < openSet[bestIndex]->fCost)
                bestIndex = i;
        }

        Node *current = openSet[bestIndex];
        openSet[bestIndex] = openSet[--openSize];

        current->inClosed = true;

        if (current->pos.row == end.row && current->pos.col == end.col) {
            reconstructPath(current, maze);
            return;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = current->pos.row + dx[i];
            int nc = current->pos.col + dy[i];

            if (!isValid(nr, nc, ROWS, COLS, maze)) continue;

            Node *neighbor = nodes[nr][nc];
            if (neighbor->inClosed) continue;

            int tentativeG = current->gCost + 1;
            if (!neighbor->inOpen || tentativeG < neighbor->gCost) {
                neighbor->parent = current;
                neighbor->gCost = tentativeG;
                neighbor->hCost = manhattan(neighbor->pos, end);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;
                if (!neighbor->inOpen) {
                    neighbor->inOpen = true;
                    openSet[openSize++] = neighbor;
                }
            }
        }
    }

    printf("No path found.\n");
}