#include <stdio.h>
#include <stdlib.h>

float calcMedia(float *n1, float *n2){

return (*n1 + *n2)/2;
}

//Criando o tipo personalizado de dado
typedef struct {
    int matricula;
    float n1, n2;
    float media;
} Aluno;

int main() {
    //Criando variaveis do tipo personalizado
    Aluno a1, a2;

    a1.matricula = 154664633488;
    a1.n1 = 7.5f;
    a1.n2 = 9.5f;
    a1.media = calcMedia(&a1.n1, &a1.n2);

    a2.matricula = 154664633489;
    a2.n1 = 6.8f;
    a2.n2 = 7.3f;
    a2.media = calcMedia(&a2.n1, &a2.n2);



    //Imprimindo as propriedades do aluno1;

    printf("-----Aluno 1-----\nmatricula: %i\nnota 1: %.2f\nnota 2: %.2f\nmedia: %2.f", a1.matricula, a1.n1, a1.n2, a1.media);

    //Imprimindo as propriedades do aluno2;

     printf("\n\n-----Aluno 2-----\nmatricula: %i\nnota 1: %.2f\nnota 2: %.2f\nmedia: %2.f", a2.matricula, a2.n1, a2.n2, a2.media);


    return 0;
}
