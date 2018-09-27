#include <stdio.h>
#include <stdlib.h>

void operacao(int *a,int *b) {
    int *aux = *a + *b;
    *b -= *a - *b;
    *a = aux;
}

int main() {

    int x = 200, y = 47;

    operacao(&x, &y);

    printf("\nSoma: %i\nSubtracao: %i\n", x, y);

    return 0;
}
