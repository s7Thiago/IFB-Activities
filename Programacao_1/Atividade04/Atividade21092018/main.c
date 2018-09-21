#include <stdio.h>
#include <stdlib.h>

void retornaSomaESubtracao(int *a, int *b) {
    int aux;

    aux = *a + *b;
    (*b) = *a - *b;
    (*a) = aux;
}

int main() {

    int x = 2, y = 4;


    printf("Valor 'x': %i\n Valor 'y': %i", x, y);
    retornaSomaESubtracao(&x, &y);

    printf("\n\nSoma: %i\nSubtracao: %i\n\n", x, y);

    return 0;
}
