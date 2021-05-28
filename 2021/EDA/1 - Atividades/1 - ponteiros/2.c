/*
Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e exiba o maior endereco.
*/
#include <stdio.h>

int main (void) {	

	int i = 10, j = 10;
	
	printf("\n[MAIOR ENDERECO]");
	
	if(&i > &j)
		printf("[i] = %p", &i);
	 else 
		printf("[j] = %p", &j);
		
		printf("\n\n");
	

	return 0;
}

