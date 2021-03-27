#include "../includes/game.h"

void game_window(char *name_player1, char *name_player2, int grid_size){
    close_window();
    create_window("Blocus", 500, 500);
    do{

    }while(!is_pressed_escape());

    close_window();
}