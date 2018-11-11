#include <stdio.h>
#include <stdlib.h>

#define QTDEALUNOS 3

//Definindo um tipo baseado na estrutura Aluno:
    typedef struct Aluno tipoAluno;

//Estrutura para se 'fabricar' um aluno
struct Aluno {
    int matricula;
    float n1, n2;
    float media;
};

float calcMedia(float *n1, float *n2) {
    return ((*n1 + *n2) / 2);
}

void lerDados(tipoAluno *alunos) {
    int i;
    for(i = 0; i < QTDEALUNOS; i++) {
        printf("Digite a matricula do aluno %i: ", (i + 1));
        scanf("%d", &alunos[i].matricula);

        printf("Digite a nota 1 do aluno %i: ", (i + 1));
        scanf("%f", &alunos[i].n1);

        printf("Digite a nota 2 do aluno %i: ", (i + 1));
        scanf("%f", &alunos[i].n2);

        printf("\n");
    }
}

void imprimirDados(tipoAluno *alunos) {
    int i;
    for(i = 0; i < QTDEALUNOS; i++) {
            printf("------Aluno %i------\n  -Matricula: %i\n  -Nota 1: %.2f\n  -Nota 2: %.2f\n  -Media: %.2f", (i + 1), alunos[i].matricula, alunos[i].n1, alunos[i].n2, calcMedia(&alunos[i].n1, &alunos[i].n2));
        printf("\n---------------------------\n\n");
    }
}

//Executa o programa
void executar(tipoAluno *alunos[]) {

    lerDados(alunos);
    imprimirDados(alunos);

}

int main() {
    //Criando os alunos
    tipoAluno a1, a2, a3;

    //Criando as variaveis de tipoAluno:
    tipoAluno colecaoAlunos[QTDEALUNOS] = {a1, a2, a3};


    //Executando o programa
    executar(colecaoAlunos);

    return 0;
}
