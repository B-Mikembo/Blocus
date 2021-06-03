#ifndef DRAW_H
#define DRAW_H

#include "grid.h"
#include <MLV/MLV_all.h>
#include <assert.h>

#define GRID_SCALE 100

/**
 * @brief Dessine une image à la postion (x,y)
 * 
 * @param image image à afficher
 * @param x_pos postion x de l'image (haut a gauche)
 * @param y_pos postion y de l'image (haut a gauche)
 */

void draw_image(MLV_Image *image, int x_pos, int y_pos);



#endif
