#include "fileOperations.h"

// Limpa uma string inserindo null (\0) em todas as posições
void cleanString(char* target){
	for(int i =0; i < strlen(target); i++){
		target[i] = '\0';
	}
}

void getContent(FILE* root, char* target){
	char line[200];

	// Limpando
	cleanString(line);
	cleanString(target);
	

	root = fopen("bbc.xml", "r");

	if(root != NULL){
		while(fgets(line, sizeof(line), root) != NULL){
			strcat(target, line);
		}
		puts("");
		fclose(root);
	}	
}
