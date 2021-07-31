#include "pilha_lista.h"

// ! Funções auxiliares para o tipo char

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

// ! $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//limpa uma string
void cleanstring(char *str, int size)
{
	for (int i = 0; i < size; i++)
	{
		str[i] = '\0';
	}
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

// Exibe os dados armazenados em um objeto pessoa
void printstr(const char *s)
{
	printf("%s\n", s);
}

void isArbitraryString(char *str)
{
	// Tentando identificar casos inválidos
	// Se o tamanho da string não for par, certamente não obedece a regra
	if (strlen(str) % 2 != 0)
		return;

	stack_t *sX;

	char *strX;
	char *strY;

	// Inicializando cada uma das pilhas
	stack_initialize(&sX, constructor_char, destructor_char);

	// Gravando cada metade da string em strX e strY
	for (int i = 0; i < strlen(str); i++)
	{
		if (i < strlen(str) / 2)
		{
			strX[i] = str[i];
			stack_push(sX, &strX[i]);
		}
	}

	// copiando o conteúdo de strX para strY
	strY = strX;

	// Copiando a segunda metade de str par strX
	for (int i = strlen(str) / 2; i < strlen(str); i++)
	{
		if (i < strlen(str))
		{
			strX[i] = str[i];
		}
	}

	// * Imprimindo de forma didática o conteúdo da pilha
	// print_stack(sX);

	// * Desempilhando em strY para comparar se é uma string arbitrária

	// * Mostrando o tamanho das strings
	printf("\n\nsize X: %d\n", strlen(strX));
	printf("size Y: %d\n\n", strlen(strY));

	//  * Imprimindo as strings
	printstr(strX);
	printstr(strY);

	stack_delete(&sX);
}

int main(void)
{
	char *str = "ABCDDCBA";
	// int size = strlen(str);

	// char *x;
	// char *y;

	// for (int i = 0; i < size; i++)
	// {
	// 	if (i < size / 2)
	// 	{
	// 		x[i] = str[i];
	// 	}
	// 	else
	// 		y[i] = str[i];
	// 	{
	// 	}
	// }

	// printf("\nstr = %s", str);
	// printf("\nx = %s", x);
	// printf("\ny = %s", y);

	isArbitraryString(str);
	return 0;
}
