#ifndef WINDOW_H
#define WINDOW_H

#include <MLV/MLV_all.h>

void create_window(const char* title, unsigned int width, unsigned int height);
int is_pressed_escape();
void close_window();
void draw_size_buttons();

#endif