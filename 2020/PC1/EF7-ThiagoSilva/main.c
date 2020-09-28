#include <stdio.h>
#include <string.h>

#define FILENAME "log.bin"

// struct
typedef struct pessoa
{
    char nomeCompleto[50];
    char idade[5];
    char cpf[20];
} pessoa;

int main(void)
{
    pessoa p;
    strcpy(p.nomeCompleto, "\tThiago Silva\t");
    strcpy(p.cpf, "\t564.875.544-82\t");
    strcpy(p.idade, "\t23\t");

    FILE *f;
    f = fopen(FILENAME, "a+b");

    // verificando se o arquivo foi aberto
    if (f == NULL)
    {
        fprintf(stderr, "\n\nErro! não foi possível abrir o arquivo\n\n");
        return 1;
    }
    else
    {
        // gravando o nome no arquivo
        for (int i = 0; i < strlen(p.nomeCompleto); i++)
        {
            fputc(p.nomeCompleto[i], f);
            fflush(f);
        }

        // gravando o cpf no arquivo
        for (int i = 0; i < strlen(p.cpf); i++)
        {
            fputc(p.cpf[i], f);
            fflush(f);
        }

        // gravando a idade no arquivo
        for (int i = 0; i < strlen(p.idade); i++)
        {
            fputc(p.idade[i], f);
            fflush(f);
        }

        // salvando os dados do arquivo em disco sem fechar o mesmo
        fflush(f);
    }

    // fechando o arquivo
    fclose(f);

    /* code */
    return 0;
}
