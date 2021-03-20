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
 * 
 * @param message texte dans le bouton
 * @param backgroundColor couleur de l'arrière-plan
 */
void draw_size_button(const char* message, MLV_Color backgroundColor){
    int window_width = MLV_get_window_width();
    int window_heigth = MLV_get_window_height();

    int x_button = window_width / 4;
    int y_button = window_width / 4;

    MLV_draw_adapted_text_box(x_button,y_button,message,0,NULL,MLV_COLOR_WHITE,backgroundColor,MLV_TEXT_LEFT);
    MLV_actualise_window();
}

void close_window(){
    MLV_free_window();
}