#include "mergesort.h"

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

void mergesort(int* v, size_t n){

}


































