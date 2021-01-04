#include <stdio.h>
#include <string.h>

#define FILENAME "1.fasta"

int charCount(char* target, char c){
	int qtde = 0;
	for (int i = 0; i < strlen(target); i++)
		if(target[i] == c)qtde++;
	return qtde;
}

int main (void) {
	
	FILE* target;
	char content[200];
	int linesCount = 0;
	int qtdes[4];
	
	target = fopen(FILENAME, "r");
	
	if(target != NULL){
		// Lendo o arquivo linha-a-linha
		while(fgets(content, sizeof(content), target) != NULL){
			linesCount++;
			if(strcmp(content, ">id\n") != 0 && linesCount != 1){
				qtdes[0] += charCount(content, 'A');
				qtdes[1] += charCount(content, 'C');
				qtdes[2] += charCount(content, 'T');
				qtdes[3] += charCount(content, 'G');
		}
	}
}
	
	double numerador = qtdes[3] + qtdes[1];
	double denominador = numerador + qtdes[0] + qtdes[2];
	double total = (numerador/denominador) * 100;
	
	printf("\n\nResultado: %.2f\n", total);
	fclose(target);
	return 0;
}
