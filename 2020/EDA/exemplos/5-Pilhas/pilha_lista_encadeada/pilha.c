#include "pilha.h"

// Inicializando uma pilha
void stack_initialize(stack_t **s, stack_node_constructor_fn constructor, stack_node_destructor_fn destructor)
{
    (*s) = mallocx(sizeof(stack_t));
    (*s)->size = 0;
    (*s)->top = NULL;
    (*s)->constructor = constructor;
    (*s)->destructor = destructor;
}

// Retorando o tamanho de uma pilha
size_t stack_size(stack_t *s)
{
    return (s->size);
}

// Verificando se a pilha está vazia
size_t stack_empty(stack_t *s)
{
    return (s->size == 0 ? 1 : 0);
}

// Empilhando dados na pilha
void stack_push(stack_t *s, void *data)
{
    stack_node_t *new_node = mallocx(sizeof(stack_node_t));
    new_node->data = s->constructor(data);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

// Obtendo um elemento do topo da pilha
void *stack_top(stack_t *s)
{
    assert(!stack_empty(s));
    return (s->top->data);
}

// Desempilhando a pilha
void stack_pop(stack_t *s)
{
    assert(!stack_empty(s));
    stack_iterator_t it = s->top;
    s->top = s->top->next;
    s->destructor(it->data);
    free(it);
    s->size--;
}

// Removendo a pilha completamente da memória
void stack_delete(stack_t **s)
{
    while (!stack_empty(s))
    {
        stack_pop(*s);
    }

    free(*s);
    (*s) = NULL;
}