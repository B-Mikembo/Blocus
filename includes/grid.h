#ifndef GRID_H
#define GRID_H

#include <stdlib.h>
#include <MLV/MLV_all.h>

/**
 * @brief Crée une cellule
 * 
 */

typedef struct
{
    int x_pos;
    int y_pos;
    int available; /* 0 non 1 oui*/
    MLV_Color backgroundColor;
} Cell;

/**
 * @brief crée une grille
 * 
 */

typedef struct
{
    Cell **cells;
    int size;
} Grid;

/**
 * @brief Crée une grille de taille indiquée
 * 
 */

Grid *create_grid(int size);

/**
 * @brief Libère la grille
 * 
 */

void free_grid(Grid *grid);

int check_case_adjacente(Cell *source_cell, Cell *target_cell);

#endif