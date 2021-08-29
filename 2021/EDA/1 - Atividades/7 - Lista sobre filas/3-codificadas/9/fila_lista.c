#include "fila_lista.h"

// Inicializa uma fila juntamente com os seus membros
void queue_initialize(queue_t **q, queue_node_constructor_fn constructor, queue_node_destructor_fn destructor)
{

	(*q) = mallocx(sizeof(queue_t));
	(*q)->front = NULL;
	(*q)->back = NULL;
	(*q)->size = 0;
	(*q)->constructor = constructor;
	(*q)->destructor = destructor;
}

//  Retorna a quantidade de elementos na fila
size_t queue_size(queue_t *q)
{
	return (q->size);
}

// Verifica se a fila está vazia
size_t queue_empty(queue_t *q)
{
	return (queue_size(q) == 0 ? 1 : 0);
}

//Implementa a lógica de enfileirarlar um elemento na fila
void queue_push(queue_t *q, void *data)
{
	//  constrói o dado (new_node) que aponta para NULL
	queue_node_t *new_node = mallocx(sizeof(queue_node_t));
	new_node->data = q->constructor(data);
	new_node->next = NULL;

	if (queue_size(q) == 0)
	{
		q->front = new_node;
	}
	else
	{
		q->back->next = new_node;
	}

	q->back = new_node;
	q->size++;
}

// Obtém o elemento que estiver a frente da fila
void *queue_front(queue_t *q)
{
	assert(!queue_empty(q));
	return (q->front->data);
}

// Responsável pelo processo de desemfileirar uma fila passada no parâmetro
void queue_pop(queue_t *q)
{
	assert(!queue_empty(q));

	queue_iterator_t it = q->front;

	if (queue_size(q) == 1)
	{
		q->front = NULL;
		q->back = NULL;
	}
	else
	{
		q->front = q->front->next;
	}

	q->destructor(it->data);
	free(it);
	q->size--;
}

// Responsável por limpar a fila da memória
// repetindo a operação de desemfileirar até
// que a fila esteja vazia
void queue_delete(queue_t **q)
{
	while (!queue_empty(*q))
	{
		queue_pop(*q);
	}

	free(*q);
	(*q) = NULL;
}
