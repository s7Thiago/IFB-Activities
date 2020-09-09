#include "alunos.h"
#include "turma.h"



char alunos[MAX_CADASTRO][TAM_NOME_ALUNO] = {
	/*"Ana",
	"Thiago",
	"Paulo",
	"Carlos",
	"Matheus",
	"Marcos",
	"Amanda",
	"Aline",
	"Francisca",*/
	};

//
extern void printTurmas();
extern int ultimaTurmaCadastrada();
extern int posicaoVaziaTurma(int turma);
extern int turmas[MAX_TURMAS][MAX_ALUNOS];

void printAlunos(){
	for (int i = 0; i < MAX_CADASTRO; i++){
		printf("[%s]", alunos[i]);
	}
	printf("\n");
}

int ultimoAlunoCadastrado(){
	int alunoIndex = 0;
	
	for (int i = 0; i < MAX_CADASTRO; i++){
		if(alunos[i][0] != '\0'){
			alunoIndex++;
		}
	}
	return alunoIndex;
}

int indiceAluno(char* nome){
	for (int i = 0; i < MAX_CADASTRO; i++){
		if(strcmp(alunos[i], nome) == 0) return i;
	}
	return -1;
}

void cadastrarNovoAluno(char* nome){
	if(!(indiceAluno(nome) > -1)){
		if(ultimoAlunoCadastrado() != 10){
			strcat(alunos[ultimoAlunoCadastrado()], nome);
			printf("\nLISTA DE ALUNOS ATUALIZADA:\n");
			printAlunos();
		} else printf("\n\n%s\n", ERRO_4);
	} else printf("\n\n%s [%s]\n", ERRO_3, nome);
}

void incluirAlunoNaTurma(int turma, char* aluno){

	int indexAluno = indiceAluno(aluno);
	
	if(indexAluno > -1) {
		turmas[turma][posicaoVaziaTurma(turma)] = indexAluno;
	} else printf("\n\n%s\n", ERRO_5);

	printf("\nTURMA %d ATUALIZADA:\n", turma);
	printTurmas();
}




























