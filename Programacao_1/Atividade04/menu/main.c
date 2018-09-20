#include <stdio.h>

char mostrarMenu(char *opcoes[], int qtde) {

    for(int i = 0; i < qtde; i++) {
        printf("%d - %s\n", (i + 1), opcoes[i]);
    }
}

int main() {

    char *opcoes[] = {"Opção 1", "Opção 2", "Opção 3"};
    char op;

    int s = (sizeof(opcoes)/sizeof((opcoes)[0]));

    char menu = mostrarMenu(opcoes, s);


    do {

        printf("\nDigite a opção: ");
        scanf("%d",&op);
        switch(op) {
        case 1:
            printf("\nOpção 1 escolhida");
            break;

        case 2:
            printf("\nOpção 2 escolhida");
            break;

        case 3:
            printf("\nOpção 3 escolhida");
            break;
        }
    } while(op != 0);

    return 0;
}
