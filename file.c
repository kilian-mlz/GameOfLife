//
// Created by kilia on 26/03/2024.
//

#include "file.h"

char** readInitialState(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier %s\n", filename);
        return NULL;
    }

    if (fscanf(file, "%d %d", width, height) != 2) {
        printf("Erreur: Donnees insuffisantes dans le fichier pour les dimensions de la grille.\n");
        fclose(file);
        return NULL;
    }

    char** grid = (char**)malloc((*height) * sizeof(char*));
    for (int i = 0; i < *height; i++) {
        grid[i] = (char*)malloc((*width) * sizeof(char));
        if (fscanf(file, "%s", grid[i]) != 1) {
            printf("Erreur: Donnees insuffisantes dans le fichier pour le contenu de la grille.\n");
            fclose(file);
            freeGrid(grid, *height);
            return NULL;
        }
    }

    fclose(file);
    return grid;
}
void saveResultToFile(char** grid, int width, int height, const char* filename) {
    FILE *resultFile = fopen(filename, "w");
    if (resultFile == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier de résultat.\n");
        return;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
                    fprintf(resultFile, "%c ", grid[i][j]);
        }
        fputc('\n', resultFile);
    }
    fclose(resultFile);
    printf("Resultat enregistrer avec succes dans le fichier 'result.txt'.");
}
