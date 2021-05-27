#include "../includes/window.h"
#include "../includes/end.h"
#include <stdio.h>
#include <string.h>

#define WIDTH 500
#define HEIGHT 500

/**
 * @brief Fenêtre de fin
 * 
 */
void end_window(char *winner)
{
    strcat(winner, " IS THE WINNER\n\n\n\nTHANKS FOR PLAYING\0");
    create_window("End Game", 500, 500);
    MLV_draw_adapted_text_box(
        175, 200,
        winner,
        9,
        MLV_COLOR_ROYAL_BLUE, MLV_COLOR_WHITE, MLV_COLOR_ROYAL_BLUE,
        MLV_TEXT_CENTER);
    MLV_actualise_window();
    MLV_wait_seconds(20);
    close_window();
}