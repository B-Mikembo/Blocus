#include "../includes/draw.h"

void draw_rectangle(int x, int y){
    MLV_draw_filled_rectangle(
        GRID_SCALE*x,
        GRID_SCALE*y,
        GRID_SCALE,
        GRID_SCALE,
        MLV_COLOR_WHITE
    );

    MLV_draw_rectangle(
        GRID_SCALE*x,
        GRID_SCALE*y,
        GRID_SCALE,
        GRID_SCALE,
        MLV_COLOR_BLACK
    );
}

void draw_cell(Cell *cell){
    draw_rectangle(cell->x_pos, cell->y_pos);
    MLV_actualise_window();
}

void draw_grid(Grid *grid){
    int i;
    int j;
    for(i = 0; i < grid->size; i++){
        for(j = 0; j < grid->size; j++){
            draw_cell(&grid->cells[i][j]);
        }
    }
    MLV_actualise_window();
}