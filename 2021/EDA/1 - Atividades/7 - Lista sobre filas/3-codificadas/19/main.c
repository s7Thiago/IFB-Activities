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

int countPairs(queue_t *q)
{

	// Verificando e contabilizando os valores positivos na fila
	queue_iterator_t it;
	int pairs = 0;

	for (it = q->front; it != NULL; it = it->next)
	{
		int element = *(int *)it->data;

		if (element % 2 == 0)
		{
			pairs++;
		}
	}

	return pairs;
}

// Aplicação principal
int main(void)
{
	queue_t *q;

	// Inicializando a fila
	queue_initialize(&q, construtor_int, destructor_int);

	// populando a fila
	for (int i = 1; i <= 10; i++)
	{
		queue_push(q, &i);
	}

	// Imprimindo as filas
	printf("Input:  ");
	showqueue(q);

	printf("\n\nPairs: %d\n\n", countPairs(q));

	queue_delete(&q);

	return 0;
}
