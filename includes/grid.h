#ifndef GRID_H
#define GRID_H

#include <stdlib.h>
#include <MLV/MLV_all.h>

typedef struct
{
    int x_pos;
    int y_pos;
    int enabled;
    MLV_Color backgroundColor;
} Cell;

typedef struct
{
    Cell **cells;
    int size;
} Grid;

/**
 * @brief Allocate memory for a grid and initialize each cell
 * 
 */
Grid *create_grid(int size);

/**
 * @brief Free memory for a grid
 * 
 */
void free_grid(Grid *grid);

#endif