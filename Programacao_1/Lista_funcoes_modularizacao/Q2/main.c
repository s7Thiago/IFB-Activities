#include <stdio.h>
#include <stdlib.h>

//criando a fun��o
float calcMedia(float nota1,float nota2,float nota3, char operacao) {
    float media, ponderada, harmonica;


    switch(operacao) {
    case 'A':
    case 'a':
        media = (nota1 + nota2 + nota3)/3;
        return media;
        break;

    case 'P':
    case 'p':
        ponderada = 5 * nota1 + 3 * nota2 + 2 * nota3;
        return ponderada;
        break;

    case 'H':
    case 'h':
        harmonica=(3 / (1 / nota1) + (1 / nota2) + (1 / nota3));
        return harmonica;
        break;

    default:
        printf("Opcao invalida");
        break;
    }
    return 0;
}


int main() {
    float a, b, c, resultado;
    char letra;

    printf("Digite a letra: ");
    scanf("%c",&letra);

    printf("\nDigite a nota 1: ");
    scanf("%f",&a);

    printf("\nDigite a nota 2: ");
    scanf("%f",&b);

    printf("\nDigite a nota 3: ");
    scanf("%f",&c);

    resultado = calcMedia(a, b, c, letra);

    printf("\n----------------------------------------\n");
    printf("Media: %.2f",resultado);
    printf("\n----------------------------------------\n");

    return 0;
}
