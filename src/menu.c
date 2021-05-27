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
    MLV_free_image(image(button));
    free(button);
}

/**
 * Vérification du click sur le bouton "Play"
*/
int check_into_play_button(int x_pos, int y_pos){
    int result = 0;

    if (x_pos >= x(play_button) && x_pos <= (x(play_button) + width(play_button)))
    {
        if (y_pos >= y(play_button) && y_pos <= (y(play_button) + height(play_button)))
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

    if (x_pos >= x(three_button) && x_pos <= (x(three_button) + width(three_button)))
    {
        if (y_pos >= y(three_button) && y_pos <= (y(three_button) + height(three_button)))
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

    if (x_pos >= x(nine_button) && x_pos <= (x(nine_button) + width(nine_button)))
    {
        if (y_pos >= y(nine_button) && y_pos <= (y(nine_button) + height(nine_button)))
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
        size = value(three_button);
    }

    /**
     * @brief check du bouton de taille 9
     * 
     */
    if (check_into_nine_button(x_pos, y_pos))
    {
        size = value(nine_button);
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
    three_button = createButton();
    nine_button = createButton();
    play_button = createButton();

    int widthBlock = WIDTH;
    int heightBlock = HEIGHT;

    /**
     * Initialisation du bouton "3"
    */
    setValue(three_button, 3);
    setHeight(three_button, (heightBlock / 4));
    setWidth(three_button, (widthBlock/4));
    setImage(three_button, MLV_load_image("img/three.png"));
    setX(three_button, (widthBlock / 8));
    setY(three_button, (heightBlock / 2));
    setEnable(three_button, 1);

    MLV_resize_image_with_proportions(three_button->image, width(three_button), height(three_button));

    /**
     * Initialisation du bouton "9"
    */
    setValue(nine_button, 9);
    setHeight(nine_button, (heightBlock / 4));
    setWidth(nine_button, (widthBlock / 4));
    setImage(nine_button, MLV_load_image("img/nine.png"));
    setX(nine_button, ((widthBlock / 2) + (widthBlock / 8)));
    setY(nine_button, (heightBlock / 2));
    setEnable(nine_button, 1);

    MLV_resize_image_with_proportions(nine_button->image, nine_button->width, nine_button->height);

    /**
     * Initialisation du bouton "Play"
    */
    int width_box = 0;
    int height_box = 0;
    int xPlayButton = (x(three_button)+width(three_button));
    int yPlayButton = heightBlock - (heightBlock / 4);
    setMessage(play_button, "JOUER");
    MLV_get_size_of_adapted_text_box(play_button->message,0,&width_box, &height_box);
    setValue(play_button, 1);
    setHeight(play_button, height_box);
    setWidth(play_button, width_box);
    setX(play_button, xPlayButton);
    setY(play_button, yPlayButton);
    setEnable(play_button, 0);
    

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
                close_window();
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
    close_window();
}
