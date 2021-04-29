#include "../includes/window.h"
#include "../includes/menu.h"

#define WIDTH 500
#define HEIGHT 500

/**
 * Variables globales
*/
Button *three_button;
Button *nine_button;
Button *play_button;

int grid_size;

char *name_player1;
char *name_player2;

void free_button(Button *button)
{
    MLV_free_image(button->image);
    free(button);
}

/**
 * Vérification du click sur le bouton "Play"
*/
int check_into_play_button(int x_pos, int y_pos){
    int result = 0;

    if (x_pos >= play_button->x_pos && x_pos <= (play_button->x_pos + play_button->width))
    {
        if (y_pos >= play_button->y_pos && y_pos <= (play_button->y_pos + play_button->height))
        {
            result = 1;
        }
    }

    return result;
}

/**
 * @brief 
 * 
 * @param x_pos 
 * @param y_pos 
 * @return int 
 */
int check_into_three_button(int x_pos, int y_pos)
{
    int result = 0;

    if (x_pos >= three_button->x_pos && x_pos <= (three_button->x_pos + three_button->width))
    {
        if (y_pos >= three_button->y_pos && y_pos <= (three_button->y_pos + three_button->height))
        {
            result = 1;
        }
    }

    return result;
}

/**
 * @brief 
 * 
 * @param x_pos 
 * @param y_pos 
 * @return int 
 */
int check_into_nine_button(int x_pos, int y_pos)
{
    int result = 0;

    if (x_pos >= nine_button->x_pos && x_pos <= (nine_button->x_pos + nine_button->width))
    {
        if (y_pos >= nine_button->y_pos && y_pos <= (nine_button->y_pos + nine_button->height))
        {
            result = 1;
        }
    }

    return result;
}

/**
 * @brief Get the value of size button object
 * 
 * @param x_pos 
 * @param y_pos 
 * @param three_button 
 * @param nine_button 
 * @return int 
 */
int get_value_of_size_button(int x_pos, int y_pos)
{
    int size = 0;
    /**
     * @brief check du bouton de taille 3
     * 
     */
    if (check_into_three_button(x_pos, y_pos))
    {
        size = three_button->value;
    }

    /**
     * @brief check du bouton de taille 9
     * 
     */
    if (check_into_nine_button(x_pos, y_pos))
    {
        size = nine_button->value;
    }

    return size;
}

/**
 * @brief Initialise les boutons de réglage de la taille
 * 
 */
void init_size_buttons()
{
    /**
     * Allocation de mémoire pour les boutons
    */
    three_button = (Button *)malloc(sizeof(Button));
    nine_button = (Button *)malloc(sizeof(Button));
    play_button = (Button *)malloc(sizeof(Button));

    int width = WIDTH;
    int height = HEIGHT;

    /**
     * Initialisation du bouton "3"
    */
    three_button->value = 3;
    three_button->height = height / 4;
    three_button->width = width / 4;
    three_button->image = MLV_load_image("img/three.png");
    three_button->x_pos = width / 8;
    three_button->y_pos = height / 2;
    three_button->enable = 1;

    MLV_resize_image_with_proportions(three_button->image, three_button->width, three_button->height);

    /**
     * Initialisation du bouton "9"
    */
    nine_button->value = 9;
    nine_button->height = height / 4;
    nine_button->width = width / 4;
    nine_button->image = MLV_load_image("img/nine.png");
    nine_button->x_pos = (width / 2) + (width / 8);
    nine_button->y_pos = height / 2;
    nine_button->enable = 1;

    MLV_resize_image_with_proportions(nine_button->image, nine_button->width, nine_button->height);

    /**
     * Initialisation du bouton "Play"
    */
    int width_box = 0;
    int height_box = 0;
    play_button->message = "JOUER";
    MLV_get_size_of_adapted_text_box(play_button->message,0,&width_box, &height_box);
    play_button->value = 1;
    play_button->height = height_box;
    play_button->width = width_box;
    play_button->image = NULL;
    play_button->x_pos = (three_button->x_pos+three_button->width);
    play_button->y_pos = height - (height / 4);
    play_button->enable = 0;
    

}

