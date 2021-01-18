#include <stdio.h>
#include <stdlib.h>


int main (void) {
	
	int *p; //Criando um ponteiro para o vetor
	int i, qtde_elementos;
		
	// recebendo a quuantidade de elementos
	printf("Qtde de elementos: ");
	scanf("%d", &qtde_elementos);
	
	// Alocando a memoria para o vetor de acordo com a
	// quantidade de elementos nele
	p = (int *)(malloc(qtde_elementos * sizeof(int)));
	
	// Caso não se ja possível alocar memória suficiente,
	// enviar mensagem e sair do programa com exit(1)
	if (p == NULL) {
		printf("Erro na aliocação de memória");
		system("pause");
		exit(1);
	}
	printf("\n\n");
	
	// Se tudo deu certo, vamos receber os elementos para
	// armazenar no vetor
	for (i = 0; i < qtde_elementos; i++){
		printf("digite o elemento %d: ", (i+1));
		scanf("%d", &p[i]);
	}
	
	printf("\nElementos aramazenados\n");
	
	// Percorrendo o vetor para mostrar os elementos armazenados
	for (i = 0; i < qtde_elementos; i++){
		printf("	[%d] - %d\n", i+1, p[i]);
	}
	
	printf("\n\n");
	
	return 0;
}
