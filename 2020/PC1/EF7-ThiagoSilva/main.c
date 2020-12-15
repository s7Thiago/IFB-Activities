#include <stdio.h>
#include <string.h>

#define FILENAME "log.bin"

// struct
typedef struct pessoa
{
    char nomeCompleto[50];
    int idade;
    char cpf[20];
} pessoa;

int main(void)
{

    FILE *f;
    pessoa p;
    strcpy(p.nomeCompleto, "Thiago Silva");
    strcpy(p.cpf, "564.875.544-82");
    p.idade = 23;

    
    f = fopen(FILENAME, "a+b");

    // verificando se o arquivo foi aberto
    if (f == NULL)
    {
        fprintf(stderr, "\n\nErro! não foi possível abrir o arquivo\n\n");
        return 1;
    }

      // gravando os dados no arquivo
      fwrite (&p, sizeof(pessoa), 3, f);

    // fechando o arquivo
    fclose(f);
    return 0;
}
