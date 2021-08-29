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
int getTop(queue_t *q)
{
	int topValue = *(int *)queue_front(q);

	queue_pop(q);

	return topValue;
}

// Aplicação principal
int main(void)
{
	queue_t *q;
	// Inicializando a fila
	queue_initialize(&q, construtor_int, destructor_int);

	// populando a fila
	for (int i = -2; i <= 2; i++)
	{
		queue_push(q, &i);
	}

	// Imprimindo as filas
	printf("Fila antes:  ");
	showqueue(q);

	printf("\n\nTOPO:%d\n", getTop(q));

	printf("\nFila depois:  ");
	showqueue(q);

	queue_delete(&q);

	return 0;
}
