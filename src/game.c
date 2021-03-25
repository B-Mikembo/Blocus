#include "../includes/window.h"
#include "../includes/menu.h"
#include "../includes/game.h"

#define WIDTH 500
#define HEIGHT 750

void display_grid(int size){
    create_window("Blocus", WIDTH, HEIGHT);
    int x_start = 25;
    int x_end = WIDTH- 25;
    int y_start = 200;
    int y_end = HEIGHT-100;
    int grid_size = x_end-x_start;

    /*Crée les contours de la grille*/
    MLV_draw_line(x_start, y_start, x_end, y_start, MLV_COLOR_WHITE);
    MLV_draw_line(x_start, y_start, x_start, y_end, MLV_COLOR_WHITE);
    MLV_draw_line(x_end, y_start, x_end, y_end, MLV_COLOR_WHITE);
    MLV_draw_line(x_start, y_end, x_end, y_end, MLV_COLOR_WHITE);

    int cell_size = grid_size/size;
    int i;
    for(i=1; i<size; i++){
        MLV_draw_line(x_start+(cell_size*i), y_start, x_start+(cell_size*i), y_end, MLV_COLOR_WHITE);
        MLV_draw_line(x_start, y_start+(cell_size*i), x_end, y_start+(cell_size*i), MLV_COLOR_WHITE);
    } 

    MLV_actualise_window();
    MLV_wait_seconds( 60 );
}