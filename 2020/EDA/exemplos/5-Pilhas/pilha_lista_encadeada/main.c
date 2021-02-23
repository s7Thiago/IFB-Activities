#include "pilha.h"

// Definição de uma pessoa
typedef struct pessoa
{
    char nome[30];
    char cpf[20];
    int idade;
} pessoa;

// Contrói um objeto pessoa
void *constructor_pessoa(void *data)
{
    // Aloca espaço em memória para uma pessoa de maneira dinâmica
    void *ptr = mallocx(sizeof(pessoa));

    // Copia os dados de data do parâmetro para a região de memória apontada por ptr
    memcpy(ptr, data, sizeof(pessoa));

    return ptr;
}

// Destrói uma pessoa
void destructor_pessoa(void *data)
{
    free(data);
}

// lê o buffer do teclado até que chegue em \n ou no tamanho total da string
// basicamente é uma modificação da função fgets
void my_getline(char *str, size_t size)
{
    int i;
    char c;
    for (i = 0; i < size; i++)
    {
        c = getchar();
        if (c == '\n')
        {
            str[i] = '\0';
            break;
        }
        str[i] = c;
    }

    str[size - 1] = '\0';

    while (c != '\n')
    {
        c = getchar();
    }
}

void cadastra_pessoa(pessoa *p)
{
    printf("Nome: ");
    my_getline(p->nome, 30);

    printf("CPF: ");
    my_getline(p->cpf, 20);

    printf("Idade: ");
    // lê um inteiro e descarta o próximo caractere do buffer do teclado
    scanf("%d%*c", &p->idade);
}

void imprime_pessoa(const pessoa *p)
{
    printf("Nome: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("Idade: %d\n", p->idade);
}

int main(void)
{

    int i;
    stack_t *s;
    pessoa p;

    stack_initialize(&s, constructor_pessoa, destructor_pessoa);

    for (i = 0; i < 5; i++)
    {
        printf("Cadastrando pessoa %d\n", i + 1);
        cadastra_pessoa(&p);
        stack_push(s, &p);
    }

    while (!stack_empty(s))
    {
        printf("\n**Imprimindo pessoa**\n");
        p = *(pessoa *)stack_top(s);

        stack_pop(s);
        imprime_pessoa(&p);
        printf("\n");
    }

    stack_delete(&s);

    return 0;
}
