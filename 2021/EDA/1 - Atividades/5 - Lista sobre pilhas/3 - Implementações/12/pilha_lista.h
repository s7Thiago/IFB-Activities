#ifndef PILHA_LISTA_H
#define PILHA_LISTA_H

#include "alloc.h"

// Definićão de construtor e destrutor de pilha
typedef void* (*stack_node_constructor_fn) (void*);
typedef void (*stack_node_destructor_fn) (void*);

/**
 * @brief list_node_t Definição de nó de pilha
 * O nó de pilha contém um ponteiro para um dado genérico (data)
 * e um ponteiro para o próximo nó da pilha
**/
typedef struct stack_node_t {
	void* data;
	struct stack_node_t* next;
} stack_node_t;

/**
 * @brief stack_t Definição do tipo pilha. Contém ponteiros para o topo
 * da pilha, as funções construtoras e destrutoras dos elementos e o
 * tamanho da pilha.
 * **/
typedef struct stack_t {
	stack_node_t* top;
	stack_node_constructor_fn constructor;
	stack_node_destructor_fn destructor;
	size_t size;
} stack_t;

/**
 * @brief stack_iterator_t Tipo para iterar na pilha.
 * O stack_iterator_t é apenas um apelido para o stack_node_t*. Ele é utilizado
 * no código quando o propósito é andar na pilha. Deixa o código mais claro,
 * pois quando declarado indica explicitamente a intenção da variável
 * **/
typedef stack_node_t *stack_iterator_t;


// Inicializa uma pilha jutnamente com os seus membros básicos
void stack_initialize(stack_t** s, stack_node_constructor_fn constructor, stack_node_destructor_fn destructor);

// Funcoes auxiliares para pilhas

//Retorna o tamanho da pilha
size_t stack_size(stack_t* s);	

// retorna 1 se a pilha estiver vazia ou 0, caso contrário
size_t stack_empty(stack_t* s);

// Empilhando
void stack_push(stack_t* s, void* data);

// Obtém o elemento no topo da pilha
void* stack_top(stack_t* s);

// Responsável pelo processo de desempilhar a pilha
void stack_pop(stack_t* s);

// Responsável pela limpeza da pilha
void stack_delete(stack_t** s);


#endif












































