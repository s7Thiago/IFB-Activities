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
	queue_t *tmp;

	// Inicializando a fila
	queue_initialize(&tmp, construtor_int, destructor_int);

	// Esvaziando a fila original a medida que preenche a temporaria selecionando apenas os valores positivos
	while (!queue_empty(q))
	{
		int elemento = *(int *)queue_front(q);

		if (elemento >= 0)
			queue_push(tmp, queue_front(q));

		queue_pop(q);
	}

	// Preenchendo novament ea fila original com os elementos da fila temporária
	while (!queue_empty(tmp))
	{
		queue_push(q, queue_front(tmp));
		queue_pop(tmp);
	}

	queue_delete(&tmp);
}

// Aplicação principal
int main(void)
{
	queue_t *q;

	// Inicializando a fila
	queue_initialize(&q, construtor_int, destructor_int);

	// populando a fila
	for (int i = -3; i <= 5; i++)
	{
		queue_push(q, &i);
	}

	// Imprimindo as filas
	printf("antes:  ");
	showqueue(q);

	printf("\n");
	excludenegatives(q);

	printf("depois: ");
	showqueue(q);

	queue_delete(&q);

	return 0;
}
