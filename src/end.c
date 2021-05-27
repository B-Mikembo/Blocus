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
    char* end_msg;
    char* msg = " IS THE WINNER\n\n\n\nTHANKS FOR PLAYING";

    end_msg = (char*)malloc(strlen(winner) + 1 + strlen(msg) + 1);
    strcpy(end_msg, winner);
    strcat(end_msg, msg);
    create_window("End Game", 500, 500);
    MLV_draw_adapted_text_box(
        175, 200,
        end_msg,
        9,
        MLV_COLOR_ROYAL_BLUE, MLV_COLOR_WHITE, MLV_COLOR_ROYAL_BLUE,
        MLV_TEXT_CENTER);
    MLV_actualise_window();
    MLV_wait_seconds(20);
    close_window();
}