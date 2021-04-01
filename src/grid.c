#include "../includes/grid.h"

Grid *create_grid(int size)
{
    int i;
    int j;

    Grid *grid = (Grid *)malloc(sizeof(Grid));
    grid->size = size;
    grid->cells = (Cell **)malloc(size * sizeof(Cell *));

    for(i = 0; i < size; i++){
        grid->cells[i] = (Cell *)malloc(size * sizeof(Cell));
    }

    for(j = 0; j < size; j++){
        for(i = 0; i < size; i++){
            grid->cells[i][j].x_pos = i;
            grid->cells[i][j].y_pos = j;
            grid->cells[i][j].enabled = 1;
            grid->cells[i][j].backgroundColor = NULL;
        }
    }

    return grid;
}

void free_grid(Grid *grid){
    int i;
    
    for(i = 0; i < grid->size; i++){
        free(grid->cells[i]);
    }

    free(grid->cells);
    free(grid);
}