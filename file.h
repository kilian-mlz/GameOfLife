//
// Created by kilia on 26/03/2024.
//

#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

char** readInitialState(const char* filename, int* width, int* height);
void saveResultToFile(char** grid, int width, int height, const char* filename);

#endif
