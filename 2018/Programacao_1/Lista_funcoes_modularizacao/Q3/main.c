#include <stdio.h>
#include <stdlib.h>
#define QTDE 3

void ordenar(int *valor1, int *valor2, int *valor3) {

    int i, j, conta = 0;
    int valores[QTDE] = {*valor1, *valor2, *valor3};
    int ordenado[QTDE];

    //Ordenado os valores do parâmetro num vetor
    for(i = 0; i < QTDE; i++) {
        for(j = 1; j < QTDE; j++) {
            if(valores[i] <= valores[j]) {
                ordenado[i] = valores[i];
            } else {
                ordenado[i] = valores[j];
            }
        }
    }

    *valor1 = ordenado[0];
    *valor2 = ordenado[1];
    *valor3 = ordenado[2];
}

int main() {

    int a = 6, b = 2, c = 7;

    //Ordenando
    ordenar(&a, &b, &c);

    printf("\nValores ordenados:\n%i\n%i\n%i\n", a, b, c);

    return 0;
}
