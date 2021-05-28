/*
Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereco de cada posicao desse array.
*/

#include <stdio.h>

int main (void) {
	
	int tam = 10;
	float array[tam];
	
	for(int i = 0; i < 10; i++){
		printf("(%d)[i]: %p\n", (i + 1), &array[i]);
	}

	return 0;
}

