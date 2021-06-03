#ifndef MENU_H
#define MENU_H

#include <MLV/MLV_all.h>
#include "../includes/game.h"

/**
 * @brief crée une fenêtre de menu
 * 
 */
void menu_window();

/**
 * @brief Affiche le nom des joueurs une fois les noms entrées
 * 
 * @param width largeur de la fenêtre
 * @param height hauteur de la fenêtre
 */
void display_username( int width, int height);

#endif