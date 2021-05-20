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
            grid->cells[i][j].available = 1;
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

int check_x_adjacent(int x_source, int x_target){
    if(x_target >= (x_source - 1) && x_target <= (x_source + 1)){
        return 1;
    }
    return 0;
}

int check_y_adjacent(int y_source, int y_target){
    if(y_target >= (y_source - 1) && y_target <= (y_source + 1)){
        return 1;
    }
    return 0;
}

/* Vérification si c'est une case adjacente */
int check_case_adjacente(Cell *source_cell, Cell *target_cell){
    int condition = 0;

    int x_source = source_cell->x_pos;
    int y_source = source_cell->y_pos;

    int x_target = target_cell->x_pos;
    int y_target = target_cell->y_pos;

    if(x_source != x_target && y_source != y_target){
        if(check_x_adjacent(x_source,x_target) && check_y_adjacent(y_source,y_target)){
            condition = 1;
        }
    }
    return condition;
}
