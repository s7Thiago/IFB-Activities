#include <stdio.h>
#include <stdlib.h> // Para usar malloc

int main (void) {
	
	int* p = malloc(sizeof(int)*64000000000LL); //tantando alocar 64GB de memoria (RAM)
	
	if (p == NULL) {
		printf("\nImpossível alocar memória\n\n");
	} else {
		printf("\n Tudo ok\n\n");
	}
	
	return 0;
}

