#include "../includes/player.h"

int getNumPlayer(Player *player){
	assert(player != NULL);
	return player->numPlayer;
}

char *getUserName(Player *player){
	assert(player != NULL);
	return player->name;
}

void setNumPlayer(Player *player, int num){
	assert(player != NULL);
	player->numPlayer = num;
}

void setImagePlayer(Player *player, MLV_Image *image){
	assert(player != NULL);
	assert(image != NULL);

	player->image = image;
}

void displayPlayer(Player *player){
	assert(player != NULL);
	printf("Player [name = %s, numPlayers = %d]\n", player->name, player->numPlayer);
}