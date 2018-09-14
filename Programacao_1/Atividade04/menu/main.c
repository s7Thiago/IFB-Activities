#include <stdio.h>
 int main() {
    char *opcoes[] = {"Opção 1", "Opção 2", "Opção 3"};

    for(int i = 0; i < (sizeof(opcoes)/sizeof((opcoes)[0])); i++) {

    printf("%d - %s\n", (i + 1), opcoes[i]);

    }

    return 0;
 }
