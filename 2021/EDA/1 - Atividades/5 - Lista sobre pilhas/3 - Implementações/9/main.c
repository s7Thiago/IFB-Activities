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

int main(void)
{

	stack_t *s;
	stack_t *tmp;

	// Inicializando a pilha
	stack_initialize(&s, constructor_int, destructor_int);
	stack_initialize(&tmp, constructor_int, destructor_int);

	int numbers[6] = {34, 3, 31, 98, 92, 23};

	// Inserting the numbers in the stack
	for (int i = 0; i < 6; i++)
	{
		stack_push(s, &numbers[i]);
	}

	// Sorting the stack
	while (!stack_empty(s))
	{
		// removing the first element from input
		int tempint = *(int *)stack_top(s);
		stack_pop(s);

		// While the temporary stack is not empty and the top
		// of the stack is greater than the top of the temporary stack
		while (!stack_empty(tmp) && (*(int *)stack_top(tmp)) < tempint)
		{
			// pop from temporary stack and push it to the input stack
			stack_push(s, stack_top(tmp));
			stack_pop(tmp);
		}

		stack_push(tmp, &tempint);
	}

	// Printing the sorted stack
	showstack(tmp);

	stack_delete(&s);
	stack_delete(&tmp);
	return 0;
}