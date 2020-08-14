#include <stdio.h>
#include <stdlib.h>

//O valor recebido no parametro deve ser inteiro e positivo
int somatorio(int valor) {

    //Fazendo o somatorio
    int somatorio = 0, i;

    for(i = 0; i < valor; i++) {

        somatorio += ((somatorio + i));
    }
return somatorio - 1;
//somatorio feito e retornado!
}

int main() {

    int valor, somatorioValor = 0;

    printf("Digite um valor inteiro e positivo: ");
    scanf("%i", &valor);

    somatorioValor = somatorio(valor);

    //imprimindo o resultado
    printf("\n\nResultado: %i\n\n", somatorioValor);

    //tudo certo...esperamos

    return 0;
}
