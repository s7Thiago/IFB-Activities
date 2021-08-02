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

void inverter(stack_t *s)
{
	stack_t *tmp;

	// Inicializando a pilha
	stack_initialize(&tmp, constructor_int, destructor_int);

	// Invertendo a pilha e colocando na pilha temporária
	while (!stack_empty(s))
	{
		// int elemento = *(int *)stack_top(s);

		stack_push(tmp, (int *)stack_top(s));
		stack_pop(s);
	}

	printf("\nTemporária: ");
	showstack(tmp);

	stack_delete(&tmp);
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
	int e = 93;
	int f = 10;

	// Inserindo elementos na pilha
	stack_push(s, &a);
	stack_push(s, &b);
	stack_push(s, &c);
	stack_push(s, &d);
	stack_push(s, &e);
	stack_push(s, &f);

	printf("Pilha original: ");
	showstack(s);

	inverter(s);

	// printf("\nPilha invertida: ");

	// Imprime a pilha invertida e esvazia
	// showstack(s);

	stack_delete(&s);

	return 0;
}