#include "../includes/game.h"

Grid *grid;
Player *player1;
Player *player2;
MLV_Event event;
MLV_Mouse_button mouseButton;

void init_player(char *name1, char *name2)
{
    player1 = (Player *)malloc(sizeof(Player));
    player2 = (Player *)malloc(sizeof(Player));

    player1->name = name1;
    player2->name = name2;

    setNumPlayer(player1, 1);
    setNumPlayer(player2, 2);
}

void game_window(char *name_player1, char *name_player2, int grid_size)
{
    /*close_window();*/

    grid = create_grid(grid_size);

    event = MLV_NONE;

    init_player(name_player1, name_player2);

    create_window("Blocus", GRID_SCALE * grid_size, GRID_SCALE * grid_size);

    draw_grid(grid);

    do
    {

    } while (!is_pressed_escape());

    close_window();
}