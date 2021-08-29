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

int minIndex(queue_t *q, int sortedIndex)
{
	int min_index = -1;
	int min_val = INT_MAX;
	int n = queue_size(q);

	for (int i = 0; i < n; i++)
	{
		int curr = *(int *)queue_front(q);
		queue_pop(q);

		if (curr <= min_val && i <= sortedIndex)
		{
			min_index = i;
			min_val = curr;
		}

		queue_push(q, &curr);
	}

	return min_index;
}

void insertMinToRear(queue_t *q, int min_index)
{
	int min_val;
	int n = *(int *)queue_size(q);

	for (int i = 0; i < n; i++)
	{
		int curr = *(int *)queue_front(q);
		queue_pop(q);
		if (i != min_index)
		{
			queue_push(q, &curr);
		}
		else
		{
			min_val = curr;
		}
	}
	queue_push(q, &min_val);
}

void sortQueue(queue_t *q)
{
	for (int i = 1; i <= queue_size(q); i++)
	{
		int min_index = minIndex(q, (queue_size(q)) - i);
		insertMinToRear(q, min_index);
	}
}

// Aplicação principal
int main(void)
{
	queue_t *q;

	// Inicializando a fila
	queue_initialize(&q, construtor_int, destructor_int);

	// populando a fila
	for (int i = 1; i <= 5; i++)
	{
		queue_push(q, &i);
	}

	// printf("\nEntrada: ");
	// showqueue(q);
	printf("\n");

	sortQueue(q);

	printf("Saída: ");
	showqueue(q);
	printf("\n");

	queue_delete(&q);

	return 0;
}
