#include <stdio.h>
#include <stdlib.h>

char *getCategory(int idade) {

    char category[5][10] = {"infantil A", "infaltil B", "juvenil A", "juvenil B", "Adulto"};
    char *categoriaAdequada;

    if(idade >= 5 || idade <= 7) {
        categoriaAdequada = &category[0];
        return categoriaAdequada;

    } else if(idade >= 8 || idade <= 10) {
        categoriaAdequada = &category[1];
        return categoriaAdequada;

    } else if(idade >= 11 || idade <= 13) {
        categoriaAdequada = &category[2];
        return categoriaAdequada;

    } else if(idade >= 14 || idade <= 17) {
       categoriaAdequada = &category[3];
        return categoriaAdequada;

    } else if(idade >= 18) {
        categoriaAdequada = &category[4];
        return categoriaAdequada;

    }

    return "";
}

int main() {
    int age;
    char* category;

    printf("\nDigite a idade: ");
    scanf("%i", &age);

    category = getCategory(age);

    printf("\n\nCategoria adequada: %s\n\n", category);

    return 0;
}
