#include <stdio.h>

//Retorna o fatorial de um número
int fact(int num) {
int factResult = 0;

for(factResult = 1; num > 1; num = num - 1) {

        factResult *= num;
}

return factResult;

}

void main() {

    int num = 0;
    char option = '0';

//Execução do programa
    do{

    printf("\nDeseja contunuar? [s, n]: ");
    scanf("%c", &option);

    switch(option) {

    case 's':
        printf("Digite um número: ");
        scanf("%i", &num);

        printf("\n\nResultado: %i\n\n", fact(num));
        break;

    case 'n':

    printf("\n\nFinalizando...\n\n");

        break;

    default:

        printf("Opção inválida");
    }
}
while(option != 'n');

}
