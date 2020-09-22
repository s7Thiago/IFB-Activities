// TABELA ASCII: https://bit.ly/3cbCwCT

#ifndef PRODUTO_H
#define PRODUTO_H

#define PRODUCT_CODE_SIZE 8
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_LIST_SIZE 999

#include <stdio.h>
#include <string.h>

// struct produto
typedef struct produto
{
	int qtde;
	char name[PRODUCT_NAME_SIZE];
	char country[PRODUCT_NAME_SIZE];
	char code[PRODUCT_CODE_SIZE];
	char end;
} produto;

// Products list
produto produtos[PRODUCT_LIST_SIZE];

// Gera um código de produto com base nos parâmetros
void generateProductCode(char target[], char *country, int productIndex);

// Converte letra maiúscula em minúscula
char lowerToUpperChar(char target);

//Converte o inteiro num para String e armazena em str
void toString(char str[], int num);

// Configura a inicialização do programa
void init();

#endif
