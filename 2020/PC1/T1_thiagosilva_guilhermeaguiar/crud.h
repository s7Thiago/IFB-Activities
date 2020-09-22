#ifndef CRUD_H
#define CRUD_H

#define MAIN_MENU_CHARACTERS_LIMIT 50

// Exibe o menu principal
void showMenu(char menu[][MAIN_MENU_CHARACTERS_LIMIT], int size);

// Contém o fluxo de adicionar um novo produto na lista
void newProduct();

// Atualiza o produto de código passado por parâmetro se existir
void updateProduct();

//Vender Produto
void sellProduct();

//Consulta Produto pelo código
void queryProduct();

//Função Consulta todos os produtos
void consultAllProducts();

// Funções para debug
void allProducts();

void mockProducts();

#endif
