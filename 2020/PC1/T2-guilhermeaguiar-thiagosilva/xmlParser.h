#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <stdio.h>
#include <string.h>
#include "fileOperations.h"

// ########### Novas
// transfere os dados do XML para uma variável
void populateData();

// Busca recorrências de uma tag nomeada como `tagName` dentro da string 
// `searchPlace` e armazena o conteúdo de cada recorrência em `contentsPlace`
void getTag(char* searchPlace, char* tagName, char contentsPlace[][5000]);



#endif
