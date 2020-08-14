#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{

    //Declarando o vetor
    int vetor[] = {9, 23, 2, 33, 12, 19, 41};

    //imprindo o tamanho do vetor
    int tam_vetor = ((sizeof(vetor))/(sizeof(int)));
    printf("tamanho do vetor :%d\n", tam_vetor);

    //imprimindo um elemento do vetor
    int posicao_elemento = 4;
    printf("Elemento %d: %d\n", posicao_elemento, vetor[posicao_elemento]);

    //Imprimindo uma soma com o vetor
    int soma_vetor = vetor + 1;
    printf("Vetor normal: %d\nVetor + 1: %d\n", vetor, soma_vetor);

    //Limpar a tela
    printf("Deseja limpar a tela? [s, n]: ");
    char comando;
    scanf("%c", &comando);

    if(comando == 's') {
        printf("\n\nLimpando a tela.........\n\n");
        system("cls");
    }

    return 0;
}
