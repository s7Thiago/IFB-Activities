#include "alunos.h"
#include "turma.h"

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
	int indexTurma = 0;
	char nomeAluno[TAM_NOME_ALUNO];
	
	do{
	
		printMenu();
	
		printf("Escolha > ");
		scanf("%d", &option);
		
		switch(option){
		
			case 1:
				cadastrarTurma();
			
				printf("Nova turma inserida\n");
				printTurmas();
			break;
			
			case 2:
				printf("Nome > ");
				scanf("%s", nomeAluno);
				cadastrarNovoAluno(nomeAluno);
			
			break;
			
			case 3:
				printf("Turma > ");
				scanf("%d", &indexTurma);
			
				printf("Nome > ");
				scanf("%s", nomeAluno);
			
				incluirAlunoNaTurma(indexTurma, nomeAluno);
				
			break;
			
			case 4:
				printf("Índice > ");
				scanf("%d", &indexTurma);
			
				exibirAlunos(indexTurma);
			break;
			
			case 5:
			break;
			
			default:
				printf("Opção desconhecida");
		}
	
	}while(option != 5);
	
	return 0;
}
