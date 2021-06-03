#ifndef GAME_H
#define GAME_H

#include <MLV/MLV_all.h>

#include "window.h"
#include "constantes.h"
#include "draw.h"
#include "end.h"

/**
 * @brief Structure pour la position d'un joueur comprennant une postion en x et y
 * 
 */

typedef struct
{
    int x;
    int y;
} PositionPlayer;

/**
 * @brief structure d'un joueur comprennant le nom, le numero, un sprit, son sprit de case bloquée et sa postion
 * 
 */

typedef struct
{
    char *name;
    int numPlayer;
    MLV_Image *image;
    MLV_Image *cross;
    PositionPlayer *position;
} Player;

/**
 * @brief Affiche la map sur la console
 * 
 * @param map map à afficher
 * @param size taille de la map
 */

void displayMap(int **map, int size);

/**
 * @brief Crée un objet de type map de taille donnée
 * 
 * @param size taille de la map voulue
 * @return une map 
 */

int **createMap(int size);

/**
 * @brief Crée un objet de type player
 * 
 * @param name nom du joueur
 * @param num numero du joueur 1 ou 2
 * @param image sprit du joueur
 * @param crossImage sprit de la case bloquée
 * @return un joueur
 */

Player *createPlayer(char *name, int num, MLV_Image *image, MLV_Image *crossImage);

/**
 * @brief Affiche une fenêtre contenant la grille de jeu
 * 
 * @param name_player1 joueur 1 de la partie
 * @param name_player2 joueur 2 de la partie
 * @param grid_size taille de la grille
 */

void game_window(char *name_player1, char *name_player2, int grid_size);

/**
 * @brief Regarde si la case en (x,y) est adjacente au joueur
 * 
 * @param player joueur 
 * @param x coordonnée x de la case à verifier
 * @param y coordonnée y de la case à verifier
 * @return 1 si la case est adjacente, 0 sinon
 */

int isNearbyCase(Player *player, int x, int y);

/**
 * @brief Déplace le joueur dans la grille
 * 
 * @param map map du jeu
 * @param player joeuur à déplacer
 * @param size taille de la map
 */

void movePlayer(int **map, Player *player, int size);

/**
 * @brief Vérifie si la case aux coordonnées (x,y) est en dehors de la map
 * 
 * @param x coordonnée x de la case à verifier
 * @param y coordonnée y de la case à verifier
 * @param size taille de la map
 * @return retrun 1 si la case est en dehors de la map, 0 sinon
 */

int isOutsideMap(int x, int y, int size);

/**
 * @brief Condamne la case sélectionnée par le joueur
 * 
 * @param map map de jeu
 * @param size taille de la map
 * @param player joueur qui bloque une case
 */

void condamnationPlayer(int **map, int size, Player *player);

/**
 * @brief Place en debut de partie le joueurs sur la map 
 * 
 * @param player joueur à placer
 * @param map map de jeu
 * @param size taille de la map
 */

void placementPlayer(Player *player, int **map, int size);

/**
 * @brief Dessine la grille dans le fenêtre de jeu
 * 
 * @param map map à afficher
 * @param size taille de la map
 */

void drawMap(int **map, int size);

/**
 * @brief Dessine un rectangle aux coordonnées (x,y)
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 */

void drawRectangle(int x, int y);

/**
 * @brief Actualise le joueur courant en fonction du numéro du tour
 * 
 * @param player_1 joueur 2
 * @param player_2 joueur 2
 * @param tour numéro du tour
 * @return le joueur courant
 */

Player *currentPlayer(Player *player_1, Player *player_2, int tour);

/**
 * @brief Parcours la grille pour savoir si le joueur courant est bloqué
 * 
 * @param player joueur courant
 * @param map map de jeu
 * @param size taille de la map
 * @return return 1 si le joueur est bloqué, 0 sinon
 */

int winTest(Player * player, int **map, int size);

#endif
