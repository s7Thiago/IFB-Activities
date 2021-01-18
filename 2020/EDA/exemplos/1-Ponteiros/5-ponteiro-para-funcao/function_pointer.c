#include <stdio.h>


// Declarando um tipo de ponteiro para função
typedef int (*ptr_func_soma) (int, int);

int soma(int a, int b){
	return (a + b);
}

int main (void) {

	// Usando o tipo ptr_func_soma
	ptr_func_soma func = soma;

	// Declarando ponteiro para função que retorna
	// um inteiro e recebe 2 inteiros
	// (*ptr) com os parênteses indica um ponteiro para função
	int (*ptr) (int, int);
	
	// Fazendo o ponteiro apontar para a nossa função soma
	ptr = soma;
	
	// Chamando a função soma através do ponteiro
	printf("Resultado: %d\n", ptr(50, 50));
	
	// Chamando a função através do tipo criado
	printf("Resultado tipo: %d\n", func(30, 31));
	
	
	
	return 0;
}
	
