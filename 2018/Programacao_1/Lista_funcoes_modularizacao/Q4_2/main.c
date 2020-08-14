
/* 
 * File:   main.c
 * Author: Thiago Sousa
 *
 * Created on 4 de Outubro de 2018, 10:54
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void tabuada(int n) {
int i = 0;

puts("\n");

  for(i = 0; i <= n; i++) {
    printf("%d x %d = %d\n", i, n, (i*n));
  }

}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    tabuada(numero);


    return 0;
}

