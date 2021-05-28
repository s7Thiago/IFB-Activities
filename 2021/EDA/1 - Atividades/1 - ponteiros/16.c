/*
Considere a seguinte declaracao: int A, *B, **C, ***D; Escreva um programa que leia a variavel a e calcule e exiba o dobro, o triplo e o quadruplo desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quadruplo
*/

#include <stdio.h>


int main (void) {	
	
	int a;
	int *b, **c, ***d;
	
	printf(">  ");
	scanf("%d", &a);
	
//	Atribuicoes
	b = &a;
	c = &b;
	d = &c;
	
//	Calculando o drobro
	*b = a * 2;
	printf("dobro: %d\n", *b);
	
// Calculando o triplo
	**c = 3 * (*b / 2);
	printf("triplo: %d\n", **c);
	
	***d = 4 * (**c / 3); 
	printf("quadruplo: %d\n", ***d);

	return 0;
}
































