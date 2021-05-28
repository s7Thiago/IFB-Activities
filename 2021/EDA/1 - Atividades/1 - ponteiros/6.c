/*
Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faca uma funcao
que retorne a soma do dobro dos dois numeros lidos. A funcao devera armazenar o dobro
de A na propria variavel A e o dobro de B na propria variavel B.
*/
#include <stdio.h>

void calc(int* a, int* b){
	*a += (*a * *a);
	*b += (*b * *b);
}

int main (void) {	
	int a, b;
	
//  Recebendo as entradas pelo teclado
	printf("type [a]: ");
	scanf("%d", &a);
	
	printf("type [b]: ");
	scanf("%d", &b);
	
//	antes do calculo
	printf("\n[ANTES]\n[a]: %d\n[b]: %d\n", a, b);
	
// Calculando
	calc(&a, &b);
	
//	depois do calculo
	printf("\n[DEPOIS]\n[a]: %d\n[b]: %d\n", a, b);

	return 0;
}

