#include "../includes/window.h"
#include "../includes/menu.h"

#define WIDTH 500
#define HEIGHT 500
#define COLOR_BUTTON MLV_COLOR_RED

void menu_window(){
    create_window("Menu Blocus", WIDTH, HEIGHT);
    draw_size_buttons();
    
    do{
    
    }while(!is_pressed_escape());

    close_window();
}