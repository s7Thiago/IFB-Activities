#include <stdio.h>

int main (void) {
	int x, *p;
	x = 100;
	p = &x; // Linha corrigida;
	
	printf("O valor de p: %d.\n", *p);
	
	return 0;
}
