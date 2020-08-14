#include <stdio.h>
#include <stdlib.h>

//criando funcao
int pesoideal(float altura, char sexo){
    // calculo do peso
    float manWeight, girlWeight;
    if(sexo == 'm'){
    manWeight =  72.1 * altura - 58;
    return manWeight;
} else {
    girlWeight = 62.1 * altura - 44.7;
    return girlWeight;
}
}
int main()
{   float altura;
    char sexo;
        printf("Digite 'm' para masculino ou 'f' para feminino: ");
        scanf("%c", &sexo);

        printf("\nDigite a altura: ");
        scanf("%f", &altura);
        altura = pesoideal(altura , sexo);

        printf("O peso ideal sera : %.3f", altura);

    return 0;
}
