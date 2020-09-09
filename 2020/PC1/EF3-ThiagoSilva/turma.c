#include "turma.h"
#include "alunos.h"

extern char alunos[MAX_CADASTRO][TAM_NOME_ALUNO];

int turmas[MAX_TURMAS][MAX_ALUNOS] = {
	
	// Representação exemplo de 3 turmas vazias
	2, 0, 3, 1, -1,
	//-1, -1, -1, -1, -1,
	//-1, -1, -1, -1, -1,

};

int ultimaTurmaCadastrada(){
	int indexTurma = 0;
	
	for (int i = 0; i < MAX_TURMAS; i++){
		if(turmas[i][0] != '\0'){
			indexTurma++;
		}
	}
	
	return indexTurma;
}

void printTurmas(){
	for (int i = 0; i < MAX_TURMAS; i++){
		for (int j = 0; j < MAX_ALUNOS; j++){
			printf("%d  ", turmas[i][j]);
		}
		
		printf("\n");
	}
	printf("\n");
}

void cadastrarTurma(){
	int turmaAtual = ultimaTurmaCadastrada();
	
	if(turmaAtual != MAX_TURMAS){
		for (int i = 0; i < MAX_ALUNOS; i++){
			turmas[turmaAtual][i] = -1;
		}
	} else printf("\n\n%s\n\n", ERRO_1);
}

int posicaoVaziaTurma(int turma) {
	for (int i = 0; i < MAX_ALUNOS; i++){
		if(turmas[turma][i] == -1) return i;
	}
	
	return -1;
}

void exibirAlunos(int turma){
	if (turmas[turma][0] != '\0') {
	printf("\nAlunos inclusos na turma %d", turma);
	for (int i = 0; i < MAX_ALUNOS; i += 1){
		printf("\n	- %d [%s]", turmas[turma][i], alunos[turmas[turma][i]]);
	}
	printf("\n\n");
	} else printf("\n\n%s [%d]\n\n", ERRO_2, turma);
}





































