#include "../includes/window.h"
#include "../includes/menu.h"

void menu_window(){
    create_window("Menu Blocus", 500, 500);

    do{

    }while(!is_pressed_escape());

    close_window();
}