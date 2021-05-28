/*
. Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereco das posicoes contendo valores pares.
*/

#include <stdio.h>

int sort(int* a, int* b, int* c){
	int auxA = *a, auxB = *b, auxC = *c;

	if(*a == *b && *b == *c) {
		return 1;
	} else {
		if(*a > *b) {
			*a = auxA;
			*b = auxB;
		} else {
			*a = auxB;
			*b = auxA;
		}
		
		if(*a > *c) {
			*c = auxA;
			if (*b > *c) {
				*a = auxB;
				*b = auxC;
			} else {
				*a = auxC;
			}
		} else *c = auxC;
		
		return 0;
	}
	
}


int main (void) {

	int a, b, c;
	
	printf("a:  ");
	scanf("%d", &a);
	
	printf("b:  ");
	scanf("%d", &b);
	
	printf("c:  ");
	scanf("%d", &c);
	
	sort(&a, &b, &c);
	
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("b: %d\n", c);
	
	
	

	return 0;
}
































