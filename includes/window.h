#ifndef WINDOW_H
#define WINDOW_H

#include <MLV/MLV_all.h>

typedef struct {
    int x_pos;
    int y_pos;
    int width;
    int height;
    MLV_Image *image;
    int value;
} Size_Button;

void create_window(const char* title, unsigned int width, unsigned int height);
int is_pressed_escape();
void close_window();
void draw_size_buttons(Size_Button *first_button, Size_Button *second_button);
void free_image(MLV_Image *image);

#endif