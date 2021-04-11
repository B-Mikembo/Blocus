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

void draw_image(MLV_Image *image, int x_pos, int y_pos){
    assert(image != NULL);
    MLV_draw_image(image, x_pos, y_pos);
    MLV_actualise_window();
}