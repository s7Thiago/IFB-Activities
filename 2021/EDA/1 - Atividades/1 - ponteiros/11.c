/*
. Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereco das posicoes contendo valores pares.
*/

#include <stdio.h>

int main (void) {
	
	int tam = 5;
	int array[tam];
	
	for(int i = 0; i < tam; i++){
		printf("%d:  ", i);
		scanf("%d", &array[i]);
	}
	
	for(int i = 0; i < tam; i++){
		if(i % 2 == 0)
			printf("[%d]: %p\n", i, (&array[i]));
	}
	
	

	return 0;
}

