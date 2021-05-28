/*
Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereco de cada posicao dessa matriz.
*/

#include <stdio.h>

int main (void) {
	
	int tam = 3;
	float array[tam][tam];
	
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			printf("[%d][%d]: %p\n", i, j, &array[i][j]);
		}
	}

	return 0;
}

