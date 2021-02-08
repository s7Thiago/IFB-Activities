#ifndef LISTA_DUP_ENCADEADA
#define LISTA_DUP_ENCADEADA

#include "alloc.h"

// Ponteiro para função que recebe um dado e retorna esse dado construído
typedef void *(*dlist_node_constructor_fn)(void *);

// Ponteiro para função que recebe um dado e destrói o mesmo sem retornar nada
typedef void (*dlist_node_destructor_fn)(void *);

/**A nossa dlista encadeada consiste de vários nós,
que possuem o tipo linked_dlist_node_t **/
typedef struct dlist_node_t
{
    void *data;                /*Ponteiro para um dado genérico de qualquer tipo*/
    struct dlist_node_t *next; /*ponteiro para o próximo elemento*/
    struct dlist_node_t *prev; /*Ponteiro para o elemento anterior*/

} dlist_node_t;

// Definição da lista duplamente encadeada (Acontece da mesma forma que a lista encadeada comum)
typedef struct dlist_t
{
    dlist_node_t *head;                    /*Cabe¸ca da dlista*/
    dlist_node_t *tail;                    /*Cauda da dlista*/
    dlist_node_constructor_fn constructor; /*Fun¸c~ao para construir o objeto*/
    dlist_node_destructor_fn destructor;   /*Fun¸c~ao para destruir o objeto*/
    size_t size;                           /*tamanho da dlista*/
} dlist_t;

// Define um apelido para um ponteiro de nó de lista duplamente encadeada
typedef dlist_node_t *dlist_iterator_t;

// Inicializa a lista duplamente encadeada e seus membros
void dlist_initialize(dlist_t **l, dlist_node_constructor_fn constructor, dlist_node_destructor_fn destructor);

// Retorna o tamanho da lista
size_t dlist_size(dlist_t *l);

// Retorna verdadeiro se a dlista está vazia, e falso caso contrário
size_t dlist_empty(dlist_t *l);

// Cria um novo nó (Temos uma mudança: aqui definimos também o ponteiro para o elemento anterior como NULL)
static dlist_node_t *dlist_new_node(void *data, dlist_node_constructor_fn constructor);

// Função para deletar um nó (Não muda nada em relação a função da lista encadeada comum)
static void dlist_delete_node(dlist_node_t *node, dlist_node_destructor_fn destructor);

// Insere um elemento na cabeça da dlista
void dlist_prepend(dlist_t *l, void *data);

// Insere um elemento na cauda da dlista
void dlist_append(dlist_t *l, void *data);

// Insere um elemento numa posição dada da lista
void dlist_insert(dlist_t *l, void *data, size_t i);

// Remove um elemento na cabeça da lista
void dlist_remove_head(dlist_t *l);

// Remove um elemento na cauda da lista
void dlist_remove_tail(dlist_t *l);

// Remove o elemento da posição i da dlista
void dlist_remove(dlist_t *l, size_t i);

// Acessa um elemento que está na cabeça da lista
void *dlist_access_head(dlist_t *l);

// Acessa um elemento que está na cauda da lista
void *dlist_access_tail(dlist_t *l);

// Acessando um elemento de uma dada posição i da lista
void *dlist_access(dlist_t *l, size_t i);

// Deleta a lista por inteiro e libera espaço em memória
void dlist_delete(dlist_t **l);

#endif