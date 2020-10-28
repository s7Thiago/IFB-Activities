#include "fileOperations.h"

void cleanString(char* target){
	for(int i =0; i < strlen(target); i++){
		target[i] = '\0';
	}
}

void cleanStringMatrix(char matrix[][600], int lines){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < strlen(matrix[i]); j++){
            matrix[i][j] = '\0';
        }
    }
}

void getContent(FILE* root, char* target){
	char line[200];

	// Limpando
	cleanString(line);
	cleanString(target);
	

	root = fopen("ifb.xml", "r");

	if(root != NULL){
		while(fgets(line, sizeof(line), root) != NULL){
			strcat(target, line);
		}
		puts("");
		fclose(root);
	}	
}
