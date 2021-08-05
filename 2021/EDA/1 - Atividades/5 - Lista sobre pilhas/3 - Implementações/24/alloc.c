#include "alloc.h"


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
