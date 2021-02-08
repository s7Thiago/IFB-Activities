#include "lista.h"

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