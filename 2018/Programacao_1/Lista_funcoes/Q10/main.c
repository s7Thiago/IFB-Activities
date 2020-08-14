#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int verificaPar(int valor) {
    //Se retornar 1, o numero e par
    if(valor % 2 == 0) {
    return TRUE;

    //Se retornar 0, o numero e impar.
    }else {
    return FALSE;
    }
}

int main() {

    int valor, teste;

    printf("Digite algum valor inteiro: ");
    scanf("%i", &valor);

    teste = verificaPar(valor);

    if(teste == 0) {
            printf("\n\nValor impar\n\n");
    } else {
            printf("\n\nValor par\n\n");

    }
    return 0;
}
