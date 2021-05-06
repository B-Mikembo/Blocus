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

void create_window(const char* title, unsigned int width, unsigned int height);
int is_pressed_escape();
void close_window();
void draw_buttons(Button *first_button, Button *second_button, Button *play);
void resizeImage(MLV_Image *image, int width, int height);
void free_image(MLV_Image *image);

#endif
