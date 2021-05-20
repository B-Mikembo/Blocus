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
	MLV_Image *cross;
	int status; /*1 = joueur joue 0 = attend*/
	int block; /* 1 = joueur doit bloquer une case 0 = il ne fait rien */
} Player;

int getNumPlayer(Player *player);

char *getUserName(Player *player);

void setNumPlayer(Player *player, int num);

void setImagePlayer(Player *player, MLV_Image *image);

void setCrossPlayer(Player *player, MLV_Image *cross);

void displayPlayer(Player *player);

#endif