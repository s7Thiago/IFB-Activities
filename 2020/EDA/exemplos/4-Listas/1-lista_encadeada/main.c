#include "lista.h"

// Struct pessoa que será o objeto base para por na lista
typedef struct pessoa
{
    char nome[30];
    char cpf[30];
    int idade;
} pessoa;

// Função construtora: indicamos para essa função como construir um objeto pessoa
void *constructor_pessoa(void *data)
{
    void *ptr = mallocx(sizeof(pessoa));
    memcpy(ptr, data, sizeof(pessoa)); // Copia os dados da área de memória `data` para a nova área `ptr`

    return ptr; // Retornando a nova pessoa que está na área recém alocada
}

// Função desstrutora: Define a forma correta de destruir uma pessoa na lista. Nesse caso, apenas desalocamos a memória ocupada
void destructor_pessoa(void *data)
{
    free(data);
}

// Função construtora: indicamos para essa função como construir um inteiro
void *constructor_int(void *data)
{
    void *ptr = mallocx(sizeof(int));
    memcpy(ptr, data, sizeof(int)); // Copia os dados da área de memória `data` para a nova área `ptr`

    return ptr; // Retornando a nova pessoa que está na área recém alocada
}

// Função desstrutora: Define a forma correta de destruir um inteiro na lista. Nesse caso, apenas desalocamos a memória ocupada
void destructor_int(void *data)
{
    free(data);
}

// Imprime os dados em uma variável do tipo pessoa
void imprime_pessoa(pessoa *p)
{
    printf("Nome = ");
    printf("%s\n", p->nome);
    printf("CPF = ");
    printf("%s\n", p->cpf);
    printf("Idade = ");
    printf("%d\n", p->idade);
}

// Imprime uma lista do tipo pessoa
void print_list_pessoa(list_t *l)
{
    printf("\n");
    list_iterator_t it;
    for (it = l->head; it != NULL; it = it->next)
    {
        imprime_pessoa(it->data);
    }
    printf("NULL\n");
    printf("\n");
}

void le_pessoa(pessoa *p)
{
    printf("Nome = ");
    scanf("%s", p->nome);
    printf("CPF = ");
    scanf("%s", p->cpf);
    printf("Idade = ");
    scanf("%d", &(p->idade));
}

int main(void)
{
    /* code */
    printf("Está tudo ok\n\n");
    list_t *l1;
    list_t *l2;
    list_t *l3;

    list_initialize(&l1, constructor_pessoa, destructor_pessoa);
    list_initialize(&l2, constructor_pessoa, destructor_pessoa);
    list_initialize(&l3, constructor_int, destructor_int);

    int i;
    for (i = 0; i < 3; i++)
    {
        pessoa p;
        le_pessoa(&p);
        list_append(l1, &p);
        list_prepend(l2, &p);
        list_append(l3, &i);
    }

    print_list_pessoa(l1);
    print_list_pessoa(l2);
    print_list_int(l3);

    list_delete(&l1);
    list_delete(&l2);
    list_delete(&l3);

    return 0;
}
