#ifndef CRUD_H
#define CRUD_H

#define MAIN_MENU_CHARACTERS_LIMIT 50
#define MAIN_MENU_OPTIONS_LIMIT 6

// Exibe o menu principal
void showMenu(char menu[][MAIN_MENU_CHARACTERS_LIMIT]);

// Contém o fluxo de adicionar um novo produto na lista
void newProduct();

// Atualiza o produto de código passado por parâmetro se existir
void updateProduct();

#endif
