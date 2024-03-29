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
	char *str = "ESTE EXERCICIO E MUITO FACIL.";
	char *resultado = mallocx(sizeof(char) * strlen(str));
	int cont = 0;

	// Inicializando a pilha
	stack_initialize(&s, constructor_char, destructor_char);

	printf("\ntexto: %s\nsaída:", str);

	// Inserindo os elementos na pilha
	for (int i = 0; i < strlen(str); i++)
	{
		cont++;
		stack_push(s, &str[i]);

		// Sempre que encontrar um espaço, insere os elementos dela no resultado e esvazia a pilha
		if (str[i] == ' ' || str[i] == '.')
		{
			while (!stack_empty(s))
			{
				char c = *(char *)stack_top(s);

				if (c == '.')
				{
					c = ' ';
				}

				printf("%c", c);
				stack_pop(s);
			}

			cont = 0;
		}
	}

	// Imprimindo a pilha
	// print_stack(s);

	stack_delete(&s);
	return 0;
}
