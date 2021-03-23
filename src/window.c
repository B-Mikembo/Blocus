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
void draw_size_buttons(){
    int width = MLV_get_window_width();
    int height = MLV_get_window_height();
    int resizer = 4;
    
    MLV_Image *three_image = MLV_load_image("img/three.png");;
    MLV_Image *nine_image = MLV_load_image("img/nine.png");

    
    MLV_resize_image_with_proportions(three_image, width / resizer, height / resizer);
    MLV_resize_image_with_proportions(nine_image, width / resizer, height / resizer);


    int x_three = width / 8;
    int y_three = height / 2;

    int x_nine = (width / 2) + (width / 8);
    int y_nine = height / 2;
    /**
     * @brief Affichage de l'image
     * 
     */
    MLV_draw_image(three_image,x_three,y_three);
    MLV_draw_image(nine_image,x_nine,y_nine);
    MLV_actualise_window();
}

void close_window(){
    MLV_free_window();
}