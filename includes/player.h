#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MLV/MLV_all.h>

typedef struct {
	char *name;
	int numPlayer;
	MLV_Image *image;
	int status; /*1 = joueur joue 0 = attend*/
} Player;

int getNumPlayer(Player *player);

char *getUserName(Player *player);

void setNumPlayer(Player *player, int num);

void setImagePlayer(Player *player, MLV_Image *image);

void displayPlayer(Player *player);

#endif