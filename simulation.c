//
// Created by kilia on 26/03/2024.
//

#include "simulation.h"

char** runIterations(char** grid, int width, int height, int numberOfIterations, int time) {
    char** lastGrid = NULL;

    int currentIteration = 0;
    while (currentIteration < numberOfIterations) {
        printGrid(grid, width, height, currentIteration);
        Sleep(time);

        char** nextGrid = (char**)malloc(height * sizeof(char*));
        for (int i = 0; i < height; i++) {
            nextGrid[i] = (char*)malloc(width * sizeof(char));
        }

        nextIteration(grid, nextGrid, width, height);

        if (currentIteration == numberOfIterations - 1){
            lastGrid = nextGrid;
        }else{
            freeGrid(grid, height);
        }
        grid = nextGrid;
        currentIteration++;
    }

    return lastGrid;
}