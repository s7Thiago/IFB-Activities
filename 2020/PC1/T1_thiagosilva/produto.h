// TABELA ASCII: https://bit.ly/3cbCwCT

#ifndef PRODUTO_H
#define PRODUTO_H

#define PRODUCT_CODE_SIZE 8
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_LIST_SIZE 999

#include <stdio.h>
#include <string.h>

char* generateProductCode(char* country, int productIndex);

#endif
