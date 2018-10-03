/* 
 * File:   main.c
 * Author: Thiago Sousa
 *
 * Created on 3 de Outubro de 2018, 10:23
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int a = 1000101, alg;

    while (a > 0) {
        
        alg = a % 10;
        
        printf("%d - ", alg);
        a = a / 10;
        
        printf("\nValor de a: %d\n", a);
    }


    return 0;
}

