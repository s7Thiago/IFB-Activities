#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "xmlParser.h"

// insere o conteúdo do arquivo `root` na variável string `target`
void getContent(FILE* root, char* target);

// Limpa uma string inserindo null (\0) em todas as posições
void cleanString(char* target);

// Limpa uma matriz de strings inserindo null (\0) em todas as posições
void cleanStringMatrix(char matrix[][600], int lines);

#endif
