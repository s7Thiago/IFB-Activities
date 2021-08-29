#ifndef FILA_LISTA_H
#define FILA_LISTA_H

#include "alloc.h"

// Definição de construtor e destrutor de fila
typedef void *(*queue_node_constructor_fn)(void *);
typedef void (*queue_node_destructor_fn)(void *);

/**
 * @brief list_node_t Definição de nó de fila
 * O nó de fila contém um ponteiro para um dado genérico (data)
 * e um ponteiro para o próximo nó da fila
**/
typedef struct queue_node_t
{
	void *data;
	struct queue_node_t *next;
} queue_node_t;

/**
 * @brief stack_t Definição do tipo fila. Contém ponteiros para o topo
 * da fila, as funções construtoras e destrutoras dos elementos e o
 * tamanho da fila.
 * **/
typedef struct queue_t
{
	queue_node_t *front;
	queue_node_t *back;
	queue_node_constructor_fn constructor;
	queue_node_destructor_fn destructor;
	size_t size;
} queue_t;

/**
 * @brief stack_iterator_t Tipo para iterar na fila.
 * O stack_iterator_t é apenas um apelido para o stack_node_t*. Ele é utilizado
 * no código quando o propósito é andar na fila. Deixa o código mais claro,
 * pois quando declarado indica explicitamente a intenção da variável
 * **/
typedef queue_node_t *queue_iterator_t;

// Inicializa uma fila juntamente com os seus membros básicos
void queue_initialize(queue_t **q, queue_node_constructor_fn constructor, queue_node_destructor_fn destructor);

// * Funções auxiliares para filas

//Retorna o tamanho da fila
size_t queue_size(queue_t *q);

// retorna 1 se a fila estiver vazia ou 0, caso contrário
size_t queue_empty(queue_t *q);

// Enfileirando
void queue_push(queue_t *q, void *data);

// Obtém o elemento no topo da fila
void *queue_front(queue_t *q);

// Responsável pelo processo de desemfileirar a fila
void queue_pop(queue_t *q);

// Responsável pela limpeza da fila
void queue_delete(queue_t **q);

#endif
