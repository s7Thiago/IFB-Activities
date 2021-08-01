#include "pilha_lista.h"

// Construtor para um tipo char
void *constructor_char(void *data)
{
	void *ptr = mallocx(sizeof(char));
	memcpy(ptr, data, sizeof(char));
	return ptr;
}

// Funcao destrutora para um tipo char
void destructor_char(void *data)
{
	free(data);
}

// Imprime de maneira didática os elementos de uma pilha
void print_stack(stack_t *stack)
{
	while (!stack_empty(stack))
	{
		char c = *(char *)stack_top(stack);
		printf("[%c]", c);
		if (stack_size(stack) > 1)
			printf("->");

		stack_pop(stack);
	}
}

int main(void)
{

	stack_t *s;
	char *str = "ARARA";
	char *resultado = mallocx(strlen(str));

	// Inicializando a pilha
	stack_initialize(&s, constructor_char, destructor_char);

	// Inserindo os elementos na pilha
	for (int i = 0; i < strlen(str); i++)
	{
		stack_push(s, &str[i]);
	}

	// Armazenando elementos da pilha em resultado na ordem inversa
	int cont = 0;
	while (!stack_empty(s))
	{
		char c = *(char *)stack_top(s);
		resultado[cont] = c;
		stack_pop(s);
		cont++;
	}

	// Imprimindo a pilha
	print_stack(s);

	printf("\nentrada: %s\n", str);
	printf("reverso: %s\n=============================\n\n", resultado);

	if (strcmp(str, resultado) == 0)
	{
		printf("É um palíndromo");
	}
	else
	{
		printf("Não é palíndromo");
	}

	printf("\n\n");

	stack_delete(&s);
	return 0;
}