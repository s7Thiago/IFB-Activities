#include <stdio.h>
#include <stdlib.h>
    float result( int N){
        float S;
        S =( 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/N );
        return S ;
    }
int main(){
    int numero;
    if(numero > 0){
    printf("Digite o valor : ");
    scanf("%d",&numero);

    numero = result(numero);

    printf("O resultado : %f", numero);
    }else
        printf("Opcao invalida");
    return 0;
}
