#include "bublesort.h"

// Realiza a troca de posições
void swap(int* v, int i, int j){
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}


void printv(int* v, size_t size){
	int i;
	printf("[ ");
	for(i = 0; i < size; i++){
		printf("%d", v[i]);
		
		if(i != size -1)
			printf(", ");
			
		if(i == size - 1)
			printf(" ]\n\n");
	}
}

void bublesort(int* v, size_t size){
	int swapped = 1; // Variável de controle de troca. Começa como true
	int i;
	
	// Indica quantas iterações já foram feitas
	for(i = 0; i < size -1 && swapped; i++){
	swapped = 0; // Define a variável de controle como false
	
	int j;
	
	// Faz a varredura no vetor, comparando os elementos adjacentes
	// efetuando a troca, quando o elemento da esquerda for maior
	// do que o elemento da direita
	for(j = 0; j < size - i - 1; j++){
		if (v[j] > v[j + 1]) {
			swap(v, j, j+1);
			swapped = 1; // Sempre que há uma troca, atualiza a veriável de controle
			}
		}
	}
}

void bublesortl(int* v, size_t size){
	int swapped = 1; // Variável de controle de troca. Começa como true
	int i;
	
	printf("BUBLESORT STARTED\n\n");
	
	// Indica quantas iterações já foram feitas
	for(i = 0; i < size -1 && swapped; i++){
	swapped = 0; // Define a variável de controle como false
	
	int j;
	
	// Faz a varredura no vetor, comparando os elementos adjacentes
	// efetuando a troca, quando o elemento da esquerda for maior
	// do que o elemento da direita
	for(j = 0; j < size - i - 1; j++){
		if (v[j] > v[j + 1]) {
			swap(v, j, j+1);
			swapped = 1; // Sempre que há uma troca, atualiza a veriável de controle
			// Mostra o vetor atualizado
			printv(v, size);
			}
		}
	
	}
	
	printf("BUBLESORT ENDED\n\n");

}




























