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

void isBiggerThan(stack_t *s, stack_t *s2)
{
	if (stack_size(s) > stack_size(s2))
	{
		printf("A primeira pilha tem mais elementos que a primeira.\n");
	}
	else
	{
		printf("A segunda pilha tem mais elementos que a primeira.\n");
	}
}

int main(void)
{

	stack_t *s;
	stack_t *s2;

	// Inicializando a pilha
	stack_initialize(&s, constructor_int, destructor_int);
	stack_initialize(&s2, constructor_int, destructor_int);

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

	// Inserindo elementos na pilha s2
	stack_push(s2, &a);
	stack_push(s2, &b);
	stack_push(s2, &c);
	stack_push(s2, &d);
	stack_push(s2, &e);
	stack_push(s2, &c);
	stack_push(s2, &f);

	isBiggerThan(s, s2);

	stack_delete(&s);
	stack_delete(&s2);

	return 0;
}