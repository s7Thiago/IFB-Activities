/*
Implemente uma funcao que receba como parametro um array de numeros reais de tamanho N e retorne quantos numeros negativos ha nesse array. Essa funcao deve
obedecer ao prototipo:

int negativos(float *vet, int N);
*/

#include <stdio.h>

void qtdeNumero(int *vet, int N)
{

    int qtde = 0;

    for (int i = 0; i < N; i++)
    {
        if (vet[i] < 0)
        {
            qtde++;
        }
    }

    printf("Numeros negativos ocorreu %d vezes.\n", qtde);
    
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
