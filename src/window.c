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
/**
 * @brief Dessine un bouton pour régler la taille de la grille
 */
void draw_size_buttons(Size_Button *first_button, Size_Button *second_button){
    
    MLV_draw_image(first_button->image,first_button->x_pos, first_button->y_pos);
    MLV_draw_image(second_button->image,second_button->x_pos, second_button->y_pos);
    MLV_actualise_window();
}

void free_image(MLV_Image *image){
    MLV_free_image(image);
}

void close_window(){
    MLV_free_window();
}