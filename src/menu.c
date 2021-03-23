#include "../includes/window.h"
#include "../includes/menu.h"

#define WIDTH           500
#define HEIGHT          500

Grid_Menu *grid_menu;
Size_Button *three_button;
Size_Button *nine_button;

void create_grid_menu(){
    int i, j;
    grid_menu = (Grid_Menu *)malloc(sizeof(Grid_Menu));
    grid_menu->x_size = 2;
    grid_menu->y_size = 2;
    grid_menu->cells = (Cell_Menu *)malloc(grid_menu->x_size*sizeof(Cell_Menu *));
    for(i = 0; i < grid_menu->x_size; i++){
        grid_menu->cells[i] = (Cell_Menu *) malloc(grid_menu->y_size*sizeof(Cell_Menu));
    }

    for(j = 0; j < grid_menu->y_size; j++){
        for(i = 0; i < grid_menu->x_size; i++){
            grid_menu->cells[i][j].x_pos = i;
            grid_menu->cells[i][j].y_pos = j;
        }
    }
}

void free_grid_menu(Grid_Menu *grid_menu){
    int i;
    for(i = 0; i < grid_menu->x_size; i++){
        free(grid_menu->cells[i]);
    }
    free(grid_menu->cells);
    free(grid_menu);
}

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
    create_grid_menu();
    init_size_buttons();
    draw_size_buttons(three_button, nine_button);
    do{
    
    }while(!is_pressed_escape());
    free_grid_menu(grid_menu);
    free_button(three_button);
    free_button(nine_button);
    close_window();
}