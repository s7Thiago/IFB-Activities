#ifndef CRUD_H
#define CRUD_H

#define MAIN_MENU_CHARACTERS_LIMIT 50
#define MAIN_MENU_OPTIONS_LIMIT 6

// Exibe o menu principal
void showMainMenu(char menu[][MAIN_MENU_CHARACTERS_LIMIT]);

//
void newProduct();


//Consulta Produto pelo codigo
void queryProduct();

#endif
