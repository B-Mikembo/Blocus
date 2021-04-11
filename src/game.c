#include "../includes/game.h"

Grid *grid;
Player *player1;
Player *player2;
Cell *last_cell_player1;
Cell *last_cell_player2;
MLV_Mouse_button mouseButton;

int numTour = 1;
int nextStep = 0;

Player *createPlayer(char *name, int num, MLV_Image *image)
{
    Player *player = (Player *)malloc(sizeof(Player));
    player->name = name;
    player->numPlayer = num;
    player->image = image;
    MLV_resize_image_with_proportions(player->image, TAILLE_BLOC, TAILLE_BLOC);
    player->position = (PositionPlayer *)malloc(sizeof(PositionPlayer));

    return player;
}

void drawRectangle(int x, int y)
{
    MLV_draw_filled_rectangle(
        TAILLE_BLOC * x,
        TAILLE_BLOC * y,
        TAILLE_BLOC,
        TAILLE_BLOC,
        MLV_COLOR_WHITE);

    MLV_draw_rectangle(
        TAILLE_BLOC * x,
        TAILLE_BLOC * y,
        TAILLE_BLOC,
        TAILLE_BLOC,
        MLV_COLOR_BLACK);
}

void drawMap(int **map, int size)
{
    int i;
    int j;
    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size; i++)
        {
            drawRectangle(i, j);
        }
    }
    MLV_actualise_window();
}

int available_cell(Grid *g, int x, int y)
{
    if (g->cells[x][y].available == 1)
    {
        return 1;
    }
    return 0;
}

void lock_cell(Grid *g, int x, int y)
{
    g->cells[x][y].available = 0;
}

void unlock_cell(Grid *g, int x, int y)
{
    g->cells[x][y].available = 1;
}

int **createMap(int size)
{
    int **map = (int **)malloc(size * sizeof(int *));
    int i, j;
    for (i = 0; i < size; i++)
    {
        map[i] = (int *)malloc(size * sizeof(int));
    }

    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size; i++)
        {
            map[i][j] = VIDE;
        }
    }

    return map;
}

Player *currentPlayer(Player *player_1, Player *player_2, int tour)
{
    if (tour % 2 == 0)
    {
        return player_2;
    }
    else
    {
        return player_1;
    }
}

void game_window(char *name_player1, char *name_player2, int grid_size)
{
    create_window("Blocus", TAILLE_BLOC * grid_size, TAILLE_BLOC * grid_size);

    int **map = createMap(grid_size);
    drawMap(map, grid_size);
    int continuer = 1;
    int tour = 1;
    MLV_Event event = MLV_NONE;
    MLV_Keyboard_button keyboardButton = MLV_NONE;
    Player *player_1 = createPlayer(name_player1, 1, MLV_load_image("img/blue_man.png"));
    Player *player_2 = createPlayer(name_player2, 2, MLV_load_image("img/orange_man.png"));
    placementPlayer(player_1, map, grid_size);
    placementPlayer(player_2, map, grid_size);

    do
    {

        printf("C'est au tour de %s de jouer\n", currentPlayer(player_1, player_2, tour)->name);

        tour++;

    } while (!is_pressed_escape());

    close_window();
}

/**
 * @brief Placement step function, at the begining of the game
 * 
 * @param player 
 * @param map 
 * @param size 
 */
void placementPlayer(Player *player, int **map, int size)
{
    printf("%s, veuillez placer votre pion sur la grille\n", player->name);
    int nextStep = 0;
    int xPixel;
    int yPixel;
    int x_position;
    int y_position;
    MLV_Event placementEvent = MLV_NONE;
    do
    {
        placementEvent = MLV_wait_event(
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            &xPixel,
            &yPixel,
            NULL,
            NULL);

        if (placementEvent == MLV_MOUSE_BUTTON)
        {
            x_position = xPixel / TAILLE_BLOC;
            y_position = yPixel / TAILLE_BLOC;
            if (x_position >= 0 && x_position < size && y_position >= 0 && y_position < size)
            {
                if (map[x_position][y_position] == VIDE)
                {

                    if (player->numPlayer == 1)
                    {
                        map[x_position][y_position] = PLAYER_1;
                    }
                    else
                    {
                        map[x_position][y_position] = PLAYER_2;
                    }
                    draw_image(player->image, x_position * TAILLE_BLOC, y_position * TAILLE_BLOC);
                    player->position->x = x_position;
                    player->position->y = y_position;
                    nextStep = 1;
                }
            }
        }

    } while (!nextStep);
    printf("Le pion de %s est placé\n", player->name);
}

int isOutsideMap(int x, int y, int size)
{
    return x < 0 || x >= size || y < 0 || y >= size;
}

int isNearbyCase(Player *player, int x, int y)
{
    return (x >= player->position->x - 1 && x <= player->position->x + 1 && x != player->position->x) && (y >= player->position->y - 1 && y <= player->position->y + 1 && y != player->position->y);
}

void movePlayer(int **map, Player *player, int size)
{
    printf("%s, déplacez votre pion sur une case adjacente\n", player->name);
    int nextStep = 0;
    MLV_Event moveEvent = MLV_NONE;
    int xPixel;
    int yPixel;
    int xPosition;
    int yPosition;

    do
    {
        moveEvent = MLV_wait_event(
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            &xPixel,
            &yPixel,
            NULL,
            NULL);

        if (moveEvent == MLV_MOUSE_BUTTON)
        {
            xPosition = xPixel / TAILLE_BLOC;
            yPosition = yPixel / TAILLE_BLOC;
            if (!isOutsideMap(xPosition, yPosition, size))
            {
                if (isNearbyCase(player, xPosition, yPosition))
                {
                    if (map[xPosition][yPosition] == VIDE)
                    {
                        /**
                         * @brief On vide la case actuel du joueur en redessinant la case puis en lui assignant la valeur VIDE
                         * 
                         */
                        drawRectangle(player->position->x, player->position->y);
                        map[player->position->x][player->position->y] == VIDE;

                        /**
                         * @brief On rempli la case cible par le joueur de la même maniere mais en assignant PLAYER_1 ou PLAYER_2
                         * 
                         */
                        
                    }
                }

                if (player->numPlayer == 1 && isNearbyCase(last_cell_player1, target))
                {
                    unlock_cell(grid, last_cell_player1->x_pos, last_cell_player1->y_pos);
                    draw_image(player1->image, target->x_pos * TAILLE_BLOC, target->y_pos * TAILLE_BLOC);
                    last_cell_player1 = target;
                    lock_cell(grid, target->x_pos, target->y_pos);
                    numTour++;
                    nextStep = 1;
                }
                else if (isNearbyCase(last_cell_player2, target))
                {
                    unlock_cell(grid, last_cell_player2->x_pos, last_cell_player2->y_pos);
                    draw_image(player2->image, target->x_pos * TAILLE_BLOC, target->y_pos * TAILLE_BLOC);
                    last_cell_player2 = target;
                    lock_cell(grid, target->x_pos, target->y_pos);
                    numTour++;
                    nextStep = 1;
                }
            }
        }
    } while (!nextStep);
}