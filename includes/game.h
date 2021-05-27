#ifndef GAME_H
#define GAME_H

#include <MLV/MLV_all.h>

#include "window.h"
#include "constantes.h"
#include "draw.h"
#include "end.h"

typedef struct
{
    int x;
    int y;
} PositionPlayer;

typedef struct
{
    char *name;
    int numPlayer;
    MLV_Image *image;
    MLV_Image *cross;
    PositionPlayer *position;
} Player;

void displayMap(int **map, int size);
int **createMap(int size);
Player *createPlayer(char *name, int num, MLV_Image *image, MLV_Image *crossImage);
void game_window(char *name_player1, char *name_player2, int grid_size);
int isNearbyCase(Player *player, int x, int y);
void movePlayer(int **map, Player *player, int size);
int isOutsideMap(int x, int y, int size);
void condamnationPlayer(int **map, int size, Player *player);
void placementPlayer(Player *player, int **map, int size);
void drawMap(int **map, int size);
void drawRectangle(int x, int y);
Player *currentPlayer(Player *player_1, Player *player_2, int tour);
int winTest(Player * player, int **map, int size);

#endif
