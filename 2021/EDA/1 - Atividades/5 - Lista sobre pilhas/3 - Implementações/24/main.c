#include "pilha_lista.h"

// Construtor para um tipo char
void *constructor_int(void *data)
{
	void *ptr = mallocx(sizeof(int));
	memcpy(ptr, data, sizeof(char));
	return ptr;
}

// Funcao destrutora para um tipo char
void destructor_int(void *data)
{
	free(data);
}

// Imprime de maneira didática os elementos de uma pilha
void showstack(stack_t *stack)
{
	stack_iterator_t it;

	printf("[ ");
	for (it = stack->top; it != NULL; it = it->next)
	{
		printf("%d, ", *(int *)it->data);
	}
	printf("{ NULL } ]");
}

int contPairs(stack_t *s)
{
	stack_iterator_t it;
	int pairs = 0;

	// Contando os elementos pares
	for (it = s->top; it != NULL; it = it->next)
	{
		if (*(int *)(it->data) % 2 == 0)
		{
			pairs++;
		}
	}

	return pairs;
}

int main(void)
{

	stack_t *s;

	// Inicializando a pilha
	stack_initialize(&s, constructor_int, destructor_int);

	int a = 34;
	int b = 23;
	int c = 13;
	int d = 7;
	int e = 15;
	int f = 10;

	// Inserindo elementos na pilha s
	stack_push(s, &a);
	stack_push(s, &b);
	stack_push(s, &c);
	stack_push(s, &d);
	stack_push(s, &e);
	stack_push(s, &f);

	printf("\nPilha: ");
	showstack(s);

	printf("\nquantidade de pares: %d\n", contPairs(s));

	stack_delete(&s);

	return 0;
}