//
// Created by kilia on 26/03/2024.
//

#ifndef TPSPRINT_GRID_H
#define TPSPRINT_GRID_H

#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

char** createGrid(int width, int height);
void freeGrid(char** grid, int height);
void printGrid(char** grid, int width, int height, int iteration);
int countNeighbors(char** grid, int x, int y, int width, int height);
void nextIteration(char** currentGrid, char** nextGrid, int width, int height);

#endif //TPSPRINT_GRID_H
