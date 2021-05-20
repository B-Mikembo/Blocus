#ifndef WINDOW_H
#define WINDOW_H

#include <MLV/MLV_all.h>
#include "../includes/fichiers.h"
#include <assert.h>

typedef struct {
    int x_pos;
    int y_pos;
    int width;
    int height;
    MLV_Image *image;
    int value;
    int enable;
    char *message;
} Button;

Button *createButton();
void create_window(const char* title, unsigned int width, unsigned int height);
int is_pressed_escape();
void close_window();

MLV_Image *image(Button *image);

void draw_buttons(Button *first_button, Button *second_button, Button *play);
void resizeImage(MLV_Image *image, int width, int height);
void free_image(MLV_Image *image);

/**
 * Getters
*/
int x(Button *button);
int y(Button *button);
int width(Button *button);
int height(Button *button);
int value(Button *button);
int enable(Button *button);
char *message(Button *button);
MLV_Image *image(Button *image);

/**
 * Setters
*/
void setX(Button *button, int x);
void setY(Button *button, int y);
void setWidth(Button *button, int width);
void setHeight(Button *button, int height);
void setValue(Button *button, int value);
void setEnable(Button *button, int enable);
void setMessage(Button *button, char *message);
void setImage(Button *button, MLV_Image *image);

#endif
