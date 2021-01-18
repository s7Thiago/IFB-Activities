#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
	
	int n, j;
	
	srand(time(NULL));
	
	printf("Tamanho do vetor a ser alocado: ");
	scanf("%d", &n);
	
	// Alocando espaço em memória para o vetor,
	// inicialozando toda a região com zeros;
	int* v = calloc(n, sizeof(int));
	
	// Tomando medidas em caso de falha
	if (v == NULL) {
		printf("Erro ao alocar");
		exit(EXIT_FAILURE);
		
	}
	
	// Acessando cada posição da região e 
	// preenchendo com inteiros aleatórios
	for (j = 0; j < n; j++){
		v[j] = rand() % 1000; // Armazena um valor aleatório entre 0 e 999
	}
	
	// Imprimindo um vetor
	for(j = 0; j < n; j++){
		printf("v[%d] = %d\n",j,  v[j]);
	}
	
	free(v);
	
	return 0;
}


