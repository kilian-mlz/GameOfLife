//
// Created by kilia on 26/03/2024.
//

#include "grid.h"

void freeGrid(char** grid, int height) {
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
}

void printGrid(char** grid, int width, int height, int iteration) {
    printf("Itération %d:\n", iteration);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 'X') {
                printf("%c ", grid[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(char** grid, int x, int y, int width, int height) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int newX = x + j;
            int newY = y + i;
            if (newX >= 0 && newX < width && newY >= 0 && newY < height && grid[newY][newX] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void nextIteration(char** currentGrid, char** nextGrid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            nextGrid[i][j] = currentGrid[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = countNeighbors(currentGrid, j, i, width, height);

            if (currentGrid[i][j] == 'X') {
                if (neighbors <= 1 || neighbors > 3) {
                    nextGrid[i][j] = '.';
                }
            } else {
                if (neighbors == 3) {
                    nextGrid[i][j] = 'X';
                }
            }
        }
    }
}
