#include <stdio.h>
#include <stdlib.h>

int mediaValores(int valores[], int qtde) {
    int i, media = 0, soma;
    //Calculando a media dos valores
    for(i = 0; i < qtde; i++) {
        soma += valores[i];
    }

    media = soma/qtde;

    return media;

}

int main()
{

    int qtde = 0, media = 0;

    do{
    printf("Digite a quantidade de valores: ");
    scanf("%i", &qtde);

    //Prrnchendo o vetor
    int valores[qtde];

    for(int i = 0; i < qtde; i++) {
        printf("Digite o valor %i: ", i + 1);
        scanf("%i", &valores[i]);
    }

    media = mediaValores(valores, qtde);

    printf("\nResultado: %i\n\n_______________________________________\n\n", media);
    }while(qtde != 0);

    return 0;
}
