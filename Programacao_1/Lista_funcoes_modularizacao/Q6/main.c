
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
    
    int aux = 0, contador = 0;
    
    while(aux <= numero) {
        
        if(numero % aux != 0) {
            
            contador++;
        }
    
        aux++;
        
        if(contador > 0) {
            
            return 1;
        
        }
    }

    return 0;
}

int main() {
    int numero;
    
    puts("Digite um numero: ");
    numero = lerNumero(numero);
    
    printf("\n\nO número digitado foi %i.\n\n", numero);
    
    

    return 0;
}

