#ifndef TURMA_H
#define TURMA_H

#define MAX_TURMAS 3
#define MAX_ALUNOS 5

#define ERRO_1  "Limite de turmas atingido"
#define ERRO_2  "Turma não cadastrada!"

//
int ultimaTurmaCadastrada();

//
void cadastrarTurma();

//
void printTurmas();

//
void exibirAlunos(int turmaIndex);

#endif
