#include <stdio.h>
#include <stdlib.h>

float calcMedia(float nota1, float nota2, float nota3, char operacao) {

    float media, mediaPonderada, mediaHarmonica;

    switch(operacao) {
    case 'A':
        //Calcula a media normal
        media = ((nota1 + nota2 + nota3)/3);

        return media;
        break;

    case 'P':
        //Calcula a media ponderada
        break;

    case 'H':
        //Calcula a media harmonica
        break;

    default:
        printf("Opcao invalida");
        break;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
