#include "../includes/window.h"
#include "../includes/menu.h"

void display_username( int width, int height, char* texte1, char* texte2 ){
    /*MLV_get_size_of_text( "BLOCUS", 250, 100);
    int positionX = (width-250)/2, positionY = 10;
    MLV_draw_text( positionX, positionY, "BLOCUS", MLV_COLOR_WHITE );*/

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
    char* texte, *texte1, *texte2;
    MLV_Input_box *input_box, *input_box_1, *input_box_2;
    MLV_Event event;

    do{

        input_box_1 = MLV_create_input_box(
                15, 100,
                220, 30, 
                MLV_COLOR_WHITE, MLV_COLOR_WHITE,
                MLV_COLOR_ROYAL_BLUE, "Joueur 1 : "
        );
        texte1 = (char*) malloc( 1*sizeof(char) ); *texte1 = '\0';

        input_box_2 = MLV_create_input_box(
                265, 100,
                220, 30, 
                MLV_COLOR_WHITE, MLV_COLOR_WHITE,
                MLV_COLOR_ROYAL_BLUE, "Joueur 2 : "
        );
        texte2 = (char*) malloc( 1*sizeof(char) ); *texte2 = '\0';

        display_username( 500, 500, texte1, texte2 );

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
                    }
                    if( input_box == input_box_2 ){
                            free( texte2 );
                            texte2 = texte;
                    }
            }
            display_username( 500, 500, texte1, texte2 );
        } while( strcmp( texte2, "quit" ) );

    }while(!is_pressed_escape());

    free( texte1 );
    free( texte2 );
    MLV_free_input_box( input_box_1 );
    MLV_free_input_box( input_box_2 );
    close_window();
}