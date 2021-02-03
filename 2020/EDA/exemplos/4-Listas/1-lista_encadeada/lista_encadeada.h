#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "alloc.h"

// definições de lista
typedef void *(*list_node_constructor_fn)(void *);
typedef void (*list_node_destructor_fn)(void *);

/**
 * @brief list_node_t Definição de nó de lista ligada
 * O nó de lista ligada contém um ponteiro para um dado genérico (data)
 * e um ponteiro para o próximo nó da lista
**/
typedef struct list_node_t
{
    void *data;               // Ponteiro para um dado genérico de qualquer tipo
    struct list_node_t *next; // Ponteiro para o próximo elemento
} list_node_t;

/**
 * @brief list_t Definição do tipo lista. Contém ponteiros para a cabeça
 * e cauda da lista, as funções construtoras e destrutoras dos elementos
 * das listas e o tamanho da lista.
 * **/

typedef struct list_t
{
    list_node_t *head;                    // Cabeça da lista
    list_node_t *tail;                    // Cauda da lista
    list_node_constructor_fn constructor; // Função para construir o objeto
    list_node_destructor_fn destructor;   // Função para destruir o objeto
    size_t size;                          // tamanho da lista
} list_t;

/**
 * @brief list_iterator_t Tipo para iterar na lista ligada.
 * O list_iterator_t é apenas um apelido para o list_node_t*. Ele é utilizado
 * no código quando o propósito é andar na lista. Deixa o código mais claro,
 * pois quando declarado indica explicitamente a intenção da variável
 * **/
typedef list_node_t *list_iterator_t;

// Retorna o tamanho da lista
size_t list_size(list_t *l);

// Retorna verdadeiro se a lista estiver vazia, ou falso, caso contrário
size_t list_empty(list_t *l);

// Cria o nó de uma lista
static list_node_t *list_new_node(void *data, list_node_constructor_fn constructor);

// Destrói o nó de uma lista
static void list_delete_node(list_node_t *n, list_node_destructor_fn destructor);

// Insere um elemento na cabeca da lista
void list_prepend(list_t *l, void *data);

// Insere um elemento na cauda da lista
void list_append(list_t *l, void *data);

// Insere um dado elemento numa dada posição da lista
void list_insert(list_t *l, void *data, size_t i);

// Remove um elemento da na cabeça da lista
void list_remove_head(list_t *l);

// Remove um elemento da na cauda da lista
void list_remove_tail(list_t *l);

// Remove um elemento na posição i da lista
void list_remove(list_t *l, size_t i);

// Acessa a cabeça da lista
void *list_access_head(list_t *l);

// Acessa a cauda da lista
void *list_access_tail(list_t *l);

// acessa o i-ésimo elemento da lista
void *list_access(list_t *l, size_t i);

// Realiza a limpeza da lista
void list_delete(list_t **l);

#endif