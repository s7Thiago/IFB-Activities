#include "lista_encadeada.h"

void list_initialize(list_t **l, list_node_constructor_fn constructor, list_node_destructor_fn destructor)
{
    // Aloca espaço para a estrutura lista
    (*l) = mallocx(sizeof(list_t));
    // Cabeca aponta para NULL
    (*l)->head = NULL;
    // Cauda aponta para NULL
    (*l)->tail = NULL;
    // Tamanho de uma lista recém inicializada é igual a 0
    (*l)->size = 0;
    // Atribuição da funcao construtora
    (*l)->constructor = constructor;
    // Atribuição da funcao destrutora
    (*l)->destructor = destructor;
}

// Retorna o tamanho da lista
size_t list_size(list_t *l)
{
    return l->size;
}

// Verificando se a lista está vazia
size_t list_empty(list_t *l)
{
    return list_size(l) == 0 ? 1 : 0;
}

static list_node_t *list_new_node(void *data, list_node_constructor_fn constructor)
{
    // Aloca espaço para o novo nó
    list_node_t *new_node = mallocx(sizeof(list_node_t));

    // Constrói o novo dado através da funcao contrutora
    new_node->data = constructor(data);

    // Atribui o ponteiro para o próximo como NULL
    new_node->next = NULL;

    // Retorna o nó alocado
    return new_node;
}

// Deleta o nó de uma lista
static void list_delete_node(list_node_t *n, list_node_destructor_fn destructor)
{
    // Chama a funcao destrutora para o dado nó
    destructor(n->data);

    // Libera o nó
    free(n);
}

// Insere um novo elemento na cabeca da lista
void list_prepend(list_t *l, void *data)
{

    // Cria um novo nó ao invocar list_new_node_t
    list_node_t *new_node = list_new_node(data, l->constructor);

    // Estabelecendo uma ligacao do novo nó para a cabeca antiga
    new_node->next = l->head;

    // Cabeca antiga agora aponta para o nó recém criado
    l->head = new_node;

    /**
     * Se a lista estava vazia, a cauda também deve apontar para o nó recém criado
     * **/
    if (list_empty(l))
    {
        l->tail = new_node;
    }

    // O tamanho da lista é incrimentado
    l->size++;
}

//  Insere um elemento no fim da lista
void list_append(list_t *l, void *data)
{
    // Cria um novo né ao chamar list_new_node
    list_node_t *new_node = list_new_node(data, l->constructor);

    // Se a lista está vazia, a cabeça deve apontar para o nó recém criado
    if (list_empty(l))
    {
        l->head = new_node;
    }

    /**
     * Caso contrário, a lista possui uma cauda e ela deve estabelecer uma
     * ligação com o elemento recém criado
     * **/
    else
    {
        l->tail->next = new_node;
    }

    // Atializando a cauda para apontar para o elemento recém criado
    l->tail = new_node;

    // Incrementando o tamanho da lista
    l->size++;
}

// insere um elemento numa posição específica da lista
void list_insert(list_t *l, void *data, size_t i)
{

    // Apenas modo debug: Aborta o programa se a posição for inválida
    assert(i <= list_size(l));

    /**
     * Se a lista está vazia, ou a posição de inserção é a 0, a inserção
     * é feita na cabeça
     * **/
    if (list_empty(l) || i == 0)
    {
        list_prepend(l, data);
    }

    // Inserção na cauda
    else if (i == list_size(l))
    {
        list_append(l, data);
    }

    /**
     * Se a inserção não cair em nehum dos ifs antriores, significa que 
     * ela não deverá ocorrer na cabeça nem na cauda, além disso, sabemos
     * também que a lista não está vazia, ou seja, a inserção ocorrerá no meio da lista. 
     * **/

    // Inserção no meio da lista que tem pelo menos 1 elemento
    else
    {
        // Cria um novo nó ao chamar a função list_new_node
        list_node_t *new_node = list_new_node(data, l->constructor);

        /**
         *  Precisamos encontrar o elemento que antecede a posição i ao
         * caminhar na lista
         * **/
        list_iterator_t it = l->head;
        size_t k;

        // Caminhamos até a posiçào i - 1da lista
        for (k = 0; k < i - 1; k++)
        {
            it = it->next;
        }

        /**
         * * it agora aponta para o elemento da posição i-1
         * Estabelecemos o next do novo nó para o elemento antigo
         * da posição i
         * **/
        new_node->next = it->next;

        // O next do nó da posição i-1 recebe o elemento recém inserido
        it->next = new_node;

        // Por fim, o tamanho da lista deve se incrementado
        l->size++;
    }
}

// Removendo um elemento da na cabeça da lista
void list_remove_head(list_t *l)
{
    /**
     * * Apenas debug: 
     * Aborta o programa caso a remoção da cabeça seja sobre uma lista vazia
     * **/
    assert(!list_empty(l));

    // O nó que será removido recebe a cabeça
    list_iterator_t node = l->head; // Nó auxiliar que aponta para a cabeça da lista

    // Se a lista tem um elemento, após a remoção, a cauda deve ser NULL
    if (list_size(l) == 1)
    {
        l->tail = NULL;
    }

    // A cabeça passa para o próximo elemento
    l->head = l->head->next;

    // Agora deletamos a cabeça
    list_delete_node(node, l->destructor);

    // Atualizando o tamanho da lista
    l->size--;
}

