#include <stdio.h>
#include <stdlib.h>

int calcIdade(int ano, int meses, int dias)
{
    int numeromeses,numerodias , mesdia, totaldias;
    // anos para dia
    numeromeses = ano * 12;
    numerodias  = numeromeses * 30;
    //meses para dia
    mesdia = meses * 30;
    // toral de dias
    totaldias = numerodias + mesdia + dias ;

    return totaldias;
}

int main()
{
    int ano,meses,dia,resposta;
    printf("Digite sua idade: ");
    scanf("%d",&ano);

    printf("Digite seu meses: ");
    scanf("%d",&meses);

    printf("Digite sua dia: ");
    scanf("%d",&dia);

    resposta= calcIdade(ano, meses, dia);
    printf("A sua idade expressa em dia e: %d",resposta);
    return 0;
}
