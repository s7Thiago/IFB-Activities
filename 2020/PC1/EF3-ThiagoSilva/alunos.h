#ifndef ALUNOS_H
#define ALUNOS_H

#define MAX_CADASTRO 10
#define TAM_NOME_ALUNO 50

#define ERRO_3 "Aluno já cadastrado"
#define ERRO_4 "Número máximo de alunos cadastrados"
#define ERRO_5 "erro ao incluir aluno na turma"

#include <stdio.h>
#include <string.h>
#include "turma.h"

//
void cadastrarNovoAluno(char* nome);

//
void incluirAlunoNaTurma(int turma, char* aluno);

#endif
