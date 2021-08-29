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
void isBiggerThan(queue_t *q, queue_t *q2)
{
	printf("q: %d\n", queue_size(q));
	printf("q2: %d\n", queue_size(q2));

	if (queue_size(q) == queue_size(q2))
	{
		printf("Ambas as filas tem a mesma quantidade de elementos\n");
		return;
	}

	if (queue_size(q) > queue_size(q2))
	{
		printf("A primeira fila tem mais elementos que a primeira.\n");
	}
	else
	{
		printf("A segunda fila tem mais elementos que a primeira.\n");
	}
}

// Aplicação principal
int main(void)
{
	queue_t *q;
	queue_t *q2;

	// Inicializando as filas
	queue_initialize(&q, construtor_int, destructor_int);
	queue_initialize(&q2, construtor_int, destructor_int);

	// populando as filas
	for (int i = 1; i <= 5; i++)
	{
		queue_push(q, &i);

		int elemento_fila2 = *(int *)queue_front(q) + i * i;
		queue_push(q2, &elemento_fila2);
	}

	// Imprimindo as filas
	printf("fila 1: ");
	showqueue(q);

	printf("\nfila 2: ");
	showqueue(q2);

	printf("\n");
	isBiggerThan(q, q2);
	printf("\n");

	queue_delete(&q);

	return 0;
}
