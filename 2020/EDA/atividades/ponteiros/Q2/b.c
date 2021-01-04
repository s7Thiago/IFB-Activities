#include <stdio.h>


void troca(int* i, int * j){
	int tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

int main (void) {
	int a = 5, b = 2;
	int *i, *j;
	i = &a;
	j = &b;
	
	printf("antes: i(%d)  j(%d)\n", *i, *j);
	troca(i, j);
	printf("depois: i(%d)  j(%d)\n", *i, *j);
	
	
	return 0;
}
