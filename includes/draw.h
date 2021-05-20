#ifndef DRAW_H
#define DRAW_H

#include "grid.h"
#include <MLV/MLV_all.h>
#include <assert.h>

#define GRID_SCALE 100

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

void draw_image(MLV_Image *image, int x_pos, int y_pos);



#endif
