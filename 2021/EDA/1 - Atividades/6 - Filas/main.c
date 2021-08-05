#include "fila_lista.h"

// Estrutura pessoa que será inserida na fila
typedef struct Pessoa
{
	char nome[30];
	char cpf[20];
	int idade;
} Pessoa;

// Função construtora para o tipo Pessoa
void *construtor_pessoa(void *data)
{
	void *ptr = mallocx(sizeof(Pessoa));
	memcpy(ptr, data, sizeof(Pessoa));
	return ptr;
}

// Responsável por realizar a leitura lê o que está no buffer
// do teclado até achar um caractere de nova linha
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

// Preenche um objeto pessoa
void cadastra_pessoa(Pessoa *p)
{
	printf("Nome: ");
	my_getline(p->nome, 30);

	printf("CPF: ");
	my_getline(p->cpf, 20);

	printf("Idade: ");
	scanf("%d%*c", &p->idade);
}

// Exibe os dados armazenados em um objeto pessoa
void imprime_pessoa(const Pessoa *p)
{
	printf("Nome: ");
	printf("%s\n", p->nome);

	printf("CPF: ");
	printf("%s\n", p->cpf);

	printf("Idade: ");
	printf("%d\n", p->idade);
}

// Imprime de maneira didática os elementos de uma fila
void showqueue(queue_t *queue)
{
	queue_iterator_t it;

	printf("[ ");
	for (it = queue->front; it != NULL; it = it->next)
	{
		printf("%d, ", *(int *)it->data);
	}
	printf("{ NULL } ]");
}

// Função de destrutor para o tipo Pessoa
void destructor_pessoa(void *data)
{
	free(data);
}

// Aplicação principal
int main(void)
{

	int i;
	queue_t *q;
	Pessoa p;

	// Inicializando a fila
	queue_initialize(&q, construtor_pessoa, destructor_pessoa);

	for (i = 0; i < 5; i++)
	{
		printf("Cadastrando pessoa %d\n", i + 1);
		cadastra_pessoa(&p);
		queue_push(q, &p);
	}

	while (!queue_empty(q))
	{
		printf("\n**Imprimindo pessoa**\n");
		p = *(Pessoa *)queue_front(q);
		queue_pop(q);
		imprime_pessoa(&p);
		printf("\n");
	}

	queue_delete(&q);

	return 0;
}
