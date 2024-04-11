//
// Created by kilia on 26/03/2024.
//

#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "grid.h"

char** runIterations(char** grid, int width, int height, int numberOfIterations, int time);

#endif