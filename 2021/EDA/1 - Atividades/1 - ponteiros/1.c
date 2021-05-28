/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a modificacao.
*/

#include <stdio.h>

int main (void) {

//	vars
	int i = 5;
	double r = 10.5;
	char c = 'A';
	
//  ptrs
	int *ptri = &i;
	double *ptrr = &r;
	char *ptrc = &c;

// Mostrando os valores das variáveis antes de manipular
printf("[ANTES DA TROCA]\n");
printf("[i]: %d\n", i);
printf("[r]: %.2f\n", r);
printf("[c]: %c\n", c);

	
//  Alterando os valores através dos ponteiros
*ptri = 15;
*ptrr = 20.5;
*ptrc = 'b';


// Mostrando os valores das variáveis depois de manipular
printf("\n\n[DEPOIS DA TROCA]\n");
printf("[i]: %d\n", i);
printf("[r]: %.2f\n", r);
printf("[c]: %c\n", c);
	
	
	
	return 0;
}

