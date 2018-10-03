/* 
 * File:   main.c
 * Author: Thiago Sousa
 * 
 * Created on 3 de Outubro de 2018, 10:23
 * 
 * 5. Escreva uma função que, tendo um número natural na base binária como 
 * parâmetro, transforma e retorna tal número na base decimal. Exemplo: Dado 
 * 10010 a saída será 18, 
 * pois 1x(2^4) + 0x(2^3) + 0x(2^2) + 1x(2^1) + 0x(2^0) = 18.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */

int binaryToDecimal(int value) {
    int retorno = 0, alg, exp = 0, base = 2;

    while (value > 0) {

        alg = value % 10; //Pegando os algarismos do numero recebido

        retorno += (alg * pow(base, exp)); //Transformando em decimal

        value = value / 10; //Reduzindo o numero para pegar o proximo algarismo
        exp++; //Expoente
    }

    return retorno;
}

int main() {

    int num, numDecimal;

    puts("Digite um numero binário: ");
    scanf("%d", &num);

    numDecimal = binaryToDecimal(num);

    printf("\n\nO numero %d em decimal eh %d\n\n", num, numDecimal);

    return 0;
}

