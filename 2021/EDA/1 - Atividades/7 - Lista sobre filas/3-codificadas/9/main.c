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
void excludenegatives(queue_t *q)
{
}

// Aplicação principal
int main(void)
{
	queue_t *q;

	// Inicializando as filas
	queue_initialize(&q, construtor_int, destructor_int);

	// populando as filas
	for (int i = 1; i <= 5; i++)
	{
		queue_push(q, &i);
	}

	// Imprimindo as filas
	printf("fila: ");
	showqueue(q);

	queue_delete(&q);

	return 0;
}
