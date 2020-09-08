#include <stdio.h>

//#include "turma.h"

char menu[][35] = {
	"========= --- =========\n",
	"1 - Cadastrar turma",
	"2 - Cadastrar aluno",
	"3 - Incluir aluno na turma",
	"4 - Exibir alunos de uma turma",
	"5 - Sair"
};

void printMenu(){

	printf("\n");
	for (int i = 0; i < 5; i++){
		printf("%s\n", menu[i]);
	}
	
	printf("\n");
}

int main (void) {

	int option = 0;
	
	do{
	
		printMenu();
	
		printf("Escolha > ");
		scanf("%d", &option);
		
		switch(option){
		
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			default:
			printf("Opção desconhecida");
		}
	
	}while(option != 5);
	
	return 0;
}
