/*
Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada
valor lido.
*/

#include <stdio.h>

int main (void) {
	
	int tam = 5;
	int array[tam];
	int *ptr = array;
	
	for(int i = 0; i < tam; i++){
		printf("%d:  ", i + 1);
		scanf("%d", &ptr[i]);
	}
	
	for(int i = 0; i < tam; i++){
		printf("[%d]: %d\n", i, (ptr[i]) * 2);
	}
	
	

	return 0;
}

