/*
Crie uma funcao que receba dois parametros: um array e um valor do mesmo tipo do array. A funcao devera preencher os elementos de array com esse valor. Nao utilize ındices para percorrer o array, apenas aritmetica de ponteiros.
*/

#include <stdio.h>
#include <string.h>

int fillArray(char* a, char b, int tam){
	printf("\n");
	for(int i = 0; i < tam; i++) {
		a[i] = b;
		printf("[%d] (%c)\n", i, a[i]);
	}
	a[tam] = '\0';
	printf("\n\n");
}


int main (void) {	
	
	int tam = 12;
	char target[tam];
	char value = 'w';
	
	printf("[ANTES]%s\n", target);
	
	fillArray(target, value, tam);
	
	printf("[DEPOIS]%s\n", target);

	return 0;
}
































