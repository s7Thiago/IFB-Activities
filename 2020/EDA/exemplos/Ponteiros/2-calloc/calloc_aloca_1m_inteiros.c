#include <stdio.h>
#include <stdlib.h>

/*

	Algoritmo que aloca o espaço em memória 
	suficiente para armazenar 1 milhão de 
	inteiros

*/

int main (void) {
	
	// Aloca o espaço para 1M de inteiros (num * size);
	// o malloc equivalente é:
	// int* ptr = malloc(sizeof(int) * 1000000);
	int* ptr = calloc(sizeof(int), 1000000);
	
	return 0;
}

