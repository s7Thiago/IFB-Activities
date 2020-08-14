#include <stdio.h>
#include <stdlib.h>

#define QTDE 5

void maiorEMenor(int valores[QTDE]) {
    int cont = 0;

    //imprime o maior valor da colecao
    for(int i = 0; i < QTDE; i++) {
        for(int j = 0; j < QTDE; j++) {
            if(valores[i] >= valores[j]) {
                cont++;
            }
        }
        //
        if(cont == QTDE) {
            printf("Maior valor: %i", valores[i]);
        }
    }

    cont = 0;

    //imprime o menor valor da colecao
    for(int i = 0; i < QTDE; i++) {
        for(int j = 0; j < QTDE; j++) {
            if(valores[i] <= valores[j]) {
                cont++;
            }
        }
        //
        if(cont == QTDE) {
            printf("Menor valor: %i", valores[i]);
        }
    }
}

int main() {

    int valores[QTDE];

    //preenchendo o vetor
    for(int i = 0; i < QTDE; i++) {
        printf("Digite o valor %i:", i + 1);
        scanf("%i", &valores[i]);
    }

    //mostrando o maior e o menor
    maiorEMenor(valores);

    return 0;
}