// Removendo um elemento da na cauda da lista
void list_remove_tail(list_t *l)
{
    /**
     * * Apenas debug:
     * aborta o programa caso a função seja chamada para uma lista vazia
     * **/
    assert(list_size(l) > 0);

    // O nó que será removido recebe a cauda
    list_iterator_t node = l->tail;

    /** Se a lista tem tamanho 1, a cauda e a acabeça apontam para NULL 
     * após a remoção
     * **/
    if (list_size(l) == 1)
    {
        l->head = NULL;
        l->tail = NULL;
    }

    /**
     * Caso contrário, a lista tem mais de um elemento. Deve-se iterar 
     * sobre a lista até penúltimo elemento
     * **/
    else
    {
        // Iterando sobre a lista a partir da cabeça até o penúltimo elemento
        list_iterator_t it = l->head;
        while (it->next != l->tail)
        {
            it = it->next;
        }

        // O campo next do penúltimo elemento agora aponta para NULL
        it->next = NULL;

        // O penúltimo passa a ser a cauda
        l->tail = it;
    }

    // Removendo a antiga cauda
    list_delete_node(node, l->destructor);

    // O tamanho da lista é decrementado
    l->size--;
}

// Removendo um elemento na posição i da lista
void list_remove(list_t *l, size_t i)
{
    /**
     * * Debug apenas:
     * Aborta o programa se a remoção estiver sendo feita em uma
     * lista vazia ou em uma posição inexistente da lista
     * **/
    assert(!list_empty(l) && i < list_size(l));

    /**
     * Se a lista tem tamanho 1 , ou a remoção é do primeiro elemento,
     * equivale a eliminar a cabeça
     * **/
    if (list_size(l) == 1 || i == 0)
    {
        list_remove_head(l);
    }

    // Se i == list_size(l)-1, a remoção é na cauda
    else if (i == list_size(l) - 1)
    {
        list_remove_tail(l);
    }

    /**
     * O nó a ser removido encontra-se no meio da lista e a
     *  lista possui mais que um elemento
     * **/
    else
    {
        // Nó a ser removido
        list_node_t *node;

        // Devemos percorrer até o i-1-ésimo elemento a partir da cabeça
        list_iterator_t it = l->head;
        size_t k;

        // Iterando até o elemento imediatamente interior ao elemento i
        for (k = 0; k < i; k++)
        {
            it = it->next;
        }

        // Nó a ser removido passa a ser o i-ésimo elemento
        node = it->next;

        /**
         * O anterior ao nó a ser removido aponta para o elemento que vem
         * após o nó a ser removido
         * **/
        it->next = node->next;

        // Agora deletamos o nó atribuído anteriormente
        list_delete_node(node, l->destructor);

        // Atualizando o tamanho da lista (Decremento)
        l->size--;
    }
}

// Acessando um dado que está na cabeça da lista
void *list_access_head(list_t *l)
{
    /**
     * * Apenas debug:
     * Aborta o programa se a lista não tem cabeça (é vazia)
     * **/
    assert(!(list_empty(l)));

    // Retornando o dado na cabeça da dada lista
    return (l->head->data);
}

// Acessando um dado que está na cauda da lista
void *list_access_tail(list_t *l)
{
    /**
     * * Apenas debug:
     * Aborta o programa se a lista não tem cabeça (é vazia)
     * **/
    assert(!(list_empty(l)));

    // Retornando o dado na cabeça da dada lista
    return (l->tail->data);
}

// Acessando um  elemento na posição i da lista
void *list_access(list_t *l, size_t i)
{
    /**
     * * Apenas debug:
     * Aborta o programa se a posição que será acessada for
     * inválida
     * **/
    assert(!list_empty(l) && i < list_size(l));

    // Se i==0, o acesso é na cabeça
    if (i == 0)
    {
        return list_access_head(l);
    }

    // Se i== list_size(l) - 1, o acesso é na cauda
    else if (i == list_size(l) - 1)
    {
        return (list_access_tail(l));
    }

    // Caso contrário, percorremos a lista até o i-ésimo elemento
    size_t j;
    list_iterator_t it = l->head;
    for (j = 0; j < i; j++)
    {
        it = it->next;
    }

    // O campo dado do elemento é retornado
    return (it->data);
}

// Realiza a limpeza de uma lista removendo a cabeça
void list_delete(list_t **l)
{
    // Enquanto a lista não for vazia, remove a cabeça
    while (!list_empty(*l))
    {
        list_remove_head(*l);
    }

    // Desaloca o espaço para a estrutura de dados
    free(*l);

    // Atribui NULL ao ponteiro para a nossa lista
    *l = NULL;
}

/**
 * * Tempo de vídeo
 * 50:50
 * **/