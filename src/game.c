#include "../includes/game.h"

Player *player1;
Player *player2;
MLV_Mouse_button mouseButton;
int continuer;
int numTour = 1;
int nextStep = 0;

Player *createPlayer(char *name, int num, MLV_Image *image, MLV_Image *crossImage)
{
    Player *player = (Player *)malloc(sizeof(Player));
    player->name = name;
    player->numPlayer = num;
    player->image = image;
    player->cross = crossImage;
    MLV_resize_image_with_proportions(player->image, TAILLE_BLOC, TAILLE_BLOC);
    MLV_resize_image_with_proportions(player->cross, TAILLE_BLOC, TAILLE_BLOC);
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

int available_cell(int **map, int x, int y)
{
    return map[y][x] == VIDE;
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
    create_window("Blocus", TAILLE_BLOC * grid_size + 100, TAILLE_BLOC * grid_size);
    int **map = createMap(grid_size);
    drawMap(map, grid_size);
    continuer = 1;
    int tour = 1;
    Player *player_1 = createPlayer(name_player1, 1, MLV_load_image("img/blue_man.png"), MLV_load_image("img/blue_cross.png"));
    Player *player_2 = createPlayer(name_player2, 2, MLV_load_image("img/orange_man.png"), MLV_load_image("img/red_cross.png"));
    placementPlayer(player_1, map, grid_size);
    placementPlayer(player_2, map, grid_size);

    do
    {
        displayMap(map, grid_size);
        if (!winTest(currentPlayer(player_1, player_2, tour), map, grid_size))
        {
            printf("C'est au tour de %s de jouer\n", currentPlayer(player_1, player_2, tour)->name);
            if (tour % 2 != 0)
            {
                movePlayer(map, player_1, grid_size);
                condamnationPlayer(map, grid_size, player_1);
            }
            else
            {
                movePlayer(map, player_2, grid_size);
                condamnationPlayer(map, grid_size, player_2);
            }
            tour++;
        }
    } while (continuer);
    printf("Fin de la partie !\n");
    close_window(map, grid_size);
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
    return x >= player->position->x - 1 && x <= player->position->x + 1 && y >= player->position->y - 1 && y <= player->position->y + 1;
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
                    if (map[yPosition][xPosition] == VIDE)
                    {
                        /**
                         * @brief On vide la case actuel du joueur en redessinant la case puis en lui assignant la valeur VIDE
                         * 
                         */
                        drawRectangle(player->position->x, player->position->y);
                        map[player->position->y][player->position->x] = VIDE;

                        /**
                         * @brief On rempli la case cible par le joueur de la même maniere mais en assignant PLAYER_1 ou PLAYER_2
                         * 
                         */
                        draw_image(player->image, xPosition * TAILLE_BLOC, yPosition * TAILLE_BLOC);
                        if (player->numPlayer == 1)
                        {
                            map[yPosition][xPosition] = PLAYER_1;
                        }
                        else
                        {
                            map[yPosition][xPosition] = PLAYER_2;
                        }
                        player->position->x = xPosition;
                        player->position->y = yPosition;
                        nextStep = 1;
                    }
                    else
                    {
                        printf("Cette case n'est pas vide !\n");
                    }
                }
                else
                {
                    printf("Ce n'est pas une case adjacente !\n");
                }
            }
            else
            {
                printf("Ce n'est pas une case de la grille\n!");
            }

            MLV_wait_milliseconds(100);
        }
    } while (!nextStep);
}

void condamnationPlayer(int **map, int size, Player *player)
{
    printf("%s, condamner une case libre\n", player->name);
    int nextStep = 0;
    MLV_Event condamnationEvent = MLV_NONE;
    int xPixel;
    int yPixel;
    int xPosition;
    int yPosition;
    do
    {
        condamnationEvent = MLV_wait_event(
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            &xPixel,
            &yPixel,
            NULL,
            NULL);

        if (condamnationEvent == MLV_MOUSE_BUTTON)
        {
            xPosition = xPixel / TAILLE_BLOC;
            yPosition = yPixel / TAILLE_BLOC;
            if (!isOutsideMap(xPosition, yPosition, size))
            {

                if (map[yPosition][xPosition] == VIDE)
                {
                    /**
                         * @brief On rempli la case cible par le joueur de la même maniere mais en assignant PLAYER_1 ou PLAYER_2
                         * 
                         */
                    draw_image(player->cross, xPosition * TAILLE_BLOC, yPosition * TAILLE_BLOC);
                    if (player->numPlayer == 1)
                    {
                        map[yPosition][xPosition] = CROSS;
                    }
                    else
                    {
                        map[yPosition][xPosition] = CROSS;
                    }
                    nextStep = 1;
                }
                else
                {
                    printf("Cette case n'est pas vide !\n");
                }
            }
            else
            {
                printf("Ce n'est pas une case de la grille\n!");
            }
        }
    } while (!nextStep);
}

int winTest(Player *player, int **map, int size)
{
    int x, y;

    for (y = player->position->y - 1; y < player->position->y + 2; y++)
    {
        for (x = player->position->x - 1; x < player->position->x + 2; x++)
        {
            if (!isOutsideMap(x,y,size) && map[y][x] == VIDE)
            {
                return 0;
            }
        }
    }
    continuer = 0;
    return 1;
}

void displayMap(int **map, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}