void display_username(int width, int height)
{
    if(name_player1 == NULL){
        name_player1 = "";
    }

    if(name_player2 == NULL){
        name_player2 = "";
    }

    MLV_clear_window(MLV_COLOR_ROYAL_BLUE);
    MLV_draw_adapted_text_box(
        10, 10,
        "BLOCUS",
        9,
        MLV_COLOR_ROYAL_BLUE, MLV_COLOR_WHITE, MLV_COLOR_ROYAL_BLUE,
        MLV_TEXT_CENTER);
    MLV_draw_text(
        10, 150,
        name_player1,
        MLV_COLOR_WHITE);

    MLV_draw_text(
        220, 150,
        name_player2,
        MLV_COLOR_WHITE);

    MLV_draw_all_input_boxes();
    draw_buttons(three_button, nine_button, play_button);
    MLV_actualise_window();
}

/**
 * @brief Fenêtre du menu
 * 
 */
void menu_window()
{
    create_window("Menu Blocus", 500, 500);
    init_size_buttons();
    printf("x pos nine : %d\n", nine_button->x_pos);
    draw_buttons(three_button, nine_button, play_button);
    int width = 640, height = 460;
    char *texte, *texte1, *texte2;
    int x_pixel;
    int y_pixel;
    MLV_Input_box *input_box, *input_box_1, *input_box_2;
    MLV_Event event;

    input_box_1 = MLV_create_input_box(
        10, 100,
        200, 30,
        MLV_COLOR_WHITE, MLV_COLOR_WHITE,
        MLV_COLOR_ROYAL_BLUE, "JOUEUR 1 : ");
    texte1 = (char *)malloc(1 * sizeof(char));
    *texte1 = '\0';
    input_box_2 = MLV_create_input_box(
        220, 100,
        200, 30,
        MLV_COLOR_WHITE, MLV_COLOR_WHITE,
        MLV_COLOR_ROYAL_BLUE, "JOUEUR 2 : ");
    texte2 = (char *)malloc(1 * sizeof(char));
    *texte2 = '\0';
    display_username(width, height);
    do
    {
        event = MLV_get_event(
            NULL, NULL, NULL,
            &texte, &input_box,
            &x_pixel, &y_pixel, NULL,
            NULL);
        /**
         * Si input box est rempli
        */
        if (event == MLV_INPUT_BOX)
        {
            if (input_box == input_box_1)
            {
                free(texte1);
                texte1 = texte;
                name_player1 = texte1;
            }
            if (input_box == input_box_2)
            {
                free(texte2);
                texte2 = texte;
                name_player2 = texte2;
            }
        }

        /**
         * Si un click de souris
        */
        else if (event == MLV_MOUSE_BUTTON)
        {
            if(check_into_three_button(x_pixel,y_pixel) || check_into_nine_button(x_pixel,y_pixel)){
                grid_size = get_value_of_size_button(x_pixel, y_pixel);
                printf("%d\n", grid_size);
            }
            
            if(check_into_play_button(x_pixel, y_pixel) && play_button->enable){
                game_window(name_player1,name_player2, grid_size);
            }
        }
        
        if(name_player1 != NULL && name_player1 != "" && name_player2 != NULL && name_player2 != ""){
            if(grid_size != 0){
                play_button->enable = 1;
            }
        }
        display_username(width, height);
    } while (strcmp(texte2, "quit"));
    free(texte1);
    free(texte2);
    MLV_free_input_box(input_box_1);
    MLV_free_input_box(input_box_2);

    free_button(three_button);
    free_button(nine_button);
    free_button(play_button);
    close_window(NULL, 0);
}
