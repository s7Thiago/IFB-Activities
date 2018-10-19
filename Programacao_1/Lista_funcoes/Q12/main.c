#include <stdio.h>
#include <stdlib.h>

char* notaClassification(float nota) {

    char* classificacao = {'D', 'C', 'B', 'A'};

    if (nota >= 0.0 || nota <= 4.9) {

        return classificacao[0];

    } else if (nota >= 5.0 || nota <= 6.9) {

       return classificacao[1];

    } else if (nota >= 7.0 || nota <= 8.9) {

        return classificacao[2];

    } else if (nota >= 9.0 || nota <= 10.0) {

        return classificacao[3];

    }
}

int main() {

    float nota;
    char* classificacao;

    printf("Digite a nota: ");
    scanf("%f", &nota);

    classificacao = notaClassification(nota);

    printf("\n\nA classificacao desta nota e '%c'\n\n", classificacao);
    return 0;
}
