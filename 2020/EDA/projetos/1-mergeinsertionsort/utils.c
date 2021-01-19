#include "utils.h"

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

void* mallocx(size_t n){
	void* ptr = malloc(n);
	
	if(ptr == NULL) {
		printf("\nmallocx: Erro ao alocar região\n");
		exit(EXIT_FAILURE);
	}
	return ptr;
}

void* callocx(size_t n, size_t s){
	void* p = calloc(n, s);
	
	if(p == NULL) {
		printf("\ncallocx: Erro ao alocar região\n");
		exit(EXIT_FAILURE);
	}
	return p;
}


void* reallocx(void* ptr ,size_t n){
	void* r = realloc(ptr, n);
	
	if(r == NULL) {
		printf("\nreallocx: Erro ao alocar região\n");
		exit(EXIT_FAILURE);
	}
	return r;
}

int* generateEntry(int range){

	// Alocando espaço para a entrada
	int*v = callocx(range, sizeof(int));
	int j;
	
	for(j = 0; j < range; j++){
		v[j] = rand() % range; // Armazena um valor aleatório
	}
	
	//printv(v, range);
	
	return v;

}



































































