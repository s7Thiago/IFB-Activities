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

void transfer(stack_t *s, stack_t *s2)
{
	stack_t *tmp;
	stack_iterator_t it;

	stack_initialize(&tmp, constructor_int, destructor_int);

	// Copia os elementos de s para uma pilha temporária
	// com a intenção de passar para s2 depois na ordem original de s
	for (it = s->top; it != NULL; it = it->next)
	{
		stack_push(tmp, it->data);
	}

	// Passando os elementos da pilha temporária para s2
	// para que eles estejam na mesma ordem da pilha s
	for (it = tmp->top; it != NULL; it = it->next)
	{
		stack_push(s2, it->data);
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

	printf("Pilha s: ");
	showstack(s);

	transfer(s, s2);

	// Transferindo elementos da pilha s para a pilha s2
	printf("\nPilha s2: ");
	showstack(s2);

	stack_delete(&s);
	stack_delete(&s2);

	return 0;
}