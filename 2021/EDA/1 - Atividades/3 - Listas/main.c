#include "lista_encadeada.h"

// Struct celula que será o objeto (não genérico) base para inserir na lista
typedef struct pessoa
{
    int info;
} celula;

// Função construtora: indicamos para essa função como construir um objeto celula
void *constructor_celula(void *data)
{
    void *ptr = mallocx(sizeof(celula));
    memcpy(ptr, data, sizeof(celula)); // Copia os dados da área de memória `data` para a nova área `ptr`

    return ptr; // Retornando a nova celula que está na área recém alocada
}

// Função desstrutora: Define a forma correta de destruir uma pessoa na lista. Nesse caso, apenas desalocamos a memória ocupada
void destructor_celula(void *data)
{
    free(data);
}

// Imprime os dados em uma variável do tipo celula com dados inteiros
void printcl(celula *c)
{

    int data = c->info;

    printf("{info:");
    printf("%d}", data);
}

// Imprime uma lista do tipo pessoa
void print_list_celulas(list_t *l)
{
    // printf("\n");
    list_iterator_t it;
    for (it = l->head; it != NULL; it = it->next)
    {
        printcl(it->data);
        printf("-> ");
    }
    printf("{NULL}\n\n");
}

void le_celula(celula *c)
{
    printf("info = ");
    scanf("%d", &c->info);
}

int main(void)
{
    // Lista
    list_t *l1 = NULL; // Será a lista baseada na struct genérica
    int option = 0;

    do
    {
        // Mostrando menu
        printf("1 - Create the generic list");
        printf("\n2 - Insert on list tail");
        printf("\n3 - Print list");
        printf("\n4 - List is empty");
        printf("\n5 - Search element on index");
        printf("\n6 - Delete element on index");
        printf("\n7 - Delete list");
        printf("\n8 - Ordered insertion\n");

        printf("\nchoose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: // Cria a lista
            // Inicializando / alocando / criando as listas
            list_initialize(&l1, constructor_celula, destructor_celula);
            break;

        case 2:; // Insere um elemento no fim da lista

            if (l1 != NULL)
            {

                celula cel;
                le_celula(&cel);
                list_append(l1, &cel);
            }
            else
            {
                printf("\nThe list not exists! \nType 1 to create and allocate memory.\n\n");
            }
            break;

        case 3: // Imprime a lista de maneira didática

            if (l1 != NULL)
                print_list_celulas(l1);
            else
                printf("\nThe list not exists!. Type 1 for create it\n\n");
            break;

        case 4: // Verifica se a lista está vazia
            if (l1 != NULL)
            {
                if (list_empty(l1) == 1)
                {
                    printf("\nA lista está vazia!\n\n");
                }
                else
                {
                    printf("\nA lista não está vazia\n\n");
                }
            }
            else
            {
                printf("The list not exists!\n\n");
            }

            break;

        case 5:; // Mostra o elemento de uma posição da lista

            if (l1 != NULL)
            {
                int max_size = list_size(l1);
                int targetPosition;

                printf("choose a index in the break [0 - %d]: ", max_size - 1);
                scanf("%d", &targetPosition);

                printf("Selected %d: ", *((int *)list_access(l1, targetPosition)));

                printf("\n\n");
            }
            else
            {
                printf("The list not exists! \nType 1 to create and allocate memory.");
            }

            break;

        case 6:; // Exclui um elemento de uma posição da lista

            if (l1 != NULL)
            {
                int max_exclude_size = list_size(l1);
                int targetExcludePosition;

                printf("choose a index in the break [0 - %d]: ", max_exclude_size - 1);
                scanf("%d", &targetExcludePosition);

                int element = *((int *)list_access(l1, targetExcludePosition));

                list_remove(l1, targetExcludePosition);

                printf("Excluded %d: ", element);

                printf("\n\n");
            }
            else
            {
                printf("The list not exists! \nType 1 to create and allocate memory.");
            }

            break;

        case 7: // Remove a lista da memória
            if (l1 != NULL)
                list_delete(&l1);
            else
                printf("\nNot exists a list to exclude\n\n");
            break;

        default:
            printf("\n\nINVALID OPTION!\n");
            break;
        }
    } while (option != 0);

    // Desaloca a lista, caso o programa finalize
    list_delete(&l1);

    return 0;
}
