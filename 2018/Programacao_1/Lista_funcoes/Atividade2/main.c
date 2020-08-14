#include <stdio.h>
#include <stdlib.h>

float calcMedia(float nota1, float nota2, float nota3, char operacao) {

    float media, mediaPonderada, mediaHarmonica;

    switch(operacao) {
    case 'A':
    case 'a':
        //Calcula a media normal
        media = ((nota1 + nota2 + nota3)/3);

        return media;
        break;

    case 'P':
    case 'p':
        //Calcula a media ponderada
        mediaPonderada = (((5 * nota1) + (3 * nota2) + (2 * nota3))/3);
        return mediaPonderada;
        break;

    case 'H':
    case 'h':
        //Calcula a media harmonica
        mediaHarmonica = (3/(1/nota1) + (1/nota2) + (1/nota3));
        return mediaHarmonica;
        break;

    case 'X': case 'x':
        printf("Finalizando execucao");
        break;

    default:
        printf("Opcao invalida");
        break;
    }

    return 0;
}

int main() {
    float a, b, c, resultado;
    char operacao;

    printf("\nDigite a operacao desejada 'A', 'P', ou 'H': ");
    scanf("%c", &operacao);

    printf("Digite a primeira nota: ");
    scanf("%f", &a);

    printf("Digite a segunda nota: ");
    scanf("%f", &b);

    printf("Digite a terceira nota: ");
    scanf("%f", &c);

    resultado = calcMedia(a, b, c, operacao);

    printf("\n\nResultado: %.2f\n\n", resultado);

    return 0;
}
