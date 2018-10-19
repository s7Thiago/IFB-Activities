#include <stdio.h>
#include <stdlib.h>

void ordenar(int *valor1, int *valor2, int *valor3) {

    int i, j;
    int valores[3] = {*valor1, *valor2, *valor3};
    int ordenado[3];

    for(i = 0; i < 3; i++) {
        for(j = 2; j > 0; j++) {
            if(valores[i] <= valores[j]) {
                ordenado[i] = valores[j];
            }
        }
    }

    *valor1 = ordenado[0];
    *valor2 = ordenado[1];
    *valor3 = ordenado[2];
}

int main() {

    int a = 4, b = 9, c = 1;

    ordenar(&a, &b, &c);

    printf("\nValores ordenados:\n%i\n%i\n%i\n", a, b, c);

    return 0;
}
