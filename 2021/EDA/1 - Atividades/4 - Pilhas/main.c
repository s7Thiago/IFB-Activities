#include "pilha_lista.h"

// Definindo tipo pessoa para por na pilha
typedef struct pessoa {
	char nome[30];
	char cpf[20];
	int idade;
} pessoa;

// Contrutor para um tipo pessoa
void* constructor_pessoa(void* data) {
	void* ptr = mallocx(sizeof(pessoa));
	memcpy(ptr, data,sizeof(pessoa));
	return ptr;
}

// Funcao destrutora para um tipo pessoa
void destructor_pessoa(void* data) {
	free(data);
}

// Responsável por realizar a leitura
void my_getline(char* str, size_t size) {
	int i;
	char c;
	for(i=0;i<size;i++) {
		c = getchar();
		if(c=='\n') {
			str[i] = '\0';
			break;
		}
		str[i] = c;
	}
	str[size-1] = '\0';
	while(c!='\n') {
		c = getchar();
	}
}

// Preenche um objeto pessoa
void cadastra_pessoa(pessoa* p) {
	printf("Nome: ");
	my_getline(p->nome, 30);
	
	printf("CPF: ");
	my_getline(p->cpf, 20);
	
	printf("Idade: ");
	scanf("%d%*c", &p->idade);
}

// Exibe os dados armazenados em um objeto pessoa
void imprime_pessoa(const pessoa* p) {
	printf("Nome: ");
	printf("%s\n", p->nome);
	
	printf("CPF: ");
	printf("%s\n", p->cpf);
	
	printf("Idade: ");
	printf("%d\n", p->idade);
}

int main(void)
{
   printf("Hello, I'm Stack List!\n\n");
   
   int i;
   stack_t* s;
   pessoa p;
   
   stack_initialize(&s, constructor_pessoa, destructor_pessoa);
   
   // Inserindo algumas pessoas na pilha
   for (i = 0; i < 2; i++){
		printf("Cadastrando pessoa %d\n", i+1);
		cadastra_pessoa(&p);
		stack_push(s, &p);
   }
   
   // Esvaziando a pilha
   while(!stack_empty(s)) {
		printf("\nImprimindo pessoa\n");
		p = *(pessoa*) stack_top(s);
		imprime_pessoa(&p);
		stack_pop(s);
		
		printf("\n");
   }
   
   stack_delete(&s);

    return 0;
}















































