#include "projeto3.h"

// Imprime uma lista de inteiros
void print_list_int(list_t *l)
{
    printf("\n");
    list_iterator_t it;
    for (it = l->head; it != NULL; it = it->next)
    {
        printf("%d -> ", *(int *)it->data);
    }
    printf("NULL\n");
    printf("\n");
}

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

// Imprime os dados em uma variável do tipo pessoa
void imprime_pessoa(pessoa *p)
{
    // printf("[%d] Nome = %s\n", p->indice, p->nome);
    printf("%s\n", p->nome);
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
    //printf("NULL\n");
    printf("\n");
}

// Recebe a entrada de dados para uma pessoa
void le_pessoa(pessoa *p)
{
    scanf("%s", p->nome);
}

void eliminar(list_t *lista, size_t nPessoas, size_t indiceEscolhido)
{
    scanf("%ld %ld", &nPessoas, &indiceEscolhido);

    // Lendo os nomes das i pessoas
    int i;
    for (i = 0; i < nPessoas; i++)
    {
        pessoa p;

        le_pessoa(&p);
        list_append(lista, &p);
    }

    while (list_size(lista) > 1)
    {

        if (indiceEscolhido >= nPessoas)
        {
            indiceEscolhido = nPessoas - 1;

            // Copiando os j primeiros elementos anteriores ao indice desejado para o fim da lista
            for (size_t j = 2; j < indiceEscolhido - 1; j++)
            {
                list_append(lista, list_access(lista, j));
            }

            // Removendo os j primeiros elementos
            for (size_t j = 0; j < indiceEscolhido - 1; j++)
            {
                indiceEscolhido--;
                list_remove_head(lista);
            }
        }

        else
        {
            list_remove(lista, indiceEscolhido - 1);     // Removendo o elemento no indice escolhido
            list_append(lista, list_access_head(lista)); // Copia a cabeça para a cauda da lista
            list_remove_head(lista);
        } // Remove a cabeça da lista
    }
}