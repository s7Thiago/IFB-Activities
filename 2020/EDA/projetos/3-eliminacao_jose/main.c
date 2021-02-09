#include "projeto3.h"

int main(void)
{
    list_t *l1;                       // Lista
    size_t nPessoas, indiceEscolhido; // Alvos da entrada de dados principal

    // Inicializando a lista
    list_initialize(&l1, constructor_pessoa, destructor_pessoa);

    // Executando as consecutivas eliminações
    eliminar(l1, nPessoas, indiceEscolhido);

    // Exibindo o resultado
    print_list_pessoa(l1);

    list_delete(&l1);

    return 0;
}
