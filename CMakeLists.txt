cmake_minimum_required(VERSION 3.27)
project(TPSPRINT C)

set(CMAKE_C_STANDARD 11)

add_executable(TPSPRINT main.c
        grid.c
        grid.h
        file.h
        simulation.c
        simulation.h
        file.c)

