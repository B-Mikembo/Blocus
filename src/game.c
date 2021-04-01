#include "../includes/game.h"

Grid *grid;
Player *player1;
Player *player2;
MLV_Event event;
MLV_Mouse_button mouseButton;

int numTour = 0;

void init_player(char *name1, char *name2)
{
    player1 = (Player *)malloc(sizeof(Player));
    player2 = (Player *)malloc(sizeof(Player));

    player1->name = name1;
    player2->name = name2;

    setNumPlayer(player1, 1);
    setNumPlayer(player2, 2);

    setImagePlayer(player1, MLV_load_image("img/blue_man.png"));
    resizeImage(player1->image, GRID_SCALE, GRID_SCALE);
    setImagePlayer(player2, MLV_load_image("img/orange_man.png"));
    resizeImage(player2->image, GRID_SCALE, GRID_SCALE);
}

void game_window(char *name_player1, char *name_player2, int grid_size)
{
    /*close_window();*/
    int x_pixel;
    int y_pixel;

    int last_x_pos1 = 0;
    int last_y_pos1 = 0;

    int last_x_pos2 = 0;
    int last_y_pos2 = 0;

    grid = create_grid(grid_size);

    event = MLV_NONE;

    create_window("Blocus", GRID_SCALE * grid_size, GRID_SCALE * grid_size);

    init_player(name_player1, name_player2);

    draw_grid(grid);

    do
    {
        event = MLV_wait_event(
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            &x_pixel,
            &y_pixel,
            &mouseButton,
            NULL);

        if (event == MLV_MOUSE_BUTTON)
        {
            int x_pos = x_pixel / GRID_SCALE;
            int y_pos = y_pixel / GRID_SCALE;

            if ((numTour % 2) == 0)
            {
                draw_cell(&grid->cells[last_x_pos1][last_y_pos1]);
                draw_image(player1->image, x_pos * GRID_SCALE, y_pos * GRID_SCALE);

                last_x_pos1 = x_pos;
                last_y_pos1 = y_pos;
                printf("Player 1\n");
            }
            else
            {
                draw_cell(&grid->cells[last_x_pos2][last_y_pos2]);
                draw_image(player2->image, x_pos * GRID_SCALE, y_pos * GRID_SCALE);

                last_x_pos2 = x_pos;
                last_y_pos2 = y_pos;
                printf("Player 2\n");
            }

            numTour++;
        }

    } while (!is_pressed_escape());

    close_window();
}