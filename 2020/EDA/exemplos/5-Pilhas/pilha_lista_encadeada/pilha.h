#ifndef PILHA_H
#define PILHA_H

#include "lista_encadeada.h"

typedef void *(*stack_node_constructor_fn)(void *); // Função que constrói um tipo
typedef void (*stack_node_destructor_fn)(void *);   // Função que destrói um tipo

// Define uma pilha (a definição é igual a de uma lista)
typedef struct stack_node_t
{
    void *data;
    struct stack_node_t *next;
} stack_node_t;

// Pilha propriamente dita
typedef struct stack_t
{
    stack_node_t *top;
    stack_node_constructor_fn constructor;
    stack_node_destructor_fn destructor;
    size_t size;
} stack_t;

// Iterador para uma pilha
typedef stack_node_t *stack_iterator_t;

// Inicializa uma pilha
void stack_initialize(stack_t **s, stack_node_constructor_fn constructor, stack_node_destructor_fn destructor);

// Retorna o tamanho de uma pilha
size_t stack_size(stack_t *s);

// Verifica se uma pilha está vazia
size_t stack_empty(stack_t *s);

// Empilha os dados *data na pilha
void stack_push(stack_t *s, void *data);

// Retorna o elemento que está no topo da pilha
void *stack_top(stack_t *s);

// Remove um elemento da pilha (desempilha)
void stack_pop(stack_t *s);

// Limpa a memória removendo a pilha da mesma
void stack_delete(stack_t **s);

#endif