#include <stdio.h>
#include <string.h>


#define TAM_MAX 500

// Retorna o tamanho de uma string
int strlength(char* target) {
	int size = 0;
	while(target[size] != '\0'){
	size++;
	}
	
	return size;
}

// Retorna um inteiro correspondente a quantidade de pontos (.) na string target
int dotCount(char* target){
	int count = 0;
	for (int i = 0; i < strlength(target); i += 1){
		if(target[i] == '.'){
			count++;
		}
	}
	
	return count;
}

// Adiciona uma quebra de linha sempre que encontra um ponto (.) na string
void compute(char* target){
	char output[TAM_MAX];
	
	for (int i = 0; i < TAM_MAX; i++){
		output[i] = '\0';
	}
	
	for (int i = 0; i < strlength(target); i++){
		char currentCharacter[2] = "";
		currentCharacter[0] = target[i];
		currentCharacter[1] = '\0';
		
		strcat(output, currentCharacter);
		
		
		if(target[i] == '.'){
			strcat(output, "\n\n");
		}
	}
	
	//strcat(output, "\0");
	printf("%s\n\n", output);
	
}


int main (void) {

	char input[TAM_MAX] = "“The Ugly Duckling is an animated film from 1939 by Walt Disney, based on the fairy tale \"The Ugly Duckling\" by Hans Christian Andersen. The film was directed by Jack Cutting and Clyde Geronimi, and released in theaters on April 7, 1939. Music was composed by Albert Hay Malotte, who was uncredited for the film. The animated short was first distributed by RKO Radio Pictures.";
	
	printf("Input: \n\n%s\n\n\n\n", input);
	
	puts("Output:\n");
	compute(input);
	
	return 0;
}







