#include "../includes/game.h"

Grid *grid;
MLV_Event event;
MLV_Mouse_button mouseButton;


void game_window(char *name_player1, char *name_player2, int grid_size){
    close_window();

    grid = create_grid(grid_size);

    event = MLV_NONE;

    create_window("Blocus", GRID_SCALE * grid_size, GRID_SCALE * grid_size);

    draw_grid(grid);

    do{

    }while(!is_pressed_escape());

    close_window();
}