#include <stdio.h>
#include "contador.h"

extern void incrementar_contador();

int main (void) {
	extern int contador;
	int i;
	
	for (i = 0; i < 10; i++){
		incrementar_contador();
		printf("contador = %d\n", contador);
	}
	
	return 0;
}
