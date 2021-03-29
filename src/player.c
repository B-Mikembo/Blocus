#include "../includes/player.h"

int getNumPlayer(Player *player){
	assert(player != NULL);
	return player->numPlayers;
}

void setNumPlayers(Player *player, int num){
	assert(player != NULL);
	player->numPlayers = num;
}

void displayPlayer(Player *player){
	assert(player != NULL);
	printf("Player [name = %s, numPlayers = %d]\n", player->name, player->numPlayers);
}