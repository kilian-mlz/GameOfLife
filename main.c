#include <stdio.h>
#include "grid.h"
#include "simulation.h"
#include "file.h"

int main(int argc, char *arg[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <number of iterations>\n", arg[0]);
        return 1;
    }
    const char* filename = arg[1];
    int width;
    int height;
    int time;
    char** grid = readInitialState(filename, &width, &height);
    if (grid == NULL) {
        return 1;
    }

    int numberOfIterations = atoi(arg[2]);

    printf("Combien de temps entre chaque iterations (en ms, 1s = 1000ms)?\n");
    scanf("%d", &time);

    char** lastGrid = runIterations(grid, width, height, numberOfIterations, time);

    printf("Resultat final :\n");
    printGrid(lastGrid, width, height, numberOfIterations);

    saveResultToFile(lastGrid, width, height, "../result.txt");

    if (lastGrid != NULL) {
        freeGrid(lastGrid, height);
    }

    freeGrid(grid, height);

    return 0;
}