#include "../includes/window.h"

/**
 * function to create a button
*/
Button *createButton(){
    Button *button = (Button *) malloc(sizeof(Button));
    button->image = NULL;
    button->message = NULL;
    return button;
}

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
void draw_buttons(Button *first_button, Button *second_button, Button *play){
    
    MLV_draw_image(image(first_button),x(first_button), y(first_button));
    MLV_draw_image(image(second_button), x(second_button), y(second_button));
    MLV_draw_adapted_text_box(x(play), y(play),message(play),0,MLV_COLOR_WHITE,MLV_COLOR_WHITE,MLV_COLOR_ROYAL_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
}

void resizeImage(MLV_Image *image, int width, int height){
    assert(image != NULL);
    MLV_resize_image_with_proportions(image,width,height);
}

void free_image(MLV_Image *image){
    MLV_free_image(image);
}

void close_window(){
    MLV_free_window();
}

/**
 * function to get x position of button
*/
int x(Button *button){
    assert(button != NULL);
    return button->x_pos;
}

/**
 * function to get y positino of button
*/
int y(Button *button){
    assert(button != NULL);
    return button->y_pos;
}

/**
 * function to get width of button
*/
int width(Button *button){
    assert(button != NULL);
    return button->width;
}

/**
 * function to get height of button
*/
int height(Button *button){
    assert(button != NULL);
    return button->height;
}

/**
 * function to get image of button
*/
MLV_Image *image(Button *button){
    assert(button != NULL);
    return button->image;
}

/**
 * function to get value of button
*/
int value(Button *button){
    assert(button != NULL);
    return button->value;
}

/**
 * function to get enable of button
*/
int enable(Button *button){
    assert(button != NULL);
    return button->enable;
}

/**
 * function to get message of button
*/
char *message(Button *button){
    assert(button != NULL);
    return button->message;
}

/**
 * Setters
*/

void setX(Button *button, int x){
    assert(button != NULL);
    button->x_pos = x;
}

/**
 * function to set y position of button
*/
void setY(Button *button, int y){
    assert(button != NULL);
    button->y_pos = y;
}

/**
 * function to set width of button
*/
void setWidth(Button *button, int width){
    assert(button != NULL);
    button->width = width;
}

/**
 * function to set height of button
*/
void setHeight(Button *button, int height){
    assert(button != NULL);
    button->height = height;
}

/**
 * function to set value of button
*/
void setValue(Button *button, int value){
    assert(button != NULL);
    button->value = value;
}

/**
 * function to set enable of button
*/
void setEnable(Button *button, int enable){
    assert(button != NULL);
    button->enable = enable;
}

/**
 * function to set message of button
*/
void setMessage(Button *button, char *message){
    assert(button != NULL);
    button->message = message;
}

/**
 * function to set image of button
*/
void setImage(Button *button, MLV_Image *image){
    assert(button != NULL);
    assert(image != NULL);
    button->image = image;
}