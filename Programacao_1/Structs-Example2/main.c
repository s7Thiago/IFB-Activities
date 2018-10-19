#include <stdio.h>
#include <stdlib.h>

#define QTDEALUNOS 3;

//Estrutura para se 'fabricar' um aluno
struct Aluno
{
    int matricula;
    float n1, n2;
    float media;
};

float calcMedia(float *n1, float *n2)
{
    return ((*n1 + *n2) / 2);
}

void lerDados(typedef struct Aluno alunos[], int quantidade)
{
    int i;
    for(i = 0; i < quantidade; i++)
    {
        printf("Digite a matricula do aluno %i: ", (i + 1));
        scanf("%i", &alunos[i].matricula);

        printf("Digite a nota 1 do aluno %i: ", (i + 1));
        scanf("%f", &alunos[i].n1);

        printf("Digite a nota 2 do aluno %i: ", (i + 1));
        scanf("%f", &alunos[i].n2);
    }
}

void imprimirDados(Aluno alunos[], int quantidade) {
    int i;
    for(i = 0; i < quantidade; i++) {
            printf("------Aluno %i------\n  -Matricula: %i\n  -Nota 1: %2f\n  -Nota 2: %.2f\n  -Media: %.2f", (i + 1), alunos[i].matricula, alunos[i].n1, alunos[i].n2, calcMedia(&alunos[i].n1, &alunos[i].n2));
        printf("\n---------------------------\n\n");
    }
}

//Executa o programa
void executar(Aluno alunos[], int quantidade) {

    lerDados(alunos, quantidade);
    imprimirDados(alunos, quantidade);

}

int main()
{
    //Definindo um tipo baseado na estrutura Aluno:
    typedef struct Aluno tipoAluno;

    //Criando as variaveis de tipoAluno:
    tipoAluno colecaoAlunos[QTDEALUNOS] = {tipoAluno a1, tipoAluno a2, tipoAluno a3};

    //Executando o programa
    executar(colecaoAlunos, QTDEALUNOS);

    printf("Hello world!\n");
    return 0;
}
