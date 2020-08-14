#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[] = "";
    printf("\n\nDigite um nome: ");
    gets(nome);

    printf("\n\nOla, %s\n\n", nome);

    //Segunda maneira de ler uma String em c
    char nome2[] = "";

    printf("\n\nDigite um nome: ");
    scanf("%s", &nome2);

    printf("\n\nOla, %s\n", nome2);

    printf("\n\nOs nomes recebidos sao %s e %s\n\n.", nome, nome2);

    return 0;
}
