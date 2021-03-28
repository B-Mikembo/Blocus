#ifndef DRAW_H
#define DRAW_H

#include "grid.h"
#include <MLV/MLV_all.h>

#define GRID_SCALE 50

/**
 * @brief Draw a single cell
 * 
 * @param cell 
 */
void draw_cell(Cell *cell);

/**
 * @brief Draw the entire grid
 * 
 */
void draw_grid(Grid *grid);



#endif