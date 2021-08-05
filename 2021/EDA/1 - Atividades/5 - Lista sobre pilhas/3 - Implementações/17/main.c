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

int main(void)
{

	stack_t *s;
	long int a, b, c;
	int n, cont;
	double r;

	// Inicializando a pilha
	stack_initialize(&s, constructor_int, destructor_int);

	printf("Digite quantos termos da sequencia de Fibonacci voce quer:\n");
	scanf("%d", &n);

	if (n <= 1)
	{
		printf("Numero de termos invalido\n");
	}
	else
	{

		a = 1;
		b = 1;
		cont = 2;
		printf("\n\n1\n1\n");

		while (cont < n)
		{
			c = a + b;
			r = c;
			r = r / b;
			printf("%ld / %.15lf\n", c, r);
			a = b;
			b = c;
			cont = cont + 1;

			stack_push(s, &c);
		}
	}

	showstack(s);
	stack_delete(&s);
	return 0;
}