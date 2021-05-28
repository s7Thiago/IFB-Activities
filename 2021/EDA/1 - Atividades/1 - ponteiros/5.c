/*
Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes 2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na segunda variavel. Escreva o conteudo das 2 variaveis na tela.
*/
#include <stdio.h>

void maior(int* a, int* b){
	printf("\n");
	
	if (a > b)
		printf("o maior é A: %d\n\n", a);
	else
		printf("o maior é B: %d\n\n", b);
}

int main (void) {	
	int a, b;
	
//  Recebendo as entradas pelo teclado
	printf("type [a]: ");
	scanf("%d", &a);
	
	printf("type [b]: ");
	scanf("%d", &b);
	
// Verificando
	maior(a, b);

	return 0;
}

