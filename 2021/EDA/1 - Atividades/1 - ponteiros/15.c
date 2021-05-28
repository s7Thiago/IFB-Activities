/*
Crie uma funcao que receba como parametro um array e o imprima. Nao utilize ındices
para percorrer o array, apenas aritmetica de ponteiros.
*/

#include <stdio.h>
#include <string.h>

int print(char* target){
	int i = 0, tam = 0;
	
//	Dexcobrindo o tamanho da string
	for(size_t t = 0; target[t] != '\0'; t++)
		tam++;
	
	while(i < tam){
		printf("%c", *(target + i));
		i++;
	}
}


int main (void) {	
	
	char *target = "Ifb2021";
	
	printf("\n");
	print(target);
	printf("\n\n");

	return 0;
}
































