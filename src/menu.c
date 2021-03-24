#include "../includes/window.h"
#include "../includes/menu.h"

#define WIDTH           500
#define HEIGHT          500

Size_Button *three_button;
Size_Button *nine_button;

void free_button(Size_Button *button){
    MLV_free_image(button->image);
    free(button);
}

/**
 * @brief Initialise les boutons de réglage de la taille
 * 
 */
void init_size_buttons(){
    three_button = (Size_Button *) malloc(sizeof(Size_Button));
    nine_button = (Size_Button *) malloc(sizeof(Size_Button));

    int width = MLV_get_window_width();
    int height = MLV_get_window_height();

    three_button->value = 3;
    three_button->height = height / 4;
    three_button->width = width / 4;
    three_button->image = MLV_load_image("img/three.png");
    three_button->x_pos = width / 8;
    three_button->y_pos = height / 2;

    MLV_resize_image_with_proportions(three_button->image, three_button->width, three_button->height);

    nine_button->value = 9;
    nine_button->height = height / 4;
    nine_button->width = width / 4;
    nine_button->image = MLV_load_image("img/nine.png");
    nine_button->x_pos = (width / 2) + (width / 8);
    nine_button->y_pos = height / 2;

    MLV_resize_image_with_proportions(nine_button->image, nine_button->width, nine_button->height);
}

/**
 * @brief Affiche le menu
 * 
 */
void menu_window(){
    
    create_window("Menu Blocus", WIDTH, HEIGHT);
    init_size_buttons();
    printf("x pos nine : %d\n", nine_button->x_pos);
    draw_size_buttons(three_button, nine_button);
    MLV_Event event = MLV_NONE;
    MLV_Mouse_button mouse_button;
    int x_pixel;
    int y_pixel;
    do{
        event = MLV_wait_event(
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            &x_pixel,
            &y_pixel,
            &mouse_button,
            NULL
        );
        /* fonctionne */
        if(event == MLV_MOUSE_BUTTON){
            if(x_pixel >= three_button->x_pos && x_pixel <= (three_button->x_pos + three_button->width)){
                printf("%d\n", three_button->value);
            }
        }
    }while(!is_pressed_escape());
    free_button(three_button);
    free_button(nine_button);
    close_window();
}

void display_username( int width, int height, char* texte1, char* texte2 ){

        MLV_clear_window( MLV_COLOR_ROYAL_BLUE );
        MLV_draw_adapted_text_box(
                10, 10,
                "BLOCUS",
                9,
                MLV_COLOR_ROYAL_BLUE, MLV_COLOR_WHITE, MLV_COLOR_ROYAL_BLUE,
                MLV_TEXT_CENTER
        );
        MLV_draw_text(
                10, 150,
                texte1,
                MLV_COLOR_WHITE
        );

        MLV_draw_text(
                220, 150,
                texte2,
                MLV_COLOR_WHITE
        );

        MLV_draw_all_input_boxes();
        MLV_actualise_window();
}


void menu_window(){
        create_window("Menu Blocus", 500, 500);
        int width = 640, height = 460;
        char* texte, *texte1, *texte2;
        char* joueur1, *joueur2;
        MLV_Input_box *input_box, *input_box_1, *input_box_2;
        MLV_Event event;
        do{
                input_box_1 = MLV_create_input_box(
                        10, 100,
                        200, 30, 
                        MLV_COLOR_WHITE, MLV_COLOR_WHITE,
                        MLV_COLOR_ROYAL_BLUE, "jOUEUR 1 : "
                );
                texte1 = (char*) malloc( 1*sizeof(char) ); *texte1 = '\0';
                input_box_2 = MLV_create_input_box(
                        220, 100,
                        200, 30, 
                        MLV_COLOR_WHITE, MLV_COLOR_WHITE,
                        MLV_COLOR_ROYAL_BLUE, "JOUEUR 2 : "
                );
                texte2 = (char*) malloc( 1*sizeof(char) ); *texte2 = '\0';
                display_username( width, height, texte1, texte2 );
                do {
                        event = MLV_get_event( 
                                NULL, NULL, NULL,
                                &texte, &input_box,
                                NULL, NULL, NULL,
                                NULL
                        );
                        if( event == MLV_INPUT_BOX ){
                                if( input_box == input_box_1 ){
                                        free( texte1 );
                                        texte1 = texte;
                                        joueur1 = texte1;
                                        printf("%s\n", joueur1);
                                }
                                if( input_box == input_box_2 ){
                                        free( texte2 );
                                        texte2 = texte;
                                        joueur2 = texte2;
                                        printf("%s\n", joueur2);
                                }
                        }
                        display_username( width, height, texte1, texte2 );

                } while( strcmp( texte2, "quit" ) );
                free( texte1 );
                free( texte2 );
                MLV_free_input_box( input_box_1 );
                MLV_free_input_box( input_box_2 );

        }while(!is_pressed_escape());
        close_window();
}

