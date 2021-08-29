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

void analise(queue_t *q)
{
	// * Encontrando o menor elemento da file
	int menor = *(int *)queue_front(q);
	int maior = *(int *)queue_front(q);
	int elemento = 0;
	double media = 0;
	double qtde = 0;
	// int auxMaior = 0;

	// * Encontrando o menor e o maior elemento da file
	while (!queue_empty(q))
	{
		qtde++;
		elemento = *(int *)queue_front(q);
		printf("m[%d]\n", elemento);

		if (elemento < menor)
		{
			menor = elemento;
			media += (elemento);
		}
		else if (elemento > maior)
		{
			maior = elemento;
			media += (elemento);
		}

		// Somando os elementos para calcular a média aritmética
		media += elemento;
		media /= qtde;

		queue_pop(q);
	}

	printf("\n\nmenor: %d\n", menor);
	printf("maior: %d\n", maior);
	printf("média: %d\n", media);
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

	analise(q);

	printf("Saída: ");
	showqueue(q);
	printf("\n");

	queue_delete(&q);

	return 0;
}
