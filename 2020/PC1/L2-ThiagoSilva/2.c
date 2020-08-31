#include <stdio.h>
#include <string.h>

#define TAM 8


// realiza um shift logic left
char* moveLeft(char target[TAM], int displacement){
	char targetFragment[TAM];
	char sll[9];
	
	// Primeiro estágio => move os bits necessários para a esquerda e armazena
	// em targetFragment
	for (int i = displacement;i < TAM; i++){
		targetFragment[i - displacement] = target[i];
	}
	
	//printf("\nEstágio 1: %s\n", targetFragment);
	
	// Segundo estágio => adiciona os bits esperados no espaço vazio de targetFragment
	for (int i = TAM - displacement; i < TAM; i++){
		targetFragment[i] = '0';
	}
	
	//printf("Estágio 2: %s\n", targetFragment);
	strcat(sll, targetFragment);
	
	return strcat(sll, "\0");

}

int main (void) {

	char input[TAM];
	int displacement;
	
	do{
	
	printf("\n🔟️  Digite > ");
	scanf("%s", input);
	
	printf("⬅️   Mover > ");
	scanf("%d", &displacement);
	
	// realizando o SLL com moveLeft e armazenando em sll	
	char* sll = moveLeft(input, displacement);
	printf("✅️  Resultado: %s\n\n", sll);
	
	}while(input[0] != '-');
	
	return 0;
}
