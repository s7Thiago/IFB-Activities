/*
Crie um programa que contenha uma funcao que permita passar por parametro dois numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal.
*/

#include <stdio.h>

void soma(int* a, int* b){
	*a = *a + *b;
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
	soma(&a, &b);
	
//	depois do calculo
	printf("\n[DEPOIS]\n[a]: %d\n[b]: %d\n", a, b);

	return 0;
}

