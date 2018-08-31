#include <stdio.h>
#include <stdlib.h>
#define MARGEM_ERRO 0.0625


float altura(float hMae, float hPai, char gen) {
    float resultado = 0;

    switch(gen) {

    //case 'F':
    case 'f':
        resultado = ((hMae + hPai) - 0.125);

        break;

    //case 'M':
    case 'm':

        resultado = ((hMae + hPai) + 0.125);

        break;

    }
    return (resultado/2);

}

void main() {

    float hMae = 0, hPai = 0, resultado = 0;
    char gen;

    printf("Digite o sexo: ");
    scanf("%c", &gen);

    printf("Digite a altura da mãe: ");
    scanf("%f", &hMae);

    printf("Digite a altura do pai: ");
    scanf("%f", &hPai);

    resultado = altura(hMae, hPai, gen);

    printf("\n\nResultado: %.2f;\ncom uma margem de %.4f;\n\npode ser %.2f ou %.2f\n\n", resultado, MARGEM_ERRO, (resultado - MARGEM_ERRO), (resultado + MARGEM_ERRO));

}


