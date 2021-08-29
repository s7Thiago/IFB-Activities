#include "fila_lista.h"
#include <limits.h>

// Função construtora para o tipo Pessoa
void *construtor_int(void *data)
{
	void *ptr = mallocx(sizeof(int));
	memcpy(ptr, data, sizeof(int));
	return ptr;
}

// Função de destrutor para o tipo Pessoa
void destructor_int(void *data)
{
	free(data);
}

// Imprime de maneira didática os elementos de uma fila
void showqueue(queue_t *queue)
{
	queue_iterator_t it;

	printf("[ ");
	for (it = queue->front; it != NULL; it = it->next)
	{
		// printf("%d, ", *(int *)it->data);
		printf("{ %d } -> ", *(int *)it->data);
	}
	printf("{ NULL } ]");
}

// ! Concatena duas filas na primeira, deixando a segunda vazia
void concat(queue_t *q, queue_t *q2)
{
	queue_t *tmp;

	// Inicializando a fila
	queue_initialize(&tmp, construtor_int, destructor_int);

	// * Esvaziando a primeira fila a medida que preenche a temporaria
	while (!queue_empty(q))
	{
		int elemento = *(int *)queue_front(q);
		queue_push(tmp, queue_front(q));

		queue_pop(q);
	}

	// * Esvaziando a segunda fila a medida que preenche a temporaria
	while (!queue_empty(q2))
	{
		int elemento = *(int *)queue_front(q2);
		queue_push(tmp, queue_front(q2));

		queue_pop(q2);
	}

	// Preenchendo novamente a primeira fila  com os elementos da fila temporária
	while (!queue_empty(tmp))
	{
		queue_push(q, queue_front(tmp));
		queue_pop(tmp);
	}

	// Removendo a fila temporária da memória
	queue_delete(&tmp);
}

// Aplicação principal
int main(void)
{
	queue_t *q;
	queue_t *q2;

	// Inicializando a fila
	queue_initialize(&q, construtor_int, destructor_int);
	queue_initialize(&q2, construtor_int, destructor_int);

	// populando a primeira fila
	for (int i = -2; i <= 2; i++)
	{
		queue_push(q, &i);
	}

	// populando a segunda fila
	for (int i = 4; i <= 7; i++)
	{
		queue_push(q2, &i);
	}

	// Imprimindo as filas
	printf("Fila 1:  ");
	showqueue(q);

	printf("\nFila 2:  ");
	showqueue(q2);

	printf("\n\nConcatenando...\n");
	concat(q, q2);

	printf("RESULTADO\n\nFila 1: ");
	showqueue(q);

	printf("\nFila 2:  ");
	showqueue(q2);

	queue_delete(&q);

	return 0;
}
