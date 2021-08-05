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
void showstack(stack_t *stack)
{
	stack_iterator_t it;

	printf("[ ");
	for (it = stack->top; it != NULL; it = it->next)
	{
		printf("%c, ", *(char *)it->data);
	}
	printf("{ NULL } ]");
}

int main(void)
{

	stack_t *s;
	// stack_t *tmp;
	char *strcorreta = "(())–(()())–()()";
	char *strincorreta = ")(–(()(–))((";
	char *target = strcorreta;

	// Inicializando as pilhas
	stack_initialize(&s, constructor_char, destructor_char);
	// stack_initialize(&tmp, constructor_char, destructor_char);

	// insere os elementos da string na pilha
	// printf("%d", strlen(target));

	printf("entrada: ");
	for (int i = 0; i < strlen(target); i++)
	{
		printf("%c", target[i]);
		stack_push(s, &target[i]);
	}

	printf("\n");
	// showstack(s);

	stack_iterator_t it;
	int contStarts = 0;
	int contEnds = 0;

	// Verificando cada elemento na pilha e contando o número de aberturas e fechamentos
	for (it = s->top; it != NULL; it = it->next)
	{
		char elemento = *(char *)it->data;
		if (elemento == '(')
			contStarts++;

		if (elemento == ')')
			contEnds++;
	}

	if (contStarts == contEnds)
	{
		printf("\nCORRETO\n");
	}
	else
	{
		printf("\nINCORRETO\n");
	}

	stack_delete(&s);
	return 0;
}
