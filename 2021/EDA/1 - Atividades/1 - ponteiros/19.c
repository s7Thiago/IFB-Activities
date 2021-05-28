/*
Escreva uma funcao que aceita como parametro um array de inteiros com N valores, e
determina o maior elemento do array e o numero de vezes que este elemento ocorreu
no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
8, 6, 15, a funcao deve retorna para o programa que a chamou o valor 15 e o numero 3
(indicando que o numero 15 ocorreu 3 vezes). A funcao deve ser do tipo void.
*/

#include <stdio.h>

void qtdeNumero(int *array, int num)
{

    int x = array[0];
    int numMaior = 0;
    int qtde = 0;

    for (int i = 0; i < num; i++)
    {

        if (array[i] >= array[numMaior])
        {
            numMaior = i;
            x = array[numMaior];
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (x == array[i])
        {
            qtde++;
        }
    }

    printf("Numero maior %d ocorreu %d vezes.\n", x, qtde);
}

int main()
{
    int *array;
    int num;

    scanf("%d", &num);

    array = (int *)malloc(num * sizeof(int));

    for (int d = 0; d < num; d++)
    {
        scanf("%d", &array[d]);
    }

    qtdeNumero(array, num);

    return 0;
}
