#include "fila_lista.h"

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

void reverso(queue_t *q)
{
	queue_t *aux;

	// Inicializando a fila
	queue_initialize(&aux, construtor_int, destructor_int);

	// Copiando os elementos da fila alvo para uma nova fila na ordem reversa
	while (!queue_empty(q))
	{
		// Pegando a referência para cada elemento da fila
		int elemento = *(int *)queue_front(q);

		// Adicionando o elemento na fila auxiliar
		queue_push(aux, &elemento);
		printf("%d - ", elemento);
		queue_pop(q);
	}

	// Colocando de volta os elementos da fila auxiliar na fila alvo
	while (!queue_empty(aux))
	{
		// Pegando a referência para cada elemento da fila
		int elemento = *(int *)queue_front(aux);

		// Adicionando o elemento de volta na fila original
		queue_push(q, &elemento);
		queue_pop(aux);
	}

	printf("\n");

	// removendo a fila auxiliar da memória
	queue_delete(&aux);
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

	reverso(q);

	printf("Saída: ");
	showqueue(q);
	printf("\n");

	queue_delete(&q);

	return 0;
}
