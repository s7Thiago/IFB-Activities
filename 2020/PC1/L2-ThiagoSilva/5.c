#include <stdio.h>
#include <string.h>  

#define LINES 3
#define COLS 5

// Imprime a matriz recebida com um rótulo e formatada em linhas e colunas (3x5)
void printMatrix(char matrix[LINES][COLS], char* label, int mode){

	printf("%s\n", label);
	for (int i = 0; i < LINES; i++){
		printf("	");
		for (int j = 0; j < COLS; j++){
			if(mode <= 0) printf("%c  ", matrix[i][j]);
			else printf("%c[%d, %d]  ", matrix[i][j], i, j);
		}
		printf("\n\n");
	}
}

// Imprime a matriz recebida com um rótulo e formatada em linhas e colunas (5x3)
void printTransposed(char matrix[COLS][LINES], char* label, int mode){

	printf("%s\n", label);
	for (int i = 0; i < COLS; i++){
		printf("	");
		for (int j = 0; j < LINES; j++){
			if(mode <= 0) printf("%c  ", matrix[i][j]);
			else printf("%c[%d, %d]  ", matrix[i][j], i, j);
		}
		printf("\n\n");
	}
}

// Gera a matriz transposta baseada na matriz recebida por parâmetro
void transpose(char matrix[LINES][COLS], int outpudMode){
	char transposed[COLS][LINES];
	
	//
	printMatrix(matrix, "Input", outpudMode);
	
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLS; j++){
			transposed[j][i] = matrix[i][j];
		}
	}
	
	printTransposed(transposed, "Output", outpudMode);
}

int main (void) {

	char input[LINES][COLS] = {
		"abcde",
		"fghij",
		"klmno"
	};
	
	transpose(input, 0);
	
	return 0;
}
