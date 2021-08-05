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
void print_stack(stack_t *stack)
{
	printf("[ ");
	while (!stack_empty(stack))
	{
		char c = *(char *)stack_top(stack);
		printf("%d", c);
		if (stack_size(stack) > 1)
			printf(" - ");
		else
			printf(" ]");

		stack_pop(stack);
	}
}

void analise(stack_t *s)
{
	// * Encontrando o menor elemento da pilha
	int menor = *(int *)stack_top(s);
	int maior = *(int *)stack_top(s);
	int elemento = 0;
	double media = 0;
	double qtde = stack_size(s);
	// int auxMaior = 0;

	// * Encontrando o menor e o maior elemento da pilha
	while (!stack_empty(s))
	{
		elemento = *(int *)stack_top(s);
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

		stack_pop(s);
	}
	media /= qtde;

	printf("\n\nmenor: %d\n", menor);
	printf("maior: %d\n", maior);
	printf("média: %d\n", media);
}

int main(void)
{

	stack_t *s;

	// Inicializando a pilha
	stack_initialize(&s, constructor_int, destructor_int);

	int input[8] = {34, 23, 13, 7, 93, 10, 115, 17};

	// Inserindo elementos na pilha
	for (int i = 0; i < 8; i++)
	{
		stack_push(s, &input[i]);
	}

	analise(s);

	stack_delete(&s);

	return 0;
}