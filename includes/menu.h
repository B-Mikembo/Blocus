#ifndef MENU_H
#define MENU_H

#define MENU_SCALE  2

#include <MLV/MLV_all.h>

typedef struct{
    int x_pos;
    int y_pos;
} Cell_Menu;

typedef struct{
    Cell_Menu **cells;
    int x_size;
    int y_size;
} Grid_Menu;

void menu_window();
void free_grid_menu(Grid_Menu *grid_menu);
void display_username( int width, int height, char* texte1, char* texte2 );

#endif