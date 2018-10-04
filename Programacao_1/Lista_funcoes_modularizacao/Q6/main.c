
/* 
 * Escreva um algoritmo que leia um valor inteiro e imprima se este é primo. 
 * Utilize as seguintes funções protótipo:
 * ● int lerNumero(); // lê um número inteiro via teclado.
 * ● int primo(int valor); // devolve 1 se o valor for primo, 0 caso contrário.
 * ● void imprime(int valor, int p); // imprime valor “é primo” caso p seja 1,
caso seja 0 imprime valor “não é primo”
 * 
 * File:   main.c
 * Author: Thiago Sousa
 *
 * Created on 3 de Outubro de 2018, 13:03
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int  lerNumero(int numero) {
    scanf("%i", &numero);
    
    return numero;
}

int primo(int numero) {
    
    int aux = 1, contador = 0;
    
    while(aux < numero) {
        
        if((numero % aux) == 0) {
            
            contador++;
        }
    
        aux++;
    }
    
     if(contador > 2) {
            
            return 0;
        
        }

    return 1;
}

void imprime(int valor, int p) {
    
    if(primo(valor) == 0) {
        
        printf("\n\nNao eh primo\n\n");
    
    } else {
        
    printf("\n\nEh primo\n\n");
    
    }

}

int main() {
    int numero;
    
    puts("Digite um numero: ");
    imprime(lerNumero(numero), primo(numero));
    
    return 0;
}

