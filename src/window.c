#include <MLV/MLV_all.h>

#include "../includes/window.h"

/**
 * @brief Create a window without full screen
 * 
 * @param title 
 * @param width 
 * @param height 
 */
void create_window(const char* title, unsigned int width, unsigned int height){
    MLV_create_window(title,NULL,width,height);

    MLV_clear_window(MLV_COLOR_ROYAL_BLUE);
    MLV_actualise_window();
}

int is_pressed_escape(){
    MLV_Keyboard_button button;
    MLV_Event event;

    event = MLV_get_event(&button,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

    if(button == MLV_KEYBOARD_ESCAPE){
        return 1;
    }
    
    return 0;
}

void close_window(){
    MLV_free_window();
}