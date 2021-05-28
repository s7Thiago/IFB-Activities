/*
Escreva uma funcao que dado um numero real passado como parametro, retorne a parte inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao. 
Prototipo:

void frac(float num, int* inteiro, float* frac);
*/

#include <stdio.h>

void frac(float num, int* inteiro, float* frac) {
	*inteiro = (int)num;
	*frac = num - *inteiro; 
}


int main (void) {

	float value = 15.47;
	int inteiro;
	float fraction;
	
	frac(value, &inteiro, &fraction);
	
	printf("[num]: %.2f\n[int]: %d\n[frc]: %.2f\n", value, inteiro, fraction);
	

	return 0;
}
































