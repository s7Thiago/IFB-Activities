/*
Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas
2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B tera o valor de A. 
*/
#include <stdio.h>

void swap(int* sa, int* sb){
	int aux = *sa;
	*sa = *sb;
	*sb = aux;
}

int main (void) {	
	int a, b;
	
//  Recebendo as entradas pelo teclado
	printf("type [a]: ");
	scanf("%d", &a);
	
	printf("type [b]: ");
	scanf("%d", &b);
	
	
//	Antes da troca
	printf("\n[ANTES]\n[a]: %d\n[b]: %d\n\n", a, b);
	
// Realizando a troca
	swap(&a, &b);
	
//	Depois da troca
	printf("[DEPOIS]\n[a]: %d\n[b]: %d\n\n", a, b);

	return 0;
}

