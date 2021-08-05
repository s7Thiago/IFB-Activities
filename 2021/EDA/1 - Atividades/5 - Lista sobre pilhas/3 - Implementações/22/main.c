#include "pilha_lista.h"

// Construtor para um tipo char
void *constructor_int(void *data)
{
	void *ptr = mallocx(sizeof(int));
	memcpy(ptr, data, sizeof(int));
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

void showtop(stack_t *s)
{

	printf("\nElemento no topo: %d", *(int *)stack_top(s));
	stack_pop(s);
}

int main(void)
{

	stack_t *s;
	int a = 15;
	int b = 7;
	int c = 31;

	// Inicializando a pilha
	stack_initialize(&s, constructor_int, destructor_int);

	stack_push(s, &a);
	stack_push(s, &b);
	stack_push(s, &c);

	printf("\nPilha completa: ");
	showstack(s);
	showtop(s);

	printf("\nNova pilha: ");
	showstack(s);

	printf("\n");
	stack_delete(&s);
	return 0;
}