#include <stdio.h>
#include <stdlib.h>

//criando a função
float calcMedia(float nota1,float nota2,float nota3, char operacao) {
    float media, ponderada, harmonica;


    switch(operacao){
case 'A':
    media = (nota1 + nota2 + nota3)/3;
    return media;
    break;

case 'P':
    ponderada = 5 * nota1 + 3 * nota2 + 2 * nota3;
    return ponderada;
    break;

case 'H':
    harmonica=(3 / (1 / nota1) + (1 / nota2) + (1 / nota3));
    return harmonica;
    break;
default:
    printf("Opcao invalida");
    break;
    }
    return 0;
}


int main()
{   float a, b, c, resultado;
    char letra;

    printf("Digite a letra:");
     scanf("%c",&letra);

    printf("Digite a nota 1: ");
    scanf("%f",&a);

    printf("\nDigite a nota 2: ");
    scanf("%f",&b);

    printf("\nDigite a nota 3: ");
    scanf("%f",&c);

    resultado = calcMedia(a, b, c, letra);
        printf("O resultado e: %.2f",resultado);

        return 0;
}
