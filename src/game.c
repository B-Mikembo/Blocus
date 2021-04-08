#include "../includes/game.h"

Grid *grid;
Player *player1;
Player *player2;
MLV_Event event;
MLV_Mouse_button mouseButton;

int numTour = 1;

void init_player(char *name1, char *name2)
{
    player1 = (Player *)malloc(sizeof(Player));
    player2 = (Player *)malloc(sizeof(Player));

    player1->name = name1;
    player1->status = 1;
    player1->block = 0;
    player2->name = name2;
    player2->status = 0;
    player2->block = 0;

    setNumPlayer(player1, 1);
    setNumPlayer(player2, 2);

    setImagePlayer(player1, MLV_load_image("img/blue_man.png"));
    resizeImage(player1->image, GRID_SCALE, GRID_SCALE);
    setImagePlayer(player2, MLV_load_image("img/orange_man.png"));
    resizeImage(player2->image, GRID_SCALE, GRID_SCALE);

    setCrossPlayer(player1, MLV_load_image("img/blue_cross.png"));
    resizeImage(player1->cross, GRID_SCALE, GRID_SCALE);
    setCrossPlayer(player2, MLV_load_image("img/red_cross.png"));
    resizeImage(player2->cross, GRID_SCALE, GRID_SCALE);
}

int available_cell(Grid *g, int x, int y){
    if(g->cells[x][y].available == 1){
        return 1;
    }
    return 0;
}

void lock_cell(Grid *g, int x, int y){
    g->cells[x][y].available = 0;
}

void unlock_cell(Grid *g, int x, int y){
    g->cells[x][y].available = 1;
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
        printf("nombre de tour : %d\n", numTour);
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

            if (player1->status == 1 )
            {
                if(available_cell(grid, x_pos, y_pos) == 1){
                    draw_cell(&grid->cells[last_x_pos1][last_y_pos1]);
                    unlock_cell(grid, last_x_pos1, last_y_pos1);
                    draw_image(player1->image, x_pos * GRID_SCALE, y_pos * GRID_SCALE);
                    lock_cell(grid, x_pos, y_pos);

                    last_x_pos1 = x_pos;
                    last_y_pos1 = y_pos;
                    printf("Player 1 -> x_pos : %d   y_pos : %d\n", x_pos, y_pos);

                    player1->block = 1;
                    player1->status = 0;

                }
            }

            int x_block = x_pixel / GRID_SCALE;
            int y_block = y_pixel / GRID_SCALE;

            if (player1->block == 1)
            {
                if(available_cell(grid, x_block, y_block) == 1){
                    printf("JE suis dans la boucle car block = : %d\n", player1->block);
                    lock_cell(grid, x_block, y_block);
                    draw_image(player1->cross, x_block * GRID_SCALE, y_block* GRID_SCALE);
                    
                    player1->block = 0;
                    player2->status = 1;
                    numTour++;
                }
            }

            if(player2->status == 1)
            {
                if(available_cell(grid, x_pos, y_pos) == 1){
                    draw_cell(&grid->cells[last_x_pos2][last_y_pos2]);
                    unlock_cell(grid, last_x_pos2, last_y_pos2);
                    draw_image(player2->image, x_pos * GRID_SCALE, y_pos * GRID_SCALE);
                    lock_cell(grid, x_pos, y_pos);

                    last_x_pos2 = x_pos;
                    last_y_pos2 = y_pos;
                    printf("Player 2 -> x_pos : %d   y_pos : %d\n", x_pos, y_pos);
                    player2->status = 0;
                    player2->block = 1;
                }
            }

            if (player2->block == 1)
            {
                if(available_cell(grid, x_block, y_block) == 1){
                    printf("JE suis dans la boucle car block = : %d\n", player2->block);
                    lock_cell(grid, x_block, y_block);
                    draw_image(player2->cross, x_block * GRID_SCALE, y_block* GRID_SCALE);
                    
                    player2->block = 0;
                    player1->status = 1;
                    numTour++;
                }
            }

            
            MLV_wait_milliseconds(100);
        }

    } while (!is_pressed_escape());

    close_window();
}
