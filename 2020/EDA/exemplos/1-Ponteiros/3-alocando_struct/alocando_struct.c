#include <stdio.h>
#include <stdlib.h>

// A struct
typedef struct MinhaStruct {
	int a, b, c;
} MinhaStruct;

int main (void) {
	// Criando ponteiro para MinhaStruct
	MinhaStruct* ptr;
	
	// Alocando memoria para UMA struct, isso passa para o ponteiro
	// o endereço inicial da struct.
	ptr = malloc(sizeof(MinhaStruct));
	
	// Tomando medidas, caso algo dê errado
	if (ptr == NULL) {
		printf("Erro durante a alocação");
		exit(EXIT_FAILURE);
	}
	
	// Inserindo valores nos membros da struct através do ponteiro
	// Também poderia ser (*ptr).a = 5; etc
	// OBS:
	// é importante usar parênteses -> (*ptr).membro porque o operador ponto (.) 
	// tem uma prioridade maior sobre o operador asterisco (*), por isso
	// se fizermos *ptr.membro, o que ocorre é que será feita primeiro um acesso ao membro,
	// e depois uma referência ao valor do ponteiro (*ptr), mas o que queremos é que
	// seja feita uma referência ao ponteiro (*ptr), e só depois o membro armazenado nessa
	// referência seja acessado; 
	ptr-> a = 5;
	ptr-> b = 3;
	ptr-> c = 9;
	
	// Mostrando os valores dos membros:
	printf("a: %d\n", ptr->a);
	printf("b: %d\n", ptr->b);
	printf("c: %d\n\n", ptr->c);
	
	// Liberando o espaço alocado anteriormente
	free(ptr);
	
	// Mostrando os valores após liberado com free
	printf("Após liberado:\na: %d\n", ptr->a);
	printf("b: %d\n", ptr->b);
	printf("c: %d\n\n", ptr->c);
		
	return 0;
}


