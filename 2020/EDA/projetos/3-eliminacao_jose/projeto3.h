#ifndef PROJETO_3_H
#define PROJETO_3_H

#include "lista_encadeada.h"
#include "lista_duplamente_encadeada.h"

// Struct pessoa que será o objeto base para por na lista
typedef struct pessoa
{
    char nome[30];

} pessoa;

// Função construtora: indicamos para essa função como construir um objeto pessoa
void *constructor_pessoa(void *data);

// Função desstrutora: Define a forma correta de destruir uma pessoa na lista. Nesse caso, apenas desalocamos a memória ocupada
void destructor_pessoa(void *data);

// Imprime os dados em uma variável do tipo pessoa
void imprime_pessoa(pessoa *p);

// Imprime uma lista do tipo pessoa
void print_list_pessoa(list_t *l);

// Recebe a entrada de dados para uma pessoa
void le_pessoa(pessoa *p);

//
void eliminar(list_t *lista, size_t nPessoas, size_t indiceEscolhido);

#endif