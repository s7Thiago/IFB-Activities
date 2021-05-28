/*
Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.
*/
#include <stdio.h>

int main (void) {	

	int i = 10, j = 10;
	
//  Recebendo as entradas pelo teclado
	printf("type [i]: ");
	scanf("%d", &i);
	
	printf("type [j]: ");
	scanf("%d", &j);
	
	
	printf("\n[MAIOR ENDERECO] ");
	
//	Verificando o maior endereco e imprimindo	
	if(&i > &j)
		printf("[i] = %p", &i);
	 else 
		printf("[j] = %p", &j);
		
		printf("\n\n");
	

	return 0;
}

