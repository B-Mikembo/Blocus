#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
	char *name;
	int numPlayer;
} Player;

int getNumPlayer(Player *player);

void setNumPlayer(Player *player, int num);

void displayPlayer(Player *player